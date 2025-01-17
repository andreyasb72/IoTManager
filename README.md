# IoTManager
:white_check_mark: [Видеоинструкция](https://youtu.be/feauIN7FCbY)    


#### Команды:  

:ballot_box_with_check: IoTManagerProject/IoTManager/ `Main.cpp`    
```yaml
//  stInit();
```


:ballot_box_with_check: Actions `c-cpp.yml`    
```yaml
name: Build Firmware

on:
  workflow_dispatch:
       
  
jobs:
  build:

    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v2
      with:
        ref: 'ver4dev'
    - name: Run PrepareProject.py
      run: python3 ./PrepareProject.py
    - name: Set up Python
      uses: actions/setup-python@v4
    - name: Install dependencies
      run: |
        python -m pip install --upgrade pip
        pip install platformio
    - name: Run PlatformIO
      run: platformio run 
    - name: Build FS
      run: platformio run -t buildfs --disable-auto-clean
    - name: Attach artifact
      uses: actions/upload-artifact@v4
      with:
        name: firmware
        path: |
          .pio/build/esp8266_4mb/firmware.bin
          .pio/build/esp8266_4mb/littlefs.bin
          .pio/build/esp8266_1mb/firmware.bin
          .pio/build/esp8266_1mb/littlefs.bin
          .pio/build/esp8266_1mb_ota/firmware.bin
          .pio/build/esp8266_1mb_ota/littlefs.bin
          .pio/build/esp8285_1mb/firmware.bin
          .pio/build/esp8285_1mb/littlefs.bin
          .pio/build/esp8285_1mb_ota/firmware.bin
          .pio/build/esp8285_1mb_ota/littlefs.bin
          .pio/build/esp32_4mb/firmware.bin
          .pio/build/esp32_4mb/littlefs.bin
          .pio/build/esp32_4mb/partitions.bin  
          .pio/build/esp32_4mb3f/firmware.bin
          .pio/build/esp32_4mb3f/littlefs.bin
          .pio/build/esp32_4mb3f/partitions.bin
          .pio/build/esp32cam_4mb/firmware.bin
          .pio/build/esp32cam_4mb/littlefs.bin
          .pio/build/esp32cam_4mb/partitions.bin
          .pio/build/esp32s2_4mb/firmware.bin
          .pio/build/esp32s2_4mb/littlefs.bin
          .pio/build/esp32s2_4mb/partitions.bin
          .pio/build/esp32s3_16mb/firmware.bin
          .pio/build/esp32s3_16mb/littlefs.bin
          .pio/build/esp32s3_16mb/partitions.bin
          .pio/build/esp32c3m_4mb/firmware.bin
          .pio/build/esp32c3m_4mb/littlefs.bin
          .pio/build/esp32c3m_4mb/partitions.bin
```


:ballot_box_with_check: Онлайн флешер  `https://espressif.github.io/esptool-js/`    
