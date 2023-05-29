#pragma once

#include <string>

#include "DogStates.hpp"

namespace thilow97 {

class Dog
{
   public:
      enum struct Command : int
      {
         STAND_UP = 0,
         SIT,
         LAY_DOWN,
         RUN
      };

      virtual ~Dog ()                                = default;
      virtual void pet ( void ) const                = 0;
      virtual void perform ( Command command )       = 0;
      virtual void feed ( void ) const               = 0;
      virtual void sleep ( void )                    = 0;
      virtual void wakeup ( void )                   = 0;
      virtual DogStateID currentState ( void ) const = 0;
};

} // namespace thilow97