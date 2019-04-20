#pragma platform(VEX)
#pragma systemFile

/* List of Methods:
*
* motorsOff(); Used to turn off all motors
* forwardFour(pwr, degs); used to move the bot forward
* backwardFour(""); moves the bot backwards
* rightSpin(""); spins bot to the right
* leftSpin(""); spins bot to the left
* crabRight(""); spins center wheel to the right
* crabLeft(""); spins center wheel to the left
* armDown(""); lowers arms
* armUp(""); raises arms
* armDownLimit(pwr); lowers arms to the extreme
* armUpLimit("); raises arms to the extreme
*z
*/


//Method to stop motors
void motorsOff()
{
	motor[frontRight] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	motor[armLeft] = 20;
	motor[armRight] = 20;
	//motor[intake] = 0;
}


//Method to go forward
void forwardFour(int pwr, int degs)
{
	SensorValue[frontRightE] = 0;
	while (abs(SensorValue[frontRightE]) <= degs)//This is were you may need to swich the < to a > and possibly the degs to -degs if it doesnt work.
	{
		motor[frontRight] = pwr;
		motor[frontLeft] = pwr;
		motor[backRight] = pwr;
		motor[backLeft] = pwr;
	}
	motorsOff();
}

//Method to go backwards
void backwardFour(int pwr, int degs)
{
	SensorValue[frontRightE] = 0;
	while (abs(SensorValue[frontRightE]) <= degs)
	{
		motor[frontRight] = -pwr;
		motor[frontLeft] = -pwr;
		motor[backRight] = -pwr;
		motor[backLeft] = -pwr;
	}
	motorsOff();
}

//Method to spin to the right
void rightSpin(int pwr, int degs)
{
	SensorValue[frontRightE] = 0;
	while (SensorValue[frontRightE] >= -degs)
	{
		motor[frontRight] = -pwr;
		motor[frontLeft] = pwr;
		motor[backRight] = -pwr;
		motor[backLeft] = pwr;

	}
	motor[frontRight] = 10;
	motor[frontLeft] = -10;
	motor[backRight] = 10;
	motor[backLeft] = -10;
}

//Method to spin to the left
void leftSpin(int pwr, int degs)
{
	SensorValue[frontRightE] = 0;
	while (SensorValue[frontRightE] <= degs)
	{
		motor[frontRight] = pwr;
		motor[frontLeft] = -pwr;
		motor[backRight] = pwr;
		motor[backLeft] = -pwr;
	}
	motor[frontRight] = -10;
	motor[frontLeft] = 10;
	motor[backRight] = -10;
	motor[backLeft] = 10;
}

//Method to CrabWalk to the Right
void crabRight(int pwr, int degs)
{
	SensorValue[frontRightE] = 0;
	while (abs(SensorValue[frontRightE]) <= degs)
	{
		motor[frontRight] = -pwr;
		motor[frontLeft] = pwr;
		motor[backRight] = pwr;
		motor[backLeft] = -pwr;

	}
	motorsOff();
}

//Method to CrabWalk to the Left
void crabLeft(int pwr, int degs)
{
	SensorValue[frontRightE] = 0;
	while (abs(SensorValue[frontRightE]) <= degs)
	{
		motor[frontRight] = pwr;
		motor[frontLeft] = -pwr;
		motor[backRight] = -pwr;
		motor[backLeft] = pwr;
	}
	motorsOff();
}

void bottomintake(int time, int pwr)
{
	motor[armLeft] = -pwr;
	wait1Msec(time);
	motor[armLeft] = 0;
}
void bottomoutake(int time, int pwr)
{
	motor[armLeft] = pwr;
	wait1Msec(time);
	motor[armLeft] = 0;
}
void topintake(int time, int pwr)
{
	motor[armRight] = pwr;
	wait1Msec(time);
	motor[armRight] = 0;
}
void topoutake(int time, int pwr)
{
	motor[armRight] = -pwr;
	wait1Msec(time);
	motor[armRight] = 0;
}
void intakeout(int time, int pwr)
{
	motor[armLeft] = -pwr;
	motor[armRight] = -pwr;
	wait1Msec(time);
	motor[armLeft] = 0;
	motor[armRight] = 0;
}
void flywheelup (int time)
{
	motor[ShootmotorLeft] = 127;
	motor[ShootmotorRight] = 127;
	motor[ShootmotorTop] = 127;
	wait1Msec(time);
}
void outakeforever (int time, int pwr)
{
	motor[armLeft] = pwr;
	wait1Msec(time);
	motor[armLeft] = 0;
}

////Method to lower Arms
//void armDown(int pwr, int degs)
//{
//	SensorValue[armLeftE] = 0;
//	while (SensorValue[armLeftE] <= degs)
//	{
//		motor[armLeft] = pwr;
//		motor[armRight] = pwr;
//	}
//	motorsOff();
//}

////Method to raise Arms
//void armUp(int pwr)
//{
//	SensorValue[armLeftE] = 0;
//	while (true)
//	{
//		motor[armLeft] = -pwr;
//		motor[armRight] = -pwr;
//	}
//	motorsOff();
//}
