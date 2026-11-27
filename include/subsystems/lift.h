#ifndef __LIFT_H__
#define __LIFT_H__

namespace Lift {
  void set(int state);
  void toggle();
  bool get();
  void extend(int state);
}

#endif