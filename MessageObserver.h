#pragma once

#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <messaging/Messager.h>

typedef std::function<void ()> Handler;

class MessengeObserver : public Messager
{
private:
  std::map<unsigned, Handler> handlers;
  unsigned nextID;

public:
  MessengeObserver() : nextID(0){}
	virtual ~Messenger() = default;

  unsigned connect(Handler handler)
  {
    handlers[nextID] = handler;
    std::cout << "I added new ID\n";
    return nextID++;
  }

  void disconnect(unsigned id)
  {
    std::cout << "I erased new ID\n";
    handlers.erase(id);
  }

  void send()
  {
    for(auto h : handlers)
    {
      h.second();
      std::cout << h.first << std::endl;
    }
  }

	void addMessage(const std::string& receiver, const Message& message) override
  {

  }
	std::vector<Message> collectMessages(const std::string& receiver) override
  {

  }

	//onMessageReceived
};
