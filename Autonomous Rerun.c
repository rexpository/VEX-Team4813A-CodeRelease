#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  frontRightE,    sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  armLeftE,    sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           arm,           tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393TurboSpeed_MC29, openLoop, driveLeft, encoderPort, dgtl1)
#pragma config(Motor,  port3,           backLeft,      tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           backRight,     tmotorVex393TurboSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port6,           armLeft,       tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           armRight,      tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           ShootmotorLeft, tmotorVex393TurboSpeed_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port9,           ShootmotorRight, tmotorVex393TurboSpeed_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

#define spinJoy Ch1
#define crabJoy Ch4
#define fwdJoy Ch3

task main()
{
	const int maxPower = 127; //max power of vex motor
	float powerPercent = 1; //var to set power to the bot
	float power = 0; //power to write to motors

	//variables for the program
	int armMotor;
	int crabVal;
	int spinVal;
	int forwardVal;

	bool fwd = false;
	bool bwd = false;

	char encoderVal[15];
	char powerVal[15];

	bool fwdJoyTog = false;

	bool spinJoyTog = false;
	bool leftSpin = false;
	bool rightSpin = false;

	bool crabJoyTog = false;
	bool crabLeft = false;
	bool crabRight = false;

	bool armTog = false;
	bool upArm = false;
	bool downArm = false;

	bool intakeTog = false;
	bool intakeIn = false;
	bool intakeOut = false;
	bool intakeOff = false;
	bool intakePrintTog = false;

	bool fwdNotCrab = true;

	int intakeVal;

	clearDebugStream();

	while (true)
	{

		motor[ShootmotorLeft] = 127;
		motor[ShootmotorRight] = 127;


		if (vexRT[Btn7UXmtr2] == 1)
		{
			powerPercent = 0.1; //10%
		}
		if (vexRT[Btn7LXmtr2] == 1)
		{
			powerPercent = 0.2; //20%
		}
		if (vexRT[Btn7DXmtr2] == 1)
		{
			powerPercent = 0.3; //30%
		}
		if (vexRT[Btn7RXmtr2] == 1)
		{
			powerPercent = 0.4; //40%
		}
		if (vexRT[Btn8UXmtr2] == 1)
		{
			powerPercent = 0.5; //50%
		}
		if (vexRT[Btn8LXmtr2] == 1)
		{
			powerPercent = 0.6; //60%
		}
		if (vexRT[Btn8DXmtr2] == 1)
		{
			powerPercent = 0.7; //70%
		}
		if (vexRT[Btn8RXmtr2] == 1)
		{
			powerPercent = 0.8; //80%
		}
		if (vexRT[Btn5UXmtr2] == 1)
		{
			powerPercent = 0.9; //90%
		}
		if (vexRT[Btn6UXmtr2] == 1)
		{
			powerPercent = 1.0; //Default:100%
		}

		power = powerPercent*maxPower;

		if (vexRT[Btn7U] == 1)
		{
			clearDebugStream();
		}


		if (vexRT[Btn8U] == 1)
		{
			fwdNotCrab = true;
		}


		if (vexRT[Btn8R] == 1)
		{
			fwdNotCrab = false;
		}


		if (fwdNotCrab == true){
		if (vexRT[fwdJoy] >= 10)//Adds a thershhold of +10 to set values
		{

			fwdJoyTog = true;
			fwd = true;


			forwardVal = power-40; //sets + joy values to varibles
		}

		else if (vexRT[fwdJoy] <= -10)//Adds a thershhold of -10 to set va lues
		{
			fwdJoyTog = true;
			bwd = true;
			forwardVal = -power; //sets - joy values to varibles
		}

		else
		{
			if (fwdJoyTog == false)//if there is no input to the fwdJoy,
			{
			if (crabJoyTog == false)//if there is no input to the crabJoy,
			{
				if(spinJoyTog == false)//if there is no input to the spinJoy,
				{
					SensorValue[frontRightE] = 0;

				}}
			}else{


					if (fwd == true)
					{

						sprintf(encoderVal, "%d", abs(SensorValue[frontRightE]));
						sprintf(powerVal, "%d", power);

						writeDebugStream("forwardFour(");
						writeDebugStream(powerVal);
						writeDebugStream(",");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");

						fwd = false;
						fwdJoyTog = false;
					}else{

						sprintf(encoderVal, "%d", abs(SensorValue[frontRightE]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("backwardFour(");
						writeDebugStream(powerVal);
						writeDebugStream(",");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						bwd = false;
						fwdJoyTog = false;
				}
			}

			forwardVal = 0;
		}
	}


		if(fwdNotCrab == false){

		if (vexRT[crabJoy] >= 10 )//Adds a thershhold of +10 to set values
		{
			crabJoyTog = true;
			crabRight = true;
			crabVal = power; //sets + joy values to varibles
		}
		else if (vexRT[crabJoy] <= -10 )//Adds a thershhold of -10 to set values
		{
			crabJoyTog = true;
			crabLeft = true;
			crabVal = -power; //sets - joy values to varibles
		}
		else
		{

			if (crabJoyTog == false)
			{
				if(spinJoyTog == false)
				{
					SensorValue[frontRightE] = 0;
				}
			}else{
					if (crabRight == true)
					{
						sprintf(encoderVal, "%d", abs(SensorValue[frontRightE]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("crabRight(");
						writeDebugStream(powerVal);
						writeDebugStream(",");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						crabRight = false;
						crabJoyTog = false;
					}else {
						sprintf(encoderVal, "%d", abs(SensorValue[frontRightE]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("crabLeft(");
						writeDebugStream(powerVal);
						writeDebugStream(",");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						crabLeft = false;
						crabJoyTog = false;

				}
			}
			crabVal = 0;
		}
	}

		//Setting variables for Spin
		if (vexRT[spinJoy] >= 10)
		{
			spinJoyTog = true;
			rightSpin = true;
			spinVal = power; //sets + joy values to varibles
		}
		else if(vexRT[spinJoy] <= -10)
		{
			spinJoyTog = true;
			leftSpin = true;
			spinVal = -power;
		}
		else
		{
			if (spinJoyTog == false)
			{
			if (crabJoyTog == false)

			{
				if(fwdJoyTog == false)
				{
					SensorValue[frontRightE] = 0;
				}}
			}else{
					if (rightSpin == true)// meaning the bot went right
					{
						//writing code including the functions in the debug stream
						sprintf(encoderVal, "%d", abs(SensorValue[frontRightE]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("rightSpin(");
						writeDebugStream(powerVal);
						writeDebugStream(",");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						rightSpin = false;
						spinJoyTog = false;
					}else{
						sprintf(encoderVal, "%d", abs(SensorValue[frontRightE]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("leftSpin(");
						writeDebugStream(powerVal);
						writeDebugStream(",");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						leftSpin = false;
						spinJoyTog = false;
				}
			}
			spinVal = 0;
		}


		//Setting variables for arms up
		if (vexRT[Btn6U]== 1 && vexRT[Btn6D]== 0 )//Checks for single button press
		{
			armTog = true;
			upArm = true;
			armMotor = power;
		}
		//Arms Down
		else if (vexRT[Btn6U]== 0 && vexRT[Btn6D]== 1  )
		{//Checks for single button pres
			armMotor = -power;
		}
		else
		{
			if(armTog == false)
			{

			}else{
				if(upArm == true)
				{
						sprintf(encoderVal, "%d", abs(SensorValue[armLeftE]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("armUp(");
						writeDebugStream(powerVal);
						writeDebugStream(",");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						upArm = false;
						armTog = false;
					}else{
						sprintf(encoderVal, "%d", abs(SensorValue[armLeftE]));
						sprintf(powerVal, "%d", power);
						writeDebugStream("armDown(");
						writeDebugStream(powerVal);
						writeDebugStream(",");
						writeDebugStream(encoderVal);
						writeDebugStreamLine(");");
						downArm = false;
						armTog = false;
				}
			}
			armMotor = 0;
		}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		if (vexRT[Btn5U]== 1 && vexRT[Btn5D]== 0 )//Checks for single button press
		{
			intakeTog = true;
			intakeIn = true;
			intakeVal = 127;
			if(intakePrintTog == false)
			{
				sprintf(powerVal, "%d", power);
				writeDebugStream("motor[intake]= ");
				writeDebugStream(powerVal);
				writeDebugStreamLine(";");
				intakePrintTog = true;
			}
		}
		else if (vexRT[Btn5U]== 0 && vexRT[Btn5D]== 1  )//Checks for single button press
		{
			intakeTog = true;
			intakeOut = true;
			intakeVal = -127;
			if(intakePrintTog == false)
			{
				sprintf(powerVal, "%d", power);
				writeDebugStream("motor[intake]= -");
				writeDebugStream(powerVal);
				writeDebugStreamLine(";");
				intakePrintTog = true;
			}
		}else{

			if(intakeTog == false)
			{
				if(intakeOff == true)
				{
					writeDebugStreamLine("motor[intake]= 0;");
					intakeOff = false;
				}
			}else{
				if(intakeIn == true)
				{
						intakeIn = false;
						intakeTog = false;
						intakeOff = true;
						intakePrintTog = false;

					}else{
						intakeOut = false;
						intakeTog = false;
						intakeOff = true;
						intakePrintTog = false;
				}
			}
			intakeVal = 0;
		}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		motor[frontRight] = forwardVal - spinVal - crabVal;
		motor[backRight] = forwardVal - spinVal + crabVal;
		motor[frontLeft] = forwardVal + spinVal + crabVal;
		motor[backLeft] = forwardVal + spinVal - crabVal;
		motor[armRight] = armMotor + 20 ;
		motor[armLeft] = armMotor + 20;


}

}
