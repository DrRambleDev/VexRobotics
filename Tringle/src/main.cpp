// Header files

#include "vex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <vex_units.h>
#include <stddef.h>
#include <iostream>
#include <ctime>
#include "devices.hpp"  // * ctrl + click to go to header file

void move() {

    float forceOne = ((-0.3464f * Controller.Axis4.position()) + (0.580f * Controller.Axis3.position()) + (0.3464f * Controller.Axis1.position()));
    float forceTwo = ((-0.3464f * Controller.Axis4.position()) + (-0.58f * Controller.Axis3.position()) + (0.3464f * Controller.Axis1.position()));
    float forceThree = ((0.667f * Controller.Axis4.position()) + (0.000f * Controller.Axis3.position()) + (0.3464f * Controller.Axis1.position()));

    Motor1.spin(vex::directionType::fwd, forceOne, vex::percentUnits::pct);
    Motor2.spin(vex::directionType::fwd, forceTwo, vex::percentUnits::pct);
    Motor3.spin(vex::directionType::fwd, forceThree, vex::percentUnits::pct);

}

void clawThing() {

    if(Controller.ButtonUp.pressing()) {
      if(BumperB.pressing() == false) {
        rackMotor.spin(vex::directionType::fwd, 7, vex::voltageUnits::volt);
      }
    } else if((Controller.ButtonDown.pressing() == true)) {
      if(BumperA.pressing() == false) {
        rackMotor.spin(vex::directionType::fwd, -7, vex::voltageUnits::volt);
      }
    } else {
        rackMotor.stop();
    }

}

void clawThingButVoltGetsChecked() {

  int motorCurrent = rackMotor.current(vex::percentUnits::pct); // * it is ~9 when it hits the top and tries to keep going

  if(Controller.ButtonUp.pressing()) {
    if(motorCurrent < 8) {
      rackMotor.spin(vex::directionType::fwd, 7, vex::voltageUnits::volt);
    }
  } else if(Controller.ButtonDown.pressing()) {
    if(motorCurrent < 8) {
      rackMotor.spin(vex::directionType::rev, 7, vex::voltageUnits::volt);
    }
  } else {
    rackMotor.stop();
  }

}

// *TODO stop robot from lurching when partymode is on

void partyMode() {

    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
    Brain.Screen.setFillColor(vex::red);
    vex::wait(.5, vex::sec);
    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
    Brain.Screen.setFillColor(vex::green);
    vex::wait(.5, vex::sec);
    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
    Brain.Screen.setFillColor(vex::blue);
    vex::wait(.5, vex::sec);
    Brain.Screen.drawRectangle(0, 0, 1000, 1000);
    Brain.Screen.setFillColor(vex::yellow);
    vex::wait(.5, vex::sec);

}

void writeCurrent() {

  int rackCurrent = rackMotor.current(vex::amp);
  Brain.Screen.print(rackCurrent);

}

int main(int argc, char *argv[]) {

    while(Controller.ButtonX.pressing() == false) {
        move();
        clawThing();
        writeCurrent();
        
        ////partyMode();
        //clawThingButVoltGetsChecked();
    }
    vexSystemExitRequest();

}