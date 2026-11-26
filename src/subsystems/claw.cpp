#include "./subsystems/claw.h"
#include "main.h"
#include "devices.h"
#include "globals.h"

namespace Claw{
  bool claw_state = false;

  void toggle(){
    claw_state = !claw_state;
    claw.set_value(claw_state);
  }
  void set(bool state){
    claw_state = state;
    claw.set_value(claw_state);
  }
  bool get(){
    return claw_state;
  }
}