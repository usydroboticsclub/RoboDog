There are two scripts in this directory, both related to the calibration of MG996R servos in the context of the robodog: 

Script: servo_cal_interval.ino 

- switches to the five neutral positions servos will reside in when installed in the robo - dog's limbs
- must verify the servo angle positions matches the software's command

Script: servo_cal_loop.ino

- performs a full rotation of the servo
- allows for deflects or irregularies in the servos range of motion to be detected/investigated.
