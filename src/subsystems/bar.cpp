#include "./subsystems/bar.h"
#include "main.h"
#include "devices.h"
#include "globals.h"
#include "./subsystems/func.h"

namespace Bar{
  int bar_state = BCK;

  void toggle(){
    if (bar_state == BCK){
      bar_state = FNT;
      Func::spinUntilResist(-1,bar_motor, 100);  
    } else if (bar_state == FNT){
      bar_state = BCK;
      Func::spinUntilResist(1,bar_motor, 100);  
    }
  }
  void scoreToggle(){
    if (bar_state == FNT){
      bar_state = TOP;
      bar_motor.move_relative(120, 100);  
    } else if (bar_state == BCK){
      bar_state = TOP;
      bar_motor.move_relative(-120, 100);  
    } else if (bar_state == TOP){
      bar_state = BCK;
      Func::spinUntilResist(1,bar_motor, 100);  
    }
  }

  bool get(){
    return bar_state;
  }
}