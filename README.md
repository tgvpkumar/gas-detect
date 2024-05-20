# gas-detect

### Abstract

This project involves the development of a gas detection system using an Arduino Uno, an MQ5 gas sensor, a GSM 900A module, LEDs, and a buzzer. The primary objective is to detect the presence of gas and alert the user via SMS and visual/auditory signals. The system continuously monitors gas levels, compares the readings against a predefined threshold, and triggers alerts if the threshold is exceeded.

**Components Used**

1. Arduino Uno: The microcontroller board that serves as the central unit for processing and controlling the system.
2. MQ5 Gas Sensor: A sensor that detects the presence of gases like methane and LPG, providing an analog output proportional to the gas concentration.
3. GSM 900A Module: A GSM module used to send SMS alerts to a predefined phone number when gas is detected.
4. Red LED: Indicates the system's status.
5. Green LED: Indicates the gas detection status.
6. Buzzer: Provides an audible alert when gas is detected.

### Working

1. **Setup**: 
    - The Arduino initializes communication with the GSM module and sets the initial states of the LEDs and the buzzer.
    - The `sendmessage` function sends an initial SMS to notify that the system is powered on and operational without detecting any gas.

2. **Gas Detection**: 
    - The `gasdetect` function reads the analog value from the MQ5 gas sensor. This value represents the gas concentration.
    - If the gas concentration exceeds the predefined threshold (400 in this case), the system considers it a gas leak.

3. **Alert Mechanism:**
    - When gas is detected:
        - The green LED turns on.
        - The buzzer sounds an alarm.
        - The `message` function sends an SMS alert indicating the detection of gas.
    - When no gas is detected:
        - The green LED and the buzzer are turned off.

4. **Loop Execution**:
    - The loop continuously monitors the gas sensor.
    - Depending on the gas sensor readings, it updates the LED and buzzer status and sends an SMS alert if necessary.

This system provides a reliable way to detect gas leaks and promptly alert users, enhancing safety in environments prone to gas leaks.
