#include <iostream>
#include "State.h"
#include "Message.h"
#include "State_Validating.h"
#include "FsmDevice.h"
#include "Bank.h"

int main()
{
    std::cout << "Hello world" << std::endl;
    Message msg;
    Bank bk;
    msg.content="Nic";
    msg.type=CardInsertion;

    FSMDevice device;
        device.handle(msg);
    msg.type=PinVerification;
    device.handle(msg);
    msg.type=Withdraw;
    device.handle(msg);

    return 0;
}
