#pragma once

#include "State.hpp"

namespace thilow97 {

// --------------------------------
// Forward declarations
// --------------------------------

struct SharedAttributes;

class BaseState : public State
{
   protected:
      SharedAttributes& m_attributes;

   public:
      BaseState ( SharedAttributes& );
      BaseState ( void ) = delete;
      virtual void onEnter ( void ) override;
      virtual void onExit ( void ) override;
      virtual ~BaseState ( void );
};

class Standing : public BaseState
{
   public:
      using BaseState::BaseState;
      virtual void perform ( Dog::Command command ) override;
      virtual void feed ( void ) const override;
      virtual void sleep ( void ) override;
      virtual void wakeup ( void ) override;
};

class Sitting : public BaseState
{
   public:
      using BaseState::BaseState;
      virtual void perform ( Dog::Command command ) override;
      virtual void feed ( void ) const override;
      virtual void sleep ( void ) override;
      virtual void wakeup ( void ) override;
};

class Laying : public BaseState
{
   public:
      using BaseState::BaseState;
      virtual void perform ( Dog::Command command ) override;
      virtual void feed ( void ) const override;
      virtual void sleep ( void ) override;
      virtual void wakeup ( void ) override;
};

class Sleeping : public BaseState
{
   public:
      using BaseState::BaseState;
      virtual void perform ( Dog::Command command ) override;
      virtual void feed ( void ) const override;
      virtual void sleep ( void ) override;
      virtual void wakeup ( void ) override;
};
} // namespace thilow97
