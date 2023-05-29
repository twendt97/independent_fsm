#pragma once

#include "thilow97/Dog.hpp"

namespace thilow97 {
class State
{
   public:
      virtual ~State ( void ) = default;

      virtual void perform ( Dog::Command command ) = 0;
      virtual void feed ( void ) const              = 0;
      virtual void sleep ( void )                   = 0;
      virtual void wakeup ( void )                  = 0;
      virtual void onEnter ( void )                 = 0;
      virtual void onExit ( void )                  = 0;
};

} // namespace thilow97
