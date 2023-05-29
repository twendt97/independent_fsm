#pragma once

#include <memory>
#include <string>

namespace thilow97 {

// --------------------------------
// Forward declarations
// --------------------------------

class Dog;

class DogFactory
{
   public:
      static std::unique_ptr< Dog > get ( const std::string& name, const std::string& breed );
};
} // namespace thilow97