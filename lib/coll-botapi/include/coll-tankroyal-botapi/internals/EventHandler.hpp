#ifndef COLL_TANKROYAL_BOTAPI_EVENT_HANDLER_HPP
#define COLL_TANKROYAL_BOTAPI_EVENT_HANDLER_HPP

#include <algorithm>
#include <functional>
#include <vector>

#pragma once

template <class T> struct ConsumerWithPriority {
	std::function<void(T)> consumer;
	int priority;

	ConsumerWithPriority(const std::function<void(T)> &consumer, int priority)
		: consumer(consumer), priority(priority) {}
};

template <class T> class EventHandler {
  public:
	EventHandler() = default;
	~EventHandler() = default;

	void subscribe(const std::function<void(T)> &subscriber, int priority = 1) {
		subscribers.push_back(ConsumerWithPriority<T>(subscriber, priority));
	}

	void publish(T event) {
		std::sort(subscribers.begin(), subscribers.end(),
				  [](const ConsumerWithPriority<T> &a,
					 const ConsumerWithPriority<T> &b) {
					  return a.priority < b.priority;
				  });
		for (const auto &subscriber : subscribers)
			subscriber.consumer(event);
	}

  private:
	std::vector<ConsumerWithPriority<T>> subscribers;
};

#endif
