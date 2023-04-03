
#include "Global.h"
#include "classes/IoTItem.h"

#include "PZEMSensor.h"
#include "modules/sensors/UART/Uart.h"

class Pzem004v : public IoTItem {
   private:
    String addr;
    PZEMSensor* pzem;

   public:
    Pzem004v(String parameters) : IoTItem(parameters) {
        addr = jsonReadStr(parameters, "addr");
        if (myUART) {
            pzem = new PZEMSensor(myUART, hexStringToUint8(addr));
            // раскомментируйте эту строку если нужно поменять адрес pzem
            // SerialPrint("i", "Pzem", String(pzem->setAddress(0x03)));
        }
    }

    void doByInterval() {
        if (pzem) {
            bool online = false;
            value.valD = pzem->values(online)->voltage;
            if (online) {
                regEvent(value.valD, "Pzem V");
            } else {
                regEvent(NAN, "Pzem V");
                SerialPrint("E", "Pzem", "V error", _id);
            }
        }
    }

    ~Pzem004v(){};
};

class Pzem004a : public IoTItem {
   private:
    String addr;
    PZEMSensor* pzem;

   public:
    Pzem004a(String parameters) : IoTItem(parameters) {
        addr = jsonReadStr(parameters, "addr");
        if (myUART) {
            pzem = new PZEMSensor(myUART, hexStringToUint8(addr));
        }
    }

    void doByInterval() {
        if (pzem) {
            bool online = false;
            value.valD = pzem->values(online)->current;
            if (online) {
                regEvent(value.valD, "Pzem A");
            } else {
                regEvent(NAN, "Pzem A");
                SerialPrint("E", "Pzem", "A error", _id);
            }
        }
    }

    ~Pzem004a(){};
};

class Pzem004w : public IoTItem {
   private:
    String addr;
    PZEMSensor* pzem;

   public:
    Pzem004w(String parameters) : IoTItem(parameters) {
        addr = jsonReadStr(parameters, "addr");
        if (myUART) {
            pzem = new PZEMSensor(myUART, hexStringToUint8(addr));
        }
    }

    void doByInterval() {
        if (pzem) {
            bool online = false;
            value.valD = pzem->values(online)->power;
            if (online) {
                regEvent(value.valD, "Pzem W");
            } else {
                regEvent(NAN, "Pzem W");
                SerialPrint("E", "Pzem", "W error", _id);
            }
        }
    }

    ~Pzem004w(){};
};

class Pzem004wh : public IoTItem {
   private:
    String addr;
    PZEMSensor* pzem;

   public:
    Pzem004wh(String parameters) : IoTItem(parameters) {
        addr = jsonReadStr(parameters, "addr");
        if (myUART) {
            pzem = new PZEMSensor(myUART, hexStringToUint8(addr));
        }
    }

    void doByInterval() {
        if (pzem) {
            bool online = false;
            value.valD = pzem->values(online)->energy;
            if (online) {
                regEvent(value.valD, "Pzem Wh");
            } else {
                regEvent(NAN, "Pzem Wh");
                SerialPrint("E", "Pzem", "Wh error", _id);
            }
        }
    }

    ~Pzem004wh(){};
};

class Pzem004hz : public IoTItem {
   private:
    String addr;
    PZEMSensor* pzem;

   public:
    Pzem004hz(String parameters) : IoTItem(parameters) {
        addr = jsonReadStr(parameters, "addr");
        if (myUART) {
            pzem = new PZEMSensor(myUART, hexStringToUint8(addr));
        }
    }

    void doByInterval() {
        if (pzem) {
            bool online = false;
            value.valD = pzem->values(online)->freq;
            if (online) {
                regEvent(value.valD, "Pzem Hz");
            } else {
                regEvent(NAN, "Pzem Hz");
                SerialPrint("E", "Pzem", "Hz error", _id);
            }
        }
    }

    ~Pzem004hz(){};
};

class Pzem004pf : public IoTItem {
   private:
    String addr;
    PZEMSensor* pzem;

   public:
    Pzem004pf(String parameters) : IoTItem(parameters) {
        addr = jsonReadStr(parameters, "addr");
        if (myUART) {
            pzem = new PZEMSensor(myUART, hexStringToUint8(addr));
        }
    }

    void doByInterval() {
        if (pzem) {
            bool online = false;
            value.valD = pzem->values(online)->pf;
            if (online) {
                regEvent(value.valD, "Pzem Pf");
            } else {
                regEvent(NAN, "Pzem Pf");
                SerialPrint("E", "Pzem", "Pf error", _id);
            }
        }
    }

    ~Pzem004pf(){};
};

class Pzem004cmd : public IoTItem {
   private:
    String addr;
    int changeaddr;
    String setaddr;
    int reset;
    PZEMSensor* pzem;

   public:
    Pzem004cmd(String parameters) : IoTItem(parameters) {
        jsonRead(parameters, F("addr"), addr);
        jsonRead(parameters, F("changeaddr"), changeaddr);
        jsonRead(parameters, F("setaddr"), setaddr);
        jsonRead(parameters, F("reset"), reset);

        if (myUART) {
            pzem = new PZEMSensor(myUART, hexStringToUint8(addr));
            if (changeaddr == 1) {
                if (pzem->setAddress(hexStringToUint8(setaddr))) {
                    SerialPrint("i", "Pzem", "address set: " + setaddr);
                } else {
                    SerialPrint("i", "Pzem", "set adress error");
                }
            }
            if (reset == 1) {
                if (pzem->reset()) {
                    SerialPrint("i", "Pzem", "reset done");
                } else {
                    SerialPrint("i", "Pzem", "reset error");
                }
            }
        }
    }

    void doByInterval() {
        if (pzem) {
        }
    }

    ~Pzem004cmd(){};
};

void* getAPI_Pzem004(String subtype, String param) {
    if (subtype == F("Pzem004v")) {
        return new Pzem004v(param);
    } else if (subtype == F("Pzem004a")) {
        return new Pzem004a(param);
    } else if (subtype == F("Pzem004w")) {
        return new Pzem004w(param);
    } else if (subtype == F("Pzem004wh")) {
        return new Pzem004wh(param);
    } else if (subtype == F("Pzem004hz")) {
        return new Pzem004hz(param);
    } else if (subtype == F("Pzem004pf")) {
        return new Pzem004pf(param);
    } else if (subtype == F("Pzem004cmd")) {
        return new Pzem004cmd(param);
    } else {
        return nullptr;
    }
}
