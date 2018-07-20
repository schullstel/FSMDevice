#pragma once

#include "Message.h"
#include "Component.h"
#include "Dispatcher.h"

class DispatcherControl : public Dispatcher
{
public:
    virtual ~Dispatcher() = default;

    virtual void registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) = 0; //how about reference instead of shared_ptr?
    void forwardMessage(const Message& message)
    {

    }
  private:
    Component component;
    std::set<MessageId> availableTypes;
};
