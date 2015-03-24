#include "PickUpAndSkateAuto.h"
#include "../Lifter/CalibrateLifter.h"
#include "../Lifter/MoveToLevel.h"
#include "../Gripper/Grab.h"
#include "../../CommandBase.h"
#include "../Gripper/Release.h"
#include "../Other/DoNothing.h"
#include "../../RobotMap.h"
#include "../Drive/DriveCommands/Move.h"

PickUpAndSkateAuto::PickUpAndSkateAuto()
{
	AddSequential(new Release());
	AddSequential(new CalibrateLifter());
	AddSequential(new DoNothing(.25));
	AddSequential(new Grab());
	AddSequential(new DoNothing(.25));
	AddSequential(new MoveToLevel(75));
	AddSequential(new DoNothing(.25));
	AddSequential(new Move(270, 1, 3));
	AddSequential(new DoNothing(.25));
	AddSequential(new MoveToLevel(0));
	AddSequential(new DoNothing(.25));
	AddSequential(new Release());
}
