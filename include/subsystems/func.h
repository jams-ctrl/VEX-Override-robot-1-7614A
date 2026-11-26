#ifndef __FUNC_H__
#define __FUNC_H__

#include "pros/motors.hpp"
namespace Func {
  void spinUntilResist(int direction, pros::Motor motor, int velocity);
}

#endif