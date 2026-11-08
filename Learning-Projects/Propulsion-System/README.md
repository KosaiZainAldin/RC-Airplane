# Propulsion System

## Overview

This project uses an Arduino controlled joystick to regulate the speed of a DC motor through a MOSFET. The system converts the joystick's position into a PWM signal, allowing the motor speed to be adjusted based on the throttle input.

The setup consists of a joystick, Arduino, MOSFET, DC motor, and a 6V battery pack.

[Watch the Propulsion System Demo](https://youtu.be/a25_9ffpNOA?is=ntEtEuXvMdTw3XWh)

## Hardware Setup

The system uses the following components:

- **Arduino:** Reads the joystick input and generates the PWM control signal.
- **Joystick:** Acts as the throttle control. It is powered by the Arduino, and its signal output is connected to analog pin A1.
- **MOSFET:** Receives the PWM signal from Arduino pin 3 and controls the power supplied to the motor.
- **Battery pack:** Four 1.5V batteries connected in series, providing a nominal voltage of 6V.
- **DC motor:** Receives power through the MOSFET, with its speed controlled by the PWM signal.

### Wiring and Signal Flow

1. The joystick receives power from the Arduino.
2. The joystick sends an analog signal to pin A1.
3. The Arduino reads the signal and processes it using the programmed throttle logic.
4. The Arduino sends a PWM signal through pin 3 to the MOSFET.
5. The MOSFET controls the power delivered from the battery pack to the DC motor.

## How the Code Works

The Arduino reads the joystick's analog signal using `analogRead(A1)`. The analog input ranges from 0 to 1023, with 512 representing approximately the midpoint of the range.

The code uses this input to determine the PWM output sent to the MOSFET through pin 3.

### Throttle Control Logic

| Joystick Input | PWM Output | Behavior |
|---|---:|---|
| 0 to 512 | 0 | Motor remains off |
| 513 to 1022 | 104.5 to approximately 254 | Motor speed gradually increases |
| 1023 | 255 | Maximum PWM output |

### PWM Calibration

The throttle values were selected through testing to achieve more predictable motor control.

- **512:** The approximate midpoint of the joystick's analog input range. The motor remains off at or below this value.
- **104.5:** The minimum PWM value found to make the DC motor start rotating.
- **3.41:** The scaling factor used to gradually increase the PWM output as the joystick input increases.
- **255:** The maximum PWM value, corresponding to full output.

The scaling calculation is:

`adjuster = (input - 512) / 3.41`

The calculated adjustment is added to the minimum starting PWM value of 104.5.

This allows the motor to begin rotating once the joystick passes the midpoint, then gradually increase its speed as the throttle input increases.

## Challenges and Lessons Learned

One of the main challenges was determining the minimum PWM value required to start the DC motor. The motor would not rotate at lower PWM values, so testing was necessary to find a suitable starting point.

This helped demonstrate how theoretical control signals can behave differently when applied to actual hardware, and why calibration is important when working with motors and electronic components.

## Code

The Arduino code is available in [`code.ino`](code.ino).
