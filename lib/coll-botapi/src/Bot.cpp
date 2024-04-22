#include "Bot.hpp"

Bot::Bot(const BotInfo& botInfo, const std::string& serverURL,
    const std::string& serverSecret)
    : internals(std::make_unique<BotInternals>(this, botInfo, serverURL,
          serverSecret))
{
}

Bot::~Bot() = default;

void Bot::start() { internals->start(); }

void Bot::onConnected(const Events::Connection::ConnectedEvent& event)
{
    internals->print(fmt::format("Connected to: {}\n", event.serverURL));
}

void Bot::onDisconnected(const Events::Connection::DisconnectedEvent& event)
{
    std::string msg = fmt::format("Disconnected from: {}", event.serverURL);
    if (event.statusCode.has_value())
        msg.append(fmt::format(", status code: {}", event.statusCode.value()));
    if (event.reason.has_value())
        msg.append(fmt::format(", reason: {}", event.reason.value()));

    internals->print(msg.append("\n"));
}

void Bot::onConnectionError(
    const Events::Connection::ConnectionErrorEvent& event)
{
    internals->printErr(fmt::format("Connection error with {}, reason {}\n",
        event.serverURL, event.error));
}
