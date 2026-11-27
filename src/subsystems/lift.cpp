#include "./subsystems/lift.h"
#include "main.h"
#include "devices.h"
#include "globals.h"
#include "./subsystems/func.h"
namespace Lift{
  int lift_state = OFF;
  int pos = 90;

  void toggle(){
    if (lift_state == OFF){
      set(EXT);
    } else {
      set(OFF);
    }
  }
  void set(int state){
    lift_state = state;
    extend(state);
  }
  bool get(){
    return lift_state;
  }
  
  void extend(int state){
    // if cascade up
    if (state == OFF){
      // goes down
      Func::spinUntilResist(1,lift_motor, 100);
    } else if (state == EXT){
      // goes up
      Func::spinUntilResist(-1,lift_motor, 100);
    } else if (state == ONE){
      // down
      Func::spinUntilResist(1,lift_motor, 100);
      // up
      lift_motor.move_relative(-100, 100);
    } else if (state == TWO){
      // down
      Func::spinUntilResist(1,lift_motor, 100);
      // up 
      lift_motor.move_relative(-200, 100);
    }
  }
}
// lift_motor.tare_position();
// if (lift_state){
//       // goes down
//       lift_motor.move_absolute(-pos, 100);  
//       // optional - stalls program until lift completes execution
//       while (!((lift_motor.get_position() < -pos - 5) && (lift_motor.get_position() > -pos + 5))) {
//         pros::delay(2);
//     }