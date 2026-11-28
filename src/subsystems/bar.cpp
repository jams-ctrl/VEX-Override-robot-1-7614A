#include "./subsystems/bar.h"
#include "main.h"
#include "devices.h"
#include "globals.h"
#include "./subsystems/func.h"
#include <cstdio>

namespace Bar{
  int bar_state = BCK;

  void toggle(){
    if (bar_state == BCK){
      bar_state = FNT;
      bar_motor.move(127);
      pros::delay(600);
      // at top
      pros::delay(100);
      bar_motor.brake();
      Func::spinUntilResist(1, bar_motor, 10);
      // if (bar_motor.get_position()>800){
      //   bar_motor.move(0);
      // }
      //Func::spinUntilResist(-1,bar_motor, 100);  
    } else if (bar_state == FNT){
      bar_state = BCK;
      bar_motor.move(-127);
      pros::delay(600);
      // at top
      pros::delay(100);
      bar_motor.brake();
      Func::spinUntilResist(-1, bar_motor, 10);
      // if (bar_motor.get_position()<98){
      //   bar_motor.move(-0);
      // }
      //Func::spinUntilResist(1,bar_motor, 100);  
    }
  }

   void stop(){
    bar_motor.move_velocity(0);
  }
  void scoreToggle(){
    if (bar_state == FNT){
      bar_state = TOP;
      bar_motor.move_relative(700, 200);  
    } else if (bar_state == BCK){
      bar_state = TOP;
      bar_motor.move(127);
      pros::delay(500);
      bar_motor.brake();
    } else if (bar_state == TOP){
      bar_state = BCK;
      bar_motor.move(-127);
      pros::delay(100);
      bar_motor.brake();
      Func::spinUntilResist(-1, bar_motor, 10);
    }
  }

  bool get(){
    return bar_state;
  }
}