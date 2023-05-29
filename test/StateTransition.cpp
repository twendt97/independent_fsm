#include <catch2/catch_all.hpp>

#include "thilow97/Dog.hpp"
#include "thilow97/DogFactory.hpp"
#include "thilow97/DogStates.hpp"

using namespace thilow97;

SCENARIO ( "Testing state transitions" )
{
   auto testDog = DogFactory::get ( "Goofy", "Beagle" );

   GIVEN ( "A dog that is standing" )
   {
      REQUIRE ( testDog->currentState () == DogStateID::STANDING );
      WHEN ( "The dog is asked to lay down" )
      {
         REQUIRE_NOTHROW ( testDog->perform ( Dog::Command::LAY_DOWN ) );
         THEN ( "The dog follows as expected" )
         {
            REQUIRE ( testDog->currentState () == DogStateID::LAYING );
         }
      }
      WHEN ( "The dog is asked to sit" )
      {
         REQUIRE_NOTHROW ( testDog->perform ( Dog::Command::SIT ) );
         THEN ( "The dog follows as expected" )
         {
            REQUIRE ( testDog->currentState () == DogStateID::SITTING );
         }
      }
   }
   GIVEN ( "A dog that is sitting" )
   {
      testDog->perform ( Dog::Command::SIT );
      REQUIRE ( testDog->currentState () == DogStateID::SITTING );
      WHEN ( "The dog is asked to stand up" )
      {
         REQUIRE_NOTHROW ( testDog->perform ( Dog::Command::STAND_UP ) );
         THEN ( "The dog follows as expected" )
         {
            REQUIRE ( testDog->currentState () == DogStateID::STANDING );
         }
      }
      WHEN ( "The dog is asked to lay down" )
      {
         REQUIRE_NOTHROW ( testDog->perform ( Dog::Command::LAY_DOWN ) );
         THEN ( "The dog follows as expected" )
         {
            REQUIRE ( testDog->currentState () == DogStateID::LAYING );
         }
      }
   }
   GIVEN ( "A dog that is laying" )
   {
      testDog->perform ( Dog::Command::LAY_DOWN );
      REQUIRE ( testDog->currentState () == DogStateID::LAYING );
      WHEN ( "The dog is asked to stand up" )
      {
         REQUIRE_NOTHROW ( testDog->perform ( Dog::Command::STAND_UP ) );
         THEN ( "The dog follows as expected" )
         {
            REQUIRE ( testDog->currentState () == DogStateID::STANDING );
         }
      }
      WHEN ( "The dog is asked to sit" )
      {
         REQUIRE_NOTHROW ( testDog->perform ( Dog::Command::SIT ) );
         THEN ( "The dog follows as expected" )
         {
            REQUIRE ( testDog->currentState () == DogStateID::SITTING );
         }
      }
      WHEN ( "The dog wants to go to sleep" )
      {
         REQUIRE_NOTHROW ( testDog->sleep () );
         THEN ( "The dog is sleeping" )
         {
            REQUIRE ( testDog->currentState () == DogStateID::SLEEPING );
         }
      }
   }
   GIVEN ( "A sleeping dog" )
   {
      testDog->perform ( Dog::Command::LAY_DOWN );
      testDog->sleep ();
      REQUIRE ( testDog->currentState () == DogStateID::SLEEPING );
      WHEN ( "The dog wakes up" )
      {
         REQUIRE_NOTHROW ( testDog->wakeup () );
         THEN ( "The dog is laying" )
         {
            REQUIRE ( testDog->currentState () == DogStateID::LAYING );
         }
      }
   }
}