#ifndef LifterPID_H
#define LifterPID_H

#include <WPILib.h>
#include <Commands/PIDSubsystem.h>
#include <SmartDashboard/SmartDashboard.h>
#include <LiveWindow/LiveWindow.h>

#include "../RobotMap.h"
#include "../DataLogger.h"

#define DOWN 1 // FWD (Positive value)
#define UP -1 // REV (Negative value)

class LifterPID: public PIDSubsystem
{
private:
//	DigitalInput* upperLimit;
//	DigitalInput* lowerLimit;
public:
	LifterPID(DataLogger*);
	Encoder* lifterEncoder;
	double ReturnPIDInput();
	void UsePIDOutput(double);
	void InitDefaultCommand();
	void UpdateSetpoint(int);
	void Reset(void);
	void BottomLimitCheck();
	static const int level1;
	static const int level2;
	static const int level3;
	static const int target;
//	Victor* lifterMotor;
	CANTalon* lifterMotor;
	DataLogger *l=NULL;
};

#endif
