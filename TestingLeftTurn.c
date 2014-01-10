#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ultrasonic,     sensorSONAR)
#pragma config(Sensor, S4,     irsensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,          bucketwrist,   tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftfrontdrive, tmotorTetrix, PIDControl, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     leftbackdrive, tmotorTetrix, PIDControl, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     rightfrontdrive, tmotorTetrix, PIDControl, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     rightbackdrive, tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_1,     liftassembly1, tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C3_2,     liftassembly2, tmotorTetrix, PIDControl)
void TurnLeft()
{
	motor[leftfrontdrive] = -100;
	motor[leftbackdrive] = -100;
	motor[rightfrontdrive] = 100;
	motor[rightbackdrive] = 100;
}

task main()
{
	TurnLeft();
	wait10Msec(1000);
}
