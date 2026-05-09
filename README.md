# EW-final-project
semester final project for engineering workshop lab

The Thermal Guardian is an Arduino-based temperature warning system built on a breadboard.
The circuit uses an LM35 temperature sensor connected to analog pin A0, a piezo buzzer on D8, a red LED on D9, and a green LED on D10, all powered via USB through the Arduino's 5V and GND pins.
The code continuously samples the LM35 50 times per cycle and averages the readings to reduce noise, then compares the result against a low and high threshold. If temperature falls outside the safe range the red LED lights up and the buzzer sounds. Within the safe range the green LED stays on indicating normal conditions.
The main challenge encountered was analog noise from the LM35 causing wild fluctuations of 10–20°C, resolved by increasing the sample size to 50 readings per cycle averaged together.
The final build requires no external power source — the USB Type-B to Type-A cable handles both programming and power supply.
