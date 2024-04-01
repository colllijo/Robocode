#ifndef COLL_TANKROYAL_BOTAPI_CONNECTION_EVENT_HPP
#define COLL_TANKROYAL_BOTAPI_CONNECTION_EVENT_HPP

#include <string>

#pragma once

class ConnectionEvent {
  public:
	std::string getServerURL() const { return serverURL; }

  protected:
	ConnectionEvent(const std::string serverURL) : serverURL(serverURL) {}

  private:
	const std::string serverURL;
};

#endif
