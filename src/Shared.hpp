#pragma once

#include <map>
#include <memory>
#include <stdexcept>

#include "thilow97/DogStates.hpp"

#include "States/Factory.hpp"
#include "States/State.hpp"

namespace thilow97 {
struct SharedAttributes
{
   private:
      std::map< DogStateID, std::unique_ptr< State > > m_states;
      DogStateID m_currentState;

   public:
      SharedAttributes ( const StateFactory& factory )
      {
         m_states[ DogStateID::STANDING ] = factory.get ( DogStateID::STANDING, *this );
         m_states[ DogStateID::SITTING ]  = factory.get ( DogStateID::SITTING, *this );
         m_states[ DogStateID::LAYING ]   = factory.get ( DogStateID::LAYING, *this );
         m_states[ DogStateID::SLEEPING ] = factory.get ( DogStateID::SLEEPING, *this );
         m_currentState                   = DogStateID::STANDING;
      }

      SharedAttributes ( void ) = delete;

      State& currentState ( void ) const
      {
         return *m_states.find ( m_currentState )->second;
      }

      DogStateID currentStateID ( void ) const
      {
         return m_currentState;
      }

      void setCurrentState ( DogStateID stateID )
      {
         if ( m_states.count ( stateID ) == 0 )
         {
            throw std::logic_error ( "Illegal state transition" );
         }

         this->currentState ().onExit ();
         m_currentState = stateID;
         this->currentState ().onEnter ();
      }
};
} // namespace thilow97