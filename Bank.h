#pragma once


#include <string>

class Bank
{
public:
    bool isCardActive(const std::string& cardNumber) const;
    bool isPinValid(const std::string& pinNumber) const;
    bool isWidthdrawAccepted(const std::string& money) const;
    std::string getAccountBalance() const;
};
