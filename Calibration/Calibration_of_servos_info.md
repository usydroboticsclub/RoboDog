Calibration of the servos:
- The MG699R motor is a hobby motor that does not take bit numbers as PWM (Duty Cycle) values - instead it takes microseconds (according to chatgpt) or it takes the supposedly ‘1 to 1’ servo.write to angle.
- Our guess is that servo.write value theoretically should be 1 to 1 with the actual angle —> BUT because of how servos work with an encoder that accumualtes an epilson that subtely increases the error margin - from 30 vs 30, to 90 vs 98. We have not identified a strong pattern for this, but do know that it should be growing. David suggested the graph make be wavy going upwards OR considered if this was fault due to..
- Another issue that arised is that 90 angle was equal to 90 servo write at the begining but changed to 98 whilst continuing - we had questions on whether this was the servo internals degrading over time? or just an error in our initial measurement (which we swear it’s not)
- The circuitry for calibration is relatively simple: a battery with enough amperage and voltage (20 amps + 6.6 V bc of the buck converter with the voltage reader and potentiometer) - we noted that GND of the battery HAD to be connected to the GND of the arduino to make it one whole circuit and so that the PWM had a reference (since it goes neg apparently from what david said)
- From a google search - we did not try this but Microsecond Value (Above 180): If you give it a number larger than (180) (for example, 2000), the library treats it directly as a pulse length in microseconds
   - 1ms pulse: Places the servo at the 0° position.
   - 1.5ms pulse: Places the servo at the center (90° position).
   - 2ms pulse: Places the servo at the 180° position.
