The following position were calibration were written with reference to Mikes Robodog Github.

# Conventions

To prevent confusion, lets establish a common nomenclature to simply the explanations:

**Anatomy Convention:**


Image below is a photo of our robodog

<img width="746" height="520" alt="image" src="https://github.com/user-attachments/assets/c3ffd8d9-d253-4885-8158-6b6f5a29817b" />


- From the ground going up:
  - **Knee Pitch (KP)**: The joint from the black lower leg to the red upper leg.
  - **Hip Pitch (HP)**: Joint from red upper leg to black shoulder.
  - **Hip Roll (HR)**: Joint from black shoulder to black body.

<img width="850" height="565" alt="image" src="https://github.com/user-attachments/assets/ca9417ea-5076-4e6c-a012-56f7a0b7f29a" />

Posture stabilizing control of quadruped robot based on cart-inverted pendulum model by Kyu-Chur Han and Jung-Yup Kim (2023)

**Position Conventions:**

- Zero Position: The position of the servo when 0 degree input by a microcontroller

- Max Position: The maximum position the servo will go to, usually when 180 degrees is input by a microcontroller. (Note the physical angle was generally found to be around 170 degrees)

- Neutral Position: The position the servo will be in when the robo dog is standing.


# Position Calibration:

Combination of the following two statements have caused us significant confusion in up to this point in the process of position calibration:

1. The left and right legs are mirrored images of another.
2. Servos have a fixed positive direction when sweeping from the zero to max position.

- Consider a clock, if you are were facing the clock the number would increase in a clockwise direction (obviously), however place the clock in front of a mirror, suddenly the 3 and 9 switch position and the number increase in a counter-clockwise direction.
<img width="795" height="463" alt="image" src="https://github.com/user-attachments/assets/59835c0a-7186-4279-a41d-cb6baf71fd4e" />

- Now image the clock hand can only move between 12 and 6, if we set our neutral position to 6 when the clock is facing up we can move 180 degrees counter-clockwise to 12. However when we flip the clock backside up, leaving the neutral position to 6, we won't be able to move any more counter-clockwise. (it would be clockwise to 12 now).
<img width="826" height="476" alt="image" src="https://github.com/user-attachments/assets/dfd52f63-3c3c-481a-9e83-cb2d85ede2fd" />

Thus for the hip pitch and knee pitch, we need to set the zero positions on opposite sides of another:
  
**Knee Pitch:**
  - For this joint we set the zero/max position first then rotate to the neutral position. This is to ensure the upper and lower legs are flush when the robodog is in the sitting position.
  - As shown on the diagram, on the left, we set the servo to its zero position then insert the servo horn. On the right we set the servo to its max position then insert the servo horn.
     <img width="853" height="735" alt="image" src="https://github.com/user-attachments/assets/126f4ac1-2a9f-46c0-854f-213b5809c2b9" />
     
     (Image was modified from Mike's Github)
  - The arrows on the diagram above represent the direction of the range of motion. On the left, the servo is able to rotate clockwise by theta where theta is the an inputted angle between 0 and 180. For the right, the servo is able to rotate counter-clockwise an angle of theta by inputing 180 minus theta. Thus we have a system of moving an angle of theta despite the transformation between left and right legs, as well as preserving the range of motion of the servos. (Note: When a servo is fixed, the servo shaft spins counterclockwise from 0 to 180. However, in this build the servo shaft is fixed instead causing the servo itself to rotate clockwise)  
  - The desired **neutral position** for the ** knee pitch** of both legs is **90 degrees**, which is achieved by simply inputting an angle of 90. (left: 0+90 = 90, right: 180-90 = 90)
  
**Hip Pitch**
   - For this joint, we first set the neutral positions first instead.
   - On the left, we set the servo to 60 degrees then attach it to the shoulder joint. On the right, we set the servo to 120 degrees before attaching it to the shoulder joint. (note an input of 130 may be required for an physical angle of 120 - please make note of these issues when during calibration)
     <img width="853" height="556" alt="image" src="https://github.com/user-attachments/assets/c2396d53-bda7-4b87-baaa-22f71161b82e" />
     
     (Image was modified from Mike's Github)
   - Similar to the knee pitch the left servo spins clockwise by an angle of theta, when 60 plus theta is inputed and the right servo spins counterclockwise by an angle of theta, when 120 minis theta is inputed.
   - As previous implied the **neutral position** of the **left leg is 60 degrees** and the neutral position of the **right leg is 120 degrees**.

**Hip Roll**    
   - For this joint, we set a **neutral position** of **90 degrees** for all the shoulder and insert it into the body.
   - With this joint, as well as having the left and right shoulder being mirrored, the front and back shoulder are also mirrored.
    <img width="893" height="379" alt="image" src="https://github.com/user-attachments/assets/c0f91048-b982-4e4e-b251-581bca1552fb" />
    
   (Image was modified from Mike's Github. The FL - front left, FR - front right, BL - back left, BR - back right)
   - This results in a interesting phenomena where the front left and back front both move theta clockwise when 90 plus theta is inputed. The same is expected with the front right and back left, which would move an angle of theta counterclockwise when 90 minus theta is inputted.
    







