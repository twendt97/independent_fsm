#include <catch2/catch_all.hpp>
#include <memory>

#include "DogImpl.hpp"
#include "Shared.hpp"
#include "States/Factory.hpp"

TEST_CASE ( "Testing state dependent behavior which does not cause a state transition",
            "[StateBehavior]" )
{
   using namespace thilow97;
   auto attrPtr                 = std::make_unique< SharedAttributes > ( ConcreteStateFactory () );
   SharedAttributes& attributes = *attrPtr;
   DogImpl testDog ( "Goofy", "Beagle", std::move ( attrPtr ) );

   SECTION ( "A dog is standing" )
   {
      REQUIRE ( testDog.currentState () == DogStateID::STANDING );
      REQUIRE_NOTHROW ( testDog.perform ( Dog::Command::STAND_UP ) );
      REQUIRE_THROWS ( testDog.wakeup () );
      REQUIRE_THROWS ( testDog.feed () );
      REQUIRE_THROWS ( testDog.sleep () );
      REQUIRE ( testDog.currentState () == DogStateID::STANDING );
   }
   SECTION ( "A dog is sitting" )
   {
      attributes.setCurrentState ( DogStateID::SITTING );
      REQUIRE ( testDog.currentState () == DogStateID::SITTING );
      REQUIRE_NOTHROW ( testDog.perform ( Dog::Command::SIT ) );
      REQUIRE_NOTHROW ( testDog.feed () );
      REQUIRE_THROWS ( testDog.sleep () );
      REQUIRE_THROWS ( testDog.wakeup () );
      REQUIRE ( testDog.currentState () == DogStateID::SITTING );
   }
   SECTION ( "A dog is laying" )
   {
      attributes.setCurrentState ( DogStateID::LAYING );
      REQUIRE ( testDog.currentState () == DogStateID::LAYING );
      REQUIRE_NOTHROW ( testDog.perform ( Dog::Command::LAY_DOWN ) );
      REQUIRE_THROWS ( testDog.feed () );
      REQUIRE_THROWS ( testDog.wakeup () );
      REQUIRE ( testDog.currentState () == DogStateID::LAYING );
   }
   SECTION ( "A dog is sleeping" )
   {
      attributes.setCurrentState ( DogStateID::SLEEPING );
      REQUIRE ( testDog.currentState () == DogStateID::SLEEPING );
      REQUIRE_NOTHROW ( testDog.sleep () );
      REQUIRE_THROWS ( testDog.perform ( Dog::Command::LAY_DOWN ) );
      REQUIRE_THROWS ( testDog.perform ( Dog::Command::SIT ) );
      REQUIRE_THROWS ( testDog.perform ( Dog::Command::STAND_UP ) );
      REQUIRE_THROWS ( testDog.feed () );
      REQUIRE ( testDog.currentState () == DogStateID::SLEEPING );
   }
}