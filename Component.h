#pragma once


#include "Message.h"

class Component
{
public:
    virtual ~Component() = default;

    virtual void handle(const Message& message) = 0;
};
