# Automatic Braking System using LPC2148

Embedded C project for an ultrasonic-sensor-based automatic braking prototype using an LPC2148 microcontroller.

## Hardware
- LPC2148 microcontroller (12 MHz oscillator)
- HC-SR04-compatible ultrasonic sensor
- L293D motor driver and DC motors
- Character LCD
- Power supply and wiring

## Pin connections
| LPC2148 pin | Connected component |
|---|---|
| P0.9 | Ultrasonic echo |
| P0.11 | Ultrasonic trigger |
| P0.10 | LCD RS |
| P0.12 | LCD RW |
| P0.13 | LCD Enable |
| P0.16–P0.23 | LCD data D0–D7 |
| P1.16 / P1.17 | Motor-driver enable pins (main variant) |

## Source files
- `Main.c`: main distance-monitoring and braking logic
- `Main_with_IN_pins.C`: alternative motor-driver input-pin variant
- `LCD.h`: LCD initialization and display helpers
- `ULTRASONIC.h`: ultrasonic trigger and range measurement
- `TIMER.h`: timer delay routines
- `PWM.h`: PWM configuration example
- `MOTOR.h`: motor initialization stub

## Build and simulation
The project files were originally prepared for Keil uVision and Proteus. Open the supplied project files in those tools and check device, clock, and pin configuration before building or simulating.

**Note:** This is an educational prototype, not a safety-certified automotive braking system. Test only in a controlled environment; do not use it in a real vehicle without proper engineering validation.
