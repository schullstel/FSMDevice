#pragma once

#include "State.h"
#include <memory>
#include <string>


class StateProcessing : public ATMState
{
private:
public:
  StateProcessing(StateTransitionFunc stateTransitionFunc)
      : ATMState(stateTransitionFunc)
      {}
  void handle(const Message& message) override
  {
    bool result;
    /*
    switch(message.type)
    {
      case(Withdraw):
        std::cout << "You want withdraw\n";
        std::cout << "Your current account balance: " << std::endl;
        std::cout << "Please take your card\n";
        stateTransition(IDLE);
        result = true;
        break;
      case(AccountBalance):
        std::cout << "Your current account balance: " << std::endl;
        std::cout << "Please take your card\n";
        stateTransition(IDLE);
        result = true;
        break;
      case(CancelTransaction):
        std::cout << "Transaction canceled\n";
        std::cout << "Please take your card\n";
        stateTransition(IDLE);
      default:
        std::cout << "Unexpected behaviour\n";




    }*/

    if(message.type==Withdraw)
    {

      std::cout << "Take your money\n";
      stateTransition(IDLE);
    }
    else if((message.type==AccountBalance))
    {
      std::cout << "Your account balance is\n";
      stateTransition(IDLE);
    }
    else if((message.type==CancelTransaction))
    {
      std::cout << "Transaction Canceled\n";
      stateTransition(IDLE);
    }
    else
    {
      std::cout << "Unexpected behaviour\n";
    }
  }

};
