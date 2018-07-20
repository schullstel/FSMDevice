#pragma once

#include "State.h"
#include <memory>
#include <string>

class StateValidating : public ATMState
{
private:

public:
  StateValidating(StateTransitionFunc stateTransitionFunc)
      : ATMState(stateTransitionFunc)
      {}
  void handle(const Message& message) override
  {
    if(message.type==PinVerification)
    {
      std::cout << "Your PIN code is valid\n";
      stateTransition(PROCESS);
    }
    else if((message.type==IncorrectPin))
    {
      std::cout << "Your PIN code is invalid!\n";
      stateTransition(IDLE);
    }
    else if((message.type==CardBanned))
    {
      std::cout << "Your card is banned!\n";
      stateTransition(IDLE);
    }
    else
    {
      std::cout << "Unexpected behaviour\n";
    }
  }
};
