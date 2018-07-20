#pragma once

#include "State.h"
#include <memory>
#include <string>


class StateIdle : public ATMState
{
public:
  StateIdle(StateTransitionFunc stateTransitionFunc)
      : ATMState(stateTransitionFunc)
      {}
  void handle(const Message& message) override
  {
    if(message.type==CardInsertion)
    {
      std::cout << "Reading your card\n";
      stateTransition(VALID);
    }
    else
    {
      std::cout << "Unexpected behaviour\n";
    }
  //  else if((message.type))
  //  {
  //    std::cout << "Your account balance is\n";
      //stateTransition(IDLE);
  //  }
  //  else if((message.type==CancelTransaction))
  //  {
    //  std::cout << "Transaction Canceled\n";
      //tateTransition(IDLE);
    //}
  }

};
