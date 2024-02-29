#include "vex.h"

vex::brain Brain;

vex::controller Controller = vex::controller(vex::primary);

vex::bumper BumperA = vex::bumper(Brain.ThreeWirePort.A);
vex::bumper BumperB = vex::bumper(Brain.ThreeWirePort.B);

vex::motor Motor1 = vex::motor(vex::PORT1, vex::ratio18_1, false);
vex::motor Motor2 = vex::motor(vex::PORT2, vex::ratio18_1, false);
vex::motor Motor3 = vex::motor(vex::PORT3, vex::ratio18_1, false);
vex::motor rackMotor = vex::motor(vex::PORT4, vex::ratio18_1, false);

vex::vision Vision = vex::vision(vex::PORT11, 50);

