#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,      ,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,      ,             tmotorTetrix, openLoop)
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          bucketwrist,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftfrontdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftbackdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightfrontdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightbackdrive, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftassembly1, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftassembly2, tmotorTetrix, openLoop)
#include "JoystickDriver.c"
task main()
{
int limit = 5;


while(true){
getJoystickSettings(joystick);
if(abs(joystick.joy1_y1) > limit){
	motor[liftassembly1] = joystick.joy1_y1;
}

else{
	motor[liftassembly1] = 0;
}


if(abs(joystick.joy1_y2) > limit){
	motor[liftassembly2] = joystick.joy1_y2;
}

else{
	motor[liftassembly2] = 0;
}
}
}
