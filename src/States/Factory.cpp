#include <stdexcept>

#include "Factory.hpp"
#include "StateImpl.hpp"

using namespace thilow97;

std::unique_ptr< State > ConcreteStateFactory::get ( DogStateID stateID,
                                                     SharedAttributes& attributes ) const
{
   switch ( stateID )
   {
   case DogStateID::STANDING:
      return std::make_unique< Standing > ( attributes );
   case DogStateID::SITTING:
      return std::make_unique< Sitting > ( attributes );
   case DogStateID::LAYING:
      return std::make_unique< Laying > ( attributes );
   case DogStateID::SLEEPING:
      return std::make_unique< Sleeping > ( attributes );
   default:
      throw std::logic_error ( "Requested state does not exist" );
   }
}
