#include "CommandBase.h"
#include "Subsystems/DriveTrain.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL
DriveTrain* CommandBase::drivetrain = NULL;
Gripper* CommandBase::gripper = NULL;
Lifter* CommandBase::lifter = NULL;
RangeFinder* CommandBase::rangefinder = NULL;
OI* CommandBase::oi = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivetrain = new DriveTrain();
	SmartDashboard::PutData(drivetrain); // i saw 190 doing this, looks neat
	gripper = new Gripper(); // Grab, Release Forks
	lifter = new Lifter(); // Raise, lower, tilt forks
	rangefinder = new RangeFinder(); // find distances!
	oi = new OI();
}
