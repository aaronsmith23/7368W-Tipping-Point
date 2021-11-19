using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern motor RightFront;
extern motor RightRear;
extern motor ForkRight;
extern motor LiftRight;
extern motor LiftLeft;
extern motor ForkLeft;
extern motor LeftRear;
extern motor LeftFront;
extern digital_out Clamp;
extern inertial Inertial;
extern signature Vision__YG;
extern signature Vision__RG;
extern signature Vision__BG;
extern signature Vision__SIG_4;
extern signature Vision__SIG_5;
extern signature Vision__SIG_6;
extern signature Vision__SIG_7;
extern vision Vision;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );