#include "./subsystems/intake.h"
#include "./subsystems/doublepark.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Intake{
  // define state variables
  int intake_state = OFF;
  // toggle intake 
  void toggle(){
    //reverse current state 
    if(intake_state == FWD){
      set_intake(OFF);
    }else{
      set_intake(FWD);
    }
  }
  // set intake state; called by above function
  void set_intake(int state){
    intake_motor.set_brake_mode(pros::motor_brake_mode_e_t::E_MOTOR_BRAKE_COAST);
    if(state == FWD){
      intake_state = FWD;
      // set motor velocity
      intake_motor.move_velocity(600);
    } else if (state == REV){
      intake_state = REV;
      // set motor velocity
      intake_motor.move_velocity(-600);
    } else{
      intake_state = OFF;
      // set motor velocity
      intake_motor.move_velocity(0);
    }
  }
  // getter
  int get_intake(){
    return intake_state;
  }
}