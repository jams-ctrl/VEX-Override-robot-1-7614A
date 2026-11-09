#include "./subsystems/lift.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Lift{
  bool lift_state = false;
  int pos = 90;

  void toggle(){
    lift_state = !lift_state;
    extend();
  }
  void set(bool state){
    lift_state = state;
    extend();
  }
  bool get(){
    return lift_state;
  }
  void extend(){
    // set current motor position as 0
    lift_motor.tare_position();
    // if cascade up
    if (lift_state){
      // goes down
      lift_motor.move_absolute(-pos, 100);  
      // optional - stalls program until lift completes execution
      while (!((lift_motor.get_position() < -pos - 5) && (lift_motor.get_position() > -pos + 5))) {
        pros::delay(2);
    }
    } else {
      // goes up
      lift_motor.move_absolute(pos, 100);  
      while (!((lift_motor.get_position() < pos + 5) && (lift_motor.get_position() > pos - 5))) {
        pros::delay(2);
      }
    }
  }
}