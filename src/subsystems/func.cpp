#include "./subsystems/func.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Func{
 void spinUntilResist(int dir, pros::Motor motor, int vel){
    // begin unrestricted motor movement
    motor.move_velocity(vel*dir);
    // get position
    int prevPos = motor.get_position();
    // allow motor to begin moving
    pros::delay(2000);

    bool noResist = true;
    while (noResist){
      // get current position
      int currPos= motor.get_position();
      // check if pos hasnt changed or abs velocity drops to less than 1
      if (currPos == prevPos || std::abs(motor.get_actual_velocity()) < 1.0) {
        noResist = false;
      }
      prevPos = currPos;
      // prevent CPU overload
      pros::delay(10);
    }
    motor.move(0);
  }
}