# Line follower robot 

This code is designed to control a line-following robot, managing motor outputs and sensor inputs to enable the robot to follow a line, make turns, and stop based on sensor readings.

## Overview of its main components

- **Motor Control Pins:** Defines pins for controlling the right and left motors (e.g., r_enR, l_enR, r_forward, r_backword).

- **Sensor Pins:** Sets pins for various sensors used to detect the line (smrv, srv, scv, slv, smlv).

- **Speed and State Variables:** Specifies speed variables and defines states for the sensors and logic flags (e.g., speed, turn, black, white).

- **Setup Function:** Initializes serial communication, sets pin modes, and runs an initial line-following loop until a condition (pass == 1) is met.

- **Loop Function:** Contains an empty loop, as the main logic is handled in the setup function and other custom functions.

- **Line Following Logic:** The linefollow function reads sensor values and decides the robot's movements (forward, right, left, halt) based on the detected line pattern.

- **Movement Functions:** Defines functions for moving the robot forward, backward, left, right, and stopping (forward, backword, left, right, halt, left90, right90).


> The robot follows the line by continuously reading sensor inputs and adjusting motor outputs to stay on course, make turns, or stop when necessary.
