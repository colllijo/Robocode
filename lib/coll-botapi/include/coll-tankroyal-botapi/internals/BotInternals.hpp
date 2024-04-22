#ifndef COLL_TANKROYAL_BOTAPI_BOT_INTERNALS_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_INTERNALS_HPP

#include <cstdio>
#include <cstdlib>
#include <latch>
#include <memory>
#include <optional>
#include <string>

#include <fmt/base.h>

#include <ixwebsocket/IXWebSocket.h>

#include <nlohmann/json.hpp>

#include "../Bot.hpp"
#include "../BotInfo.hpp"
#include "../BotResult.hpp"
#include "../events/ConnectionEvents.hpp"
#include "../events/Events.hpp"
#include "../events/GameEvents.hpp"
#include "../events/Messages.hpp"
#include "./BotEventHandler.hpp"

#pragma once

class Bot;
class BotEventHandler;
class BotInternals {
public:
    BotInternals(Bot* bot, const BotInfo& botInfo,
        const std::string& serverUrl = std::string(),
        const std::string& serverSecret = std::string());
    ~BotInternals();

    void start();

    bool isRunning() const { return running; }
    void setRunning(bool running) { this->running = running; }

    void print(const std::string& msg);
    void printErr(const std::string& err);

private:
    constexpr static const fmt::string_view DEFAULT_SERVER_URL = "ws://localhost:7654";
    constexpr static const fmt::string_view SERVER_URL = "SERVER_URL";
    constexpr static const fmt::string_view SERVER_SECRET = "SERVER_SECRET";

    std::string serverURL;
    std::string serverSecret;

    ix::WebSocket webSocket;
    std::latch closedLatch;

    std::unique_ptr<BotInfo> botInfo;

    std::optional<int> id;

    const std::unique_ptr<BotEventHandler> botEventHandler;

    bool running;
    bool stopped;

    void initWebSocket();

    void onMessage(const ix::WebSocketMessagePtr& msg);

    void handleMessage(const nlohmann::json& message);
    void handleGameStarted(const nlohmann::json& message);
    void handleGameEnded(const nlohmann::json& message);
    void handleGameAborted(const nlohmann::json& message);
    void handleRoundStarted(const nlohmann::json& message);
    void handleServerHandshake(const nlohmann::json& message);

    void connect();

    static std::string getServerURLFromEnv()
    {
        const char* URL = getenv(SERVER_URL.data());
        if (URL == nullptr)
            URL = DEFAULT_SERVER_URL.data();

        return std::string(URL);
    };
    static std::string getServerSecretFromEnv()
    {
        const char* secret = getenv(SERVER_SECRET.data());

        if (secret != nullptr)
            return secret;
        return std::string();
    };
};

#endif
