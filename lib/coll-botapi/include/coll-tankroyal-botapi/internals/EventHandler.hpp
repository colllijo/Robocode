#ifndef COLL_TANKROYAL_BOTAPI_EVENT_HANDLER_HPP
#define COLL_TANKROYAL_BOTAPI_EVENT_HANDLER_HPP

#include <algorithm>
#include <vector>

#include "EventConsumer.hpp"

#pragma once

template <class T> struct ConsumerWithPriority {
	EventConsumer<T> consumer;
	int priority;

	ConsumerWithPriority<T>(EventConsumer<T> consumer, int priority)
		: consumer(consumer), priority(priority) {}
};

template <class T> class EventHandler {
  public:
	EventHandler();
	~EventHandler();

	void subscribe(EventConsumer<T> subscriber, int priority = 1) {
		subscribers.push_back(ConsumerWithPriority<T>(subscriber, priority));
	}

	void publish(T event) {
		std::sort(subscribers.begin(), subscribers.end(),
				  [](const ConsumerWithPriority<T> &a,
					 const ConsumerWithPriority<T> &b) {
					  return a.priority < b.priority;
				  });
		for (const auto &subscriber : subscribers)
			subscriber.consumer.accept(event);
	}

  private:
	std::vector<EventConsumer<T>> subscribers;
};

#endif
