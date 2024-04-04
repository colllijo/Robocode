#ifndef COLL_TANKROYAL_BOTAPI_CONNECTION_EVENTS_HPP
#define COLL_TANKROYAL_BOTAPI_CONNECTION_EVENTS_HPP

#include "Events.hpp"
#include <optional>
#include <string>

#pragma once

namespace Events {
namespace Connection {
struct ConnectionEvent {
	const Type type;
	const std::string serverURL;

	ConnectionEvent(const Type &type, const std::string serverURL)
		: type(type), serverURL(serverURL) {}
};

struct ConnectedEvent : public ConnectionEvent {
	ConnectedEvent(const std::string serverURL)
		: ConnectionEvent(Type::Connected, serverURL) {}
};

struct ConnectionErrorEvent : public ConnectionEvent {
	const std::exception error;

	ConnectionErrorEvent(const std::string serverURL,
						 const std::exception &error)
		: ConnectionEvent(Type::ConnectionError, serverURL), error(error) {}
};

struct DisconnectedEvent : public ConnectionEvent {
	const bool remote;
	const std::optional<int> statusCode;
	const std::optional<std::string> reason;

	DisconnectedEvent(const std::string serverURL, bool remote,
					  const std::optional<int> &statusCode,
					  const std::optional<std::string> &reason)
		: ConnectionEvent(Type::Disconnected, serverURL), remote(remote),
		  statusCode(statusCode), reason(reason) {}
};
}; // namespace Connection

}; // namespace Events

#endif
