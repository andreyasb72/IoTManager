#include "ESPConfiguration.h"

void* getAPI_Cron(String subtype, String params);
void* getAPI_Loging(String subtype, String params);
void* getAPI_LogingDaily(String subtype, String params);
void* getAPI_IoTMath(String subtype, String params);
void* getAPI_owmWeather(String subtype, String params);
void* getAPI_Timer(String subtype, String params);
void* getAPI_Variable(String subtype, String params);
void* getAPI_VButton(String subtype, String params);
void* getAPI_A02Distance(String subtype, String params);
void* getAPI_Acs712(String subtype, String params);
void* getAPI_AhtXX(String subtype, String params);
void* getAPI_AnalogAdc(String subtype, String params);
void* getAPI_Bme280(String subtype, String params);
void* getAPI_Bmp280(String subtype, String params);
void* getAPI_Dht1122(String subtype, String params);
void* getAPI_Ds18b20(String subtype, String params);
void* getAPI_Impulse(String subtype, String params);
void* getAPI_MQgas(String subtype, String params);
void* getAPI_Pzem004_v2(String subtype, String params);
void* getAPI_RTC(String subtype, String params);
void* getAPI_S8(String subtype, String params);
void* getAPI_Sht20(String subtype, String params);
void* getAPI_Sht30(String subtype, String params);
void* getAPI_Sonar(String subtype, String params);
void* getAPI_UART(String subtype, String params);
void* getAPI_AnalogBtn(String subtype, String params);
void* getAPI_ButtonIn(String subtype, String params);
void* getAPI_ButtonOut(String subtype, String params);
void* getAPI_Buzzer(String subtype, String params);
void* getAPI_Encoder(String subtype, String params);
void* getAPI_IoTServo(String subtype, String params);
void* getAPI_Mcp23017(String subtype, String params);
void* getAPI_Mp3(String subtype, String params);
void* getAPI_Multitouch(String subtype, String params);
void* getAPI_OpenThermMonitor(String subtype, String params);
void* getAPI_Pcf8574(String subtype, String params);
void* getAPI_Pwm32(String subtype, String params);
void* getAPI_TelegramLT(String subtype, String params);
void* getAPI_Thermostat(String subtype, String params);
void* getAPI_DwinI(String subtype, String params);
void* getAPI_Lcd2004(String subtype, String params);
void* getAPI_Oled64(String subtype, String params);
void* getAPI_Smi2_m(String subtype, String params);

void* getAPI(String subtype, String params) {
void* tmpAPI;
if ((tmpAPI = getAPI_Cron(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Loging(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_LogingDaily(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_IoTMath(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_owmWeather(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Timer(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Variable(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_VButton(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_A02Distance(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Acs712(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_AhtXX(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_AnalogAdc(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Bme280(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Bmp280(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Dht1122(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Ds18b20(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Impulse(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_MQgas(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Pzem004_v2(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_RTC(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_S8(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Sht20(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Sht30(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Sonar(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_UART(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_AnalogBtn(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_ButtonIn(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_ButtonOut(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Buzzer(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Encoder(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_IoTServo(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Mcp23017(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Mp3(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Multitouch(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_OpenThermMonitor(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Pcf8574(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Pwm32(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_TelegramLT(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Thermostat(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_DwinI(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Lcd2004(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Oled64(subtype, params)) != nullptr) return tmpAPI;
if ((tmpAPI = getAPI_Smi2_m(subtype, params)) != nullptr) return tmpAPI;
return nullptr;
}