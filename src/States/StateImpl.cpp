#include <iostream>
#include <stdexcept>

#include "../Shared.hpp"
#include "StateImpl.hpp"

using namespace thilow97;

BaseState::BaseState ( SharedAttributes& attributes )
    : m_attributes ( attributes )
{}

BaseState::~BaseState ( void ) = default;

void BaseState::onEnter ( void )
{}

void BaseState::onExit ( void )
{}

void Standing::perform ( Dog::Command command )
{
   switch ( command )
   {
   case Dog::Command::STAND_UP:
      std::cout << "Wuff, I am already standing \n";
      break;
   case Dog::Command::SIT:
      std::cout << "Wuff, I am sitting down now \n";
      BaseState::m_attributes.setCurrentState ( DogStateID::SITTING );
      break;
   case Dog::Command::LAY_DOWN:
      std::cout << "Wuff, I am laying down now \n";
      BaseState::m_attributes.setCurrentState ( DogStateID::LAYING );
      break;
   default:
      std::cout << "Wuff Wuff, I do not understand \n";
      break;
   }
}

void Standing::feed ( void ) const
{
   throw std::logic_error ( "I need to be sitting before getting fed" );
}

void Standing::sleep ( void )
{
   throw std::logic_error ( "I need to lay down before sleeping" );
}

void Standing::wakeup ( void )
{
   throw std::logic_error ( "I am already awake!" );
}

void Sitting::perform ( Dog::Command command )
{
   switch ( command )
   {
   case Dog::Command::STAND_UP:
      std::cout << "Wuff, I am standing up now \n";
      BaseState::m_attributes.setCurrentState ( DogStateID::STANDING );
      break;
   case Dog::Command::SIT:
      std::cout << "Wuff, I am already sitting \n";
      break;
   case Dog::Command::LAY_DOWN:
      std::cout << "Wuff, I am laying down now \n";
      BaseState::m_attributes.setCurrentState ( DogStateID::LAYING );
      break;
   default:
      std::cout << "Wuff Wuff, I do not understand \n";
      break;
   }
}

void Sitting::feed ( void ) const
{
   std::cout << "Thank you I was sooo hungry \n";
}

void Sitting::sleep ( void )
{
   throw std::logic_error ( "I need to lay down before sleeping" );
}

void Sitting::wakeup ( void )
{
   throw std::logic_error ( "I am already awake!" );
}

void Laying::perform ( Dog::Command command )
{
   switch ( command )
   {
   case Dog::Command::STAND_UP:
      std::cout << "Wuff, I am standing up now \n";
      BaseState::m_attributes.setCurrentState ( DogStateID::STANDING );
      break;
   case Dog::Command::SIT:
      std::cout << "Wuff, I am sitting now \n";
      BaseState::m_attributes.setCurrentState ( DogStateID::SITTING );
      break;
   case Dog::Command::LAY_DOWN:
      std::cout << "Wuff, I am already laying \n";
      break;
   default:
      std::cout << "Wuff Wuff, I do not understand \n";
      break;
   }
}

void Laying::feed ( void ) const
{
   throw std::logic_error ( "I need to be sitting before getting fed" );
}

void Laying::sleep ( void )
{
   std::cout << "I am sooo tired. Going for a nap now. Wake me up later \n";
   BaseState::m_attributes.setCurrentState ( DogStateID::SLEEPING );
}

void Laying::wakeup ( void )
{
   throw std::logic_error ( "I am already awake!" );
}

void Sleeping::perform ( Dog::Command command )
{
   throw std::logic_error ( "Wake me up before I can do anything!" );
}

void Sleeping::feed ( void ) const
{
   throw std::logic_error ( "I can not eat while sleeping" );
}

void Sleeping::sleep ( void )
{
   std::cout << "Zzzzzz \n";
}

void Sleeping::wakeup ( void )
{
   std::cout << "Ready for action \n";
   BaseState::m_attributes.setCurrentState ( DogStateID::LAYING );
}