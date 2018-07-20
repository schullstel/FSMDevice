#pragma once

#include "State.h"
#include "State_Validating.h"
#include "State_Idle.h"
#include "State_Processing.h"
#include "Bank.h"
#include <string>
#include <memory>
#include <map>



class FSMDevice
{
public:
    FSMDevice() //: bank(bk)
    {
        createStatesMap();
        currentState = allStates[IDLE];
        //std::cout << __PRETTY_FUNCTION__ <<std::endl;
    }

    void handle(const Message& message)
    {
      currentState->handle(message);
    }


private:
    void createStatesMap()
    {
        StateTransitionFunc transition = [this](State state)
        {
            this->currentState = allStates[state];
        };

        auto sharedName = std::make_shared<std::string>();

        allStates[IDLE] = std::make_shared<StateIdle>(transition);
        allStates[PROCESS] = std::make_shared<StateProcessing>(transition);
        allStates[VALID] = std::make_shared<StateValidating>(transition);
    }

    std::map<State, std::shared_ptr<ATMState>> allStates;
    std::shared_ptr<ATMState> currentState;
    //Bank& bank;
};
