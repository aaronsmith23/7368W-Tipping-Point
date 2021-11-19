#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor RightFront = motor(PORT11, ratio6_1, false);
motor RightRear = motor(PORT1, ratio6_1, false);
motor ForkRight = motor(PORT4, ratio18_1, false);
motor LiftRight = motor(PORT5, ratio36_1, false);
motor LiftLeft = motor(PORT7, ratio36_1, true);
motor ForkLeft = motor(PORT8, ratio18_1, true);
motor LeftRear = motor(PORT10, ratio6_1, true);
motor LeftFront = motor(PORT20, ratio6_1, true);
digital_out Clamp = digital_out(Brain.ThreeWirePort.A);
inertial Inertial = inertial(PORT21);
/*vex-vision-config:begin*/
signature Vision__YG = signature (1, 2169, 2535, 2352, -3647, -3339, -3493, 7, 0);
signature Vision__RG = signature (2, 4321, 10145, 7233, -897, -413, -655, 2.5, 0);
signature Vision__BG = signature (3, -3287, -2799, -3043, 11229, 14175, 12702, 2.5, 0);
vision Vision = vision (PORT3, 50, Vision__YG, Vision__RG, Vision__BG);
/*vex-vision-config:end*/

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}