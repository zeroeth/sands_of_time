#include "Arduino.h"
#include "color_utilities.h"

class SandGrain {
 public:

  uint8_t position;
  uint32_t color;

  /* METHODS */
  void pick_color();
};
