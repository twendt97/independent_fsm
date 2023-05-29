#include <exception>
#include <memory>

#include <catch2/catch_all.hpp>
#include <fakeit.hpp>

#include "DogImpl.hpp"
#include "Shared.hpp"
#include "States/Factory.hpp"

using namespace thilow97;

class TestAbortException : public std::exception
{
      const char* what () const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
      {
         return "State dependent method called";
      }
};

class FakeStateFactory : public StateFactory
{
   private:
      State* const m_fakeState;

   public:
      FakeStateFactory ( State* fakeState )
          : m_fakeState ( fakeState )
      {
         assert ( m_fakeState != nullptr );
      }

      std::unique_ptr< State > get ( DogStateID stateID,
                                     SharedAttributes& attributes ) const override
      {
         return std::unique_ptr< State > ( m_fakeState );
      }
};

TEST_CASE ( "Testing state independent behavior", "[state_independent]" )
{
   using namespace fakeit;
   Mock< State > stateMock;

   FakeStateFactory stateFactory ( &stateMock.get () );
   When ( Method ( stateMock, perform ) ).AlwaysThrow ( TestAbortException () );
   When ( Method ( stateMock, feed ) ).AlwaysThrow ( TestAbortException () );
   When ( Method ( stateMock, sleep ) ).AlwaysThrow ( TestAbortException () );
   When ( Method ( stateMock, wakeup ) ).AlwaysThrow ( TestAbortException () );
   When ( Method ( stateMock, onEnter ) ).AlwaysThrow ( TestAbortException () );
   When ( Method ( stateMock, onExit ) ).AlwaysThrow ( TestAbortException () );

   SECTION ( "State independent methods" )
   {
      REQUIRE_NOTHROW (
          DogImpl ( "Goofy", "Beagle", std::make_unique< SharedAttributes > ( stateFactory ) ) );

      DogImpl testDog ( "Goofy", "Beagle", std::make_unique< SharedAttributes > ( stateFactory ) );
      REQUIRE_NOTHROW ( testDog.pet () );
   }
}
