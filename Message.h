#pragma once


#include <string>

enum MessageId
{
    CardInsertion ,
    PinVerification,
    Withdraw,
    AccountBalance,
    CancelTransaction,
    CardEjection,
    IncorrectPin,
    CardBanned,
    LackOfFounds,
};

struct Message
{
    MessageId type;
    std::string content;
};
