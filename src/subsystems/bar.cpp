#include "./subsystems/bar.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace bar{
  int bar_state = BCK;

  void toggle(){
    if (bar_state == BCK){
      bar_state = FNT;
      bar_motor.move_relative(-250, 100);  
    } else if (bar_state == FNT){
      bar_state = BCK;
      bar_motor.move_relative(250, 100);  
    }
  }
  void scoreToggle(int state){
    if (state == FNT){
      bar_state = TOP;
      bar_motor.move_relative(120, 100);  
    } else if (state == BCK){
      bar_state = TOP;
      bar_motor.move_relative(-120, 100);  
    } else if (state == TOP){
      bar_state = BCK;
      bar_motor.move_relative(120, 100);  
    }
  }

  bool get(){
    return bar_state;
  }
}