#include "thilow97/DogFactory.hpp"

#include "DogImpl.hpp"
#include "Shared.hpp"
#include "States/Factory.hpp"

using namespace thilow97;

std::unique_ptr< Dog > DogFactory::get ( const std::string& name, const std::string& breed )
{
   auto attributes = std::make_unique< SharedAttributes > ( ConcreteStateFactory () );
   return std::make_unique< DogImpl > ( name, breed, std::move ( attributes ) );
}