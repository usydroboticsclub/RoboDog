This Repo is for our robot dog mascot. We aim to use other repos to make it.

# RoboDog Checklist
https://docs.google.com/document/d/10oTWnJSjZQA49-zwCSayfSq9JB1JXsvcdztj8M00Js8/edit?usp=sharing

# Interesting Sources of information
- [Comparing SG90 to MG90S & MG996R Servo Motors](https://zaitronics.com.au/blogs/guides/comparing-sg90-mg90s-and-mg996r-servos)


# Best Dog Repos
- We printed based off [this](https://github.com/michaelkubina/SpotMicroESP32) repo ESP32 based.
- Online Guide for R-pi with Renforcement learning [here](https://spotmicroai.readthedocs.io/en/latest/gettingStarted/) 
- Best Kinematics Explnation, Interesting Servo and electronics guide for R-pi set up [here](https://github.com/MZandtheRaspberryPi/spot_micro_demo).
- [vertueux](https://github.com/MZandtheRaspberryPi/spot_micro_demo): ROS2 implementation good R-pi setup.
- RL Guides for spot dog using Ri Pi [here](https://spotmicroai.readthedocs.io/en/latest/training/#reinforcement-learning-environment) orignal repo [here](https://github.com/OpenQuadruped/spot_mini_mini#reinforcement-learning-agent-training) drawback is its ROS 1.

## Other Repos
- Blacksheep has good PCB design and kinematics explanation [here](https://github.com/Blacksheep909/SpotMicroESP32-Nitro-Fork/tree/master)
- unsure https://github.com/MZandtheRaspberryPi/spot_micro_demo
- [Mike4192](https://github.com/mike4192/spotMicro/tree/master) : mikes orginal ros 1 implementation

# Standford Dog
https://github.com/Nate711/StanfordDoggoProject 
## Documentation
[here](https://pupper-v3-documentation.readthedocs.io/en/latest/index.html)
## CS123 Course Page
[here](https://cs123-stanford.readthedocs.io/en/latest/#)



# USRC apporach with Dog
1. Ordered
   - x12 MG996R Servos : metal gear version
   - PCA9685 : I2C Servo Driver
   - LM2596 : 5V Stepdown
   - SZBK07 : 300W, 20A DC-DC step-down (buck) converter
   - 625zz : Bearings
2. Printer Legs and chassis 3D parts


# Log Book
## 7th May 2026
<img width="4096" height="3072" alt="IMG20260507151431" src="https://github.com/user-attachments/assets/cdc9132c-4720-4951-bc9c-7188d3193563" />

- Today we worked on extracting the best way to power the Dog. We realised that PCA9685 has a seperate servo (6V+) and circuit logic power via (5V+ Vcc)
- Following Mike's layout, we resolved to power the PCA9685 with the SZBK07 at 6V with maybe a fuse in the middle to protect the PCA and power the Raspberry Pi using the LM2596 at 5V.
- Antonio suggested to power the servos seperately since the PCA9685 internal rails cap out at 12A.
- We note most online implementations do not power the PCA9685 with a SZBK07 and instead directly hook into the battery.
- Please see circuit diagram above for our first iteration circuit design, based on (mikes)[https://github.com/michaelkubina/SpotMicroESP32/tree/master/electronics] circuit design. I note the current and voltage sensors are not necessary to protect ADC pins on the Raspberry pi we are not using.

## 14th May 2026
- The Servo motors finally arrived!
- We spent the day building the robotic dog. Pictures TODO
- We have concerns the RL learning module in our repo won't transfer to RL for the robo dog.

## 19th August 2026 
- After a 3 month hiatus, we finally return to the robo dog.
- Within that time we assembled all the legs and frame of the body with relatively no issues.
- Currently the building progress has been put on hold to properly calibrate the servos, this process as not been so smooth.
- Long story short, after frying two arduinos and hours of going in circles, we have finally settled on a calibration method!
- Although properly calibrating servos is quite the hurdle at the moment, spending this time will allow us:
  - To ensure the robo has the proper range of motion
  - To rule out and/or be aware of hardware issue when writing and debugging code later down the line.
- Details of calibration is available in the 'Calibration' directory, compiled by Jacky.

## 26th August 2026
- This week we continued with calibration of the servos
- After further struggle with Mike's instruction, we have successfully workout the calibration/rest positions of the robodog's limbs
- Parvez developed a calibration method where angle were typed into the serial input, which significantly streamlined the process. (added code to 'Calibration')
- Additionally, Parvez managed to get the PCA9685 running off an arduino nano which allowed for multiple legs to be activated at the same time. (unfortunately a shoulder part went missing which meant the dogs balance was not able to be tested)
- Some loose ends from this session include: the missing shoulder, missing nuts and bolts boxes, have not bolted the shoulder joint servo motor yet.
<img width="4284" height="5712" alt="IMG_7346" src="https://github.com/user-attachments/assets/84cd02c2-afae-4e3a-80e4-ab71e53aad17" />

- Above is the an image of the legs attached to the body, with one leg missing due to the missing shoulder. 
- To the left is a buck converter which connects from the LiPo 7.4V to the PCA9685 V+ and the common ground between the arduino and PCA9685. It's purpose is to drop the 7.4V to 6V (servo's operating range is 4.8-7.2V)
- To the right with the many wires is the PCA9685 which allows the arduino to control all the servos independently with two microcontroller pins. There are 6 input pins: From bottom to top: V+, Vcc, SDA, SCL, OE, GND.
  - V+ -> buck convert 6V +output. This is to power the motors.
  - Vcc -> arduino 5V pin. This is to power the PCA9685 board itself
  - SDA -> arduino A4 pin. Serial Data 
  - SCL -> arduino A5 pin. Serial Clock
  - OE -> none
  - GND -> breadboard common ground.
- The output pins are connected to the motors, where the board provides the common ground, V+ from the buck converter and PWM pins
