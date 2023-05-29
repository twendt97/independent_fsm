#pragma once

#include <memory>

#include "thilow97/DogStates.hpp"

namespace thilow97 {
class State;
struct SharedAttributes;

class StateFactory
{
   public:
      virtual std::unique_ptr< State > get ( DogStateID stateID,
                                             SharedAttributes& attributes ) const = 0;
};

class ConcreteStateFactory : public StateFactory
{
   public:
      virtual std::unique_ptr< State > get ( DogStateID stateID,
                                             SharedAttributes& attributes ) const override;
};
} // namespace thilow97