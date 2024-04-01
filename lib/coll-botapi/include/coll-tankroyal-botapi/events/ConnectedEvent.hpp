#ifndef COLL_TANKROYAL_BOTAPI_CONNECTED_EVENT_HPP
#define COLL_TANKROYAL_BOTAPI_CONNECTED_EVENT_HPP

#include "ConnectionEvent.hpp"

#pragma once

class ConnectedEvent : public ConnectionEvent {
  public:
	ConnectedEvent(const std::string serverURL) : ConnectionEvent(serverURL) {}
};

#endif
