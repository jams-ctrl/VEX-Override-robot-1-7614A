#include "./subsystems/lift.h"
#include "main.h"
#include "devices.h"
#include "globals.h"
#include "./subsystems/func.h"
namespace Lift{
  // cascade max height: 12500
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
    lift_state=state;
    if (state == OFF){
      // goes down
      // lift_motor.move_velocity(200);
      // lift_motor_2.move_velocity(200);
      lift_motor.move(127);
      lift_motor_2.move(127);
    } else if (state == EXT){
      // goes up
      // lift_motor.move_velocity(-200);
      // lift_motor_2.move_velocity(-200);
      lift_motor.move(-127);
      lift_motor_2.move(-127);
      // Func::spinUntilResist(-1,lift_motor, 100);
      // Func::spinUntilResist(-1,lift_motor_2, 100);
    } else if (state == 6){
      // goes up
      lift_motor.move_velocity(0);
      lift_motor_2.move_velocity(0);
      // Func::spinUntilResist(-1,lift_motor, 100);
      // Func::spinUntilResist(-1,lift_motor_2, 100);
    } 
    else if (state == ONE){
      // down
      lift_motor.move_relative(-100, 100);  
      // up
      Func::spinUntilResist(1,lift_motor, 100);
    } else if (state == TWO){
      // down
      lift_motor.move_relative(-200, 100);  
      // up
      Func::spinUntilResist(1,lift_motor, 100);
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