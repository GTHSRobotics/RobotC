#pragma config(Sensor, S3,     ultrasonic,     sensorSONAR)
#pragma config(Sensor, S4,     irsensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S3,     ultrasonic,     sensorSONAR)
#pragma config(Sensor, S4,     irsensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          bucketwrist,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftfrontdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftbackdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightfrontdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightbackdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftassembly1, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftassembly2, tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

  waitForStart();   // wait for start of tele-op phase
int limit = 5;
  while (true)
  {




	getJoystickSettings(joystick);
		if(abs(joystick.joy1_y1) > limit){
		motor[leftfrontdrive] = -joystick.joy1_y1;
		motor[leftbackdrive] = -joystick.joy1_y1;
	}

	if(abs(joystick.joy1_y2) > limit){
		motor[rightfrontdrive] = -joystick.joy1_y2;
		motor[rightbackdrive] = joystick.joy1_y2;
	}

	if(abs(joystick.joy1_y1) < limit && abs(joystick.joy1_y2) < limit){

	motor[leftfrontdrive] = 0;
	motor[leftbackdrive] = 0;
	motor[rightfrontdrive] = 0;
	motor[rightbackdrive] = 0;
}

	if(abs(joystick.joy2_y1) > limit){
		motor[liftassembly1] = joystick.joy2_y1;
	}
	else{
		motor[liftassembly1] = 0;
	}
	if(abs(joystick.joy2_y2) > limit){
motor[bucketwrist] = joystick.joy2_y2;
}
else{
	motor[bucketwrist] = 0;
}
if(joy2Btn(4) == 1){
	motor[liftassembly2] = 100;
}
if(joy2Btn(2) == 1){
	motor[liftassembly2] = -100;
}
if(joy2Btn(2) == 0 && joy2Btn(4) == 0){
	motor[liftassembly2] = 0;

	nxtDisplayCenteredTextLine(3, "Sonar: %d", SensorValue[ultrasonic]);    // Display "Sensor Value: ##"
  wait1Msec(100);    // Wait 100 milliseconds to help display correctly.



}

  }
}