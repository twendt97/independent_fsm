#include <iostream>

#include "DogImpl.hpp"
#include "Shared.hpp"

using namespace thilow97;

DogImpl::DogImpl ( std::string name, std::string breed,
                   std::unique_ptr< SharedAttributes > attributes )
    : m_name ( name )
    , m_breed ( breed )
    , m_attributes ( std::move ( attributes ) )
{}

void DogImpl::pet ( void ) const
{
   std::cout << "Cuddling " << this->m_name << "\n";
}

void DogImpl::perform ( Command command )
{
   m_attributes->currentState ().perform ( command );
}

void DogImpl::feed ( void ) const
{
   m_attributes->currentState ().feed ();
}

void DogImpl::sleep ( void )
{
   m_attributes->currentState ().sleep ();
}

void DogImpl::wakeup ( void )
{
   m_attributes->currentState ().wakeup ();
}

DogStateID DogImpl::currentState ( void ) const
{
   return m_attributes->currentStateID ();
}