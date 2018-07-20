#pragma once


#include <string>
#include "Message.h"
#include "Component.h"
#include <memory>
#include <functional>
#include <iostream>


enum State
{
  IDLE=1,
  VALID=2,
  PROCESS=3
};

typedef std::function<void (State)> StateTransitionFunc;

class ATMState : public Component
{
public:
    ATMState(StateTransitionFunc stateTransitionFunc)
        : stateTransitionFunc(stateTransitionFunc)
    {}

    virtual void handle(const Message& message) = 0;
    virtual ~ATMState() {}

private:
   StateTransitionFunc stateTransitionFunc;

protected:
    void stateTransition(State newState)
    {
        //std::cout << "DEBUGLOG: state transition to:" << newState << "\n";
        stateTransitionFunc(newState);
    }
};
