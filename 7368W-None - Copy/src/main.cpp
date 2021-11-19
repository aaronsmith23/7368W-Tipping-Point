/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Aaron Smith                                      */
/*    Created:      Mon Oct 18 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightFront           motor         11              
// RightRear            motor         1               
// ForkRight            motor         4               
// LiftRight            motor         5               
// LiftLeft             motor         7               
// ForkLeft             motor         8               
// LeftRear             motor         10              
// LeftFront            motor         20              
// Clamp                digital_out   A               
// Inertial             inertial      21              
// Vision               vision        3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  LeftFront.setStopping(brake);
  LeftRear.setStopping(brake);
  RightFront.setStopping(brake);
  RightRear.setStopping(brake);
  LiftLeft.setStopping(hold);
  LiftRight.setStopping(hold);
  ForkLeft.setStopping(hold);
  ForkRight.setStopping(hold);
  Clamp.set(true);
  Inertial.calibrate();
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void Move (double dist, int speed, double slow) {
 
  LeftFront.setPosition(0, turns);
  LeftRear.setPosition(0, turns);
  RightFront.setPosition(0, turns);
  RightRear.setPosition(0, turns);
  
}




bool clamped = false;

void Clampy () {
  if (clamped) {
    Clamp.set (true);
    clamped = false;
  } else {
    Clamp.set (false);
    clamped = true;
  }
}


void autonomous(void) {
  // .........................................................................
  // Functions Index
  // ..........................................................................


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
    Controller1.ButtonA.pressed(Clampy);
    LeftFront.setStopping(brake);
    LeftRear.setStopping(brake);
    RightFront.setStopping(brake);
    RightRear.setStopping(brake);
    LiftLeft.setStopping(hold);
    LiftRight.setStopping(hold);
    ForkLeft.setStopping(hold);
    ForkRight.setStopping(hold);
    
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    LeftFront.spin(forward, Controller1.Axis3.position(percent), percent);
    LeftRear.spin(forward, Controller1.Axis3.position(percent), percent);
    RightFront.spin(forward, Controller1.Axis2.position(percent), percent);
    RightRear.spin(forward, Controller1.Axis2.position(percent), percent);

  
  if (Controller1.ButtonUp.pressing()){
    LeftFront.spin (forward, 30, percent);
    LeftRear.spin (forward, 30, percent);
    RightFront.spin (forward, 30, percent);
    RightRear.spin (forward, 30, percent);
  } else if (Controller1.ButtonDown.pressing()){
    LeftFront.spin (reverse, 30, percent);
    LeftRear.spin (reverse, 30, percent);
    RightFront.spin (reverse, 30, percent);
    RightRear.spin (reverse, 30, percent);
  } else {
    LeftFront.stop();
    LeftRear.stop();
    RightFront.stop();
    RightRear.stop();
  }

  if (Controller1.ButtonLeft.pressing()){
    LeftFront.spin (reverse,30,percent);
    LeftRear.spin (reverse,30,percent);
    RightFront.spin (forward,30,percent);
    RightRear.spin (forward,30,percent);
  } else if (Controller1.ButtonRight.pressing()){
    LeftFront.spin (forward,30,percent);
    LeftRear.spin (forward,30,percent);
    RightFront.spin (reverse,30,percent);
    RightRear.spin (reverse,30,percent);
  } else {
    LeftFront.stop();
    LeftRear.stop();
    RightFront.stop();
    RightRear.stop();
  }

  
  wait(20, msec); 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}