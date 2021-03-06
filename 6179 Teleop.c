#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          bucketwrist,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftfrontdrive, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     leftbackdrive, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     rightfrontdrive, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     rightbackdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftassembly1, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftassembly2, tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
task main(){
int limit = 5;
  while (true)
  {




	getJoystickSettings(joystick);

	if(abs(joystick.joy1_y1) > limit){
		motor[leftfrontdrive] = joystick.joy1_y1; //Left Drive Train
		motor[leftbackdrive] = joystick.joy1_y1;
	}

	if(abs(joystick.joy1_y2) > limit){           //Right Drive Train
		motor[rightfrontdrive] = joystick.joy1_y2;
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




}

  }
}
