#ifndef COLL_TANKROYAL_BOTAPI_EVENT_CONSUMER_HPP
#define COLL_TANKROYAL_BOTAPI_EVENT_CONSUMER_HPP

#pragma once

template <class T> class EventConsumer {
  public:
	void accept(T event);
};

#endif
