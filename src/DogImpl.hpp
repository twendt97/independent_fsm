#pragma once

#include <memory>
#include <string>

#include "thilow97/Dog.hpp"

namespace thilow97 {

// --------------------------------
// Forward declarations
// --------------------------------

struct SharedAttributes;

class DogImpl : public Dog
{
   public:
      DogImpl ( void ) = delete;
      DogImpl ( std::string name, std::string breed,
                std::unique_ptr< SharedAttributes > attributes );

      virtual void pet ( void ) const override;
      virtual void perform ( Command command ) override;
      virtual void feed ( void ) const override;
      virtual void sleep ( void ) override;
      virtual void wakeup ( void ) override;
      virtual DogStateID currentState ( void ) const override;

      const std::string m_name;
      const std::string m_breed;

   private:
      std::unique_ptr< SharedAttributes > m_attributes;
};
} // namespace thilow97