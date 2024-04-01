#ifndef COLL_TANKROYAL_BOTAPI_BOT_INTERNALS_HPP
#define COLL_TANKROYAL_BOTAPI_BOT_INTERNALS_HPP

#include <cstdlib>
#include <memory>
#include <optional>
#include <string>

#include <fmt/base.h>

#include <ixwebsocket/IXWebSocket.h>

#include <nlohmann/json.hpp>

#include "../BotInfo.hpp"
#include "../message/Message.hpp"

#pragma once

class BotInternals {
  public:
	BotInternals(const BotInfo &botInfo,
				 const std::string &serverUrl = std::string(),
				 const std::string &serverSecret = std::string());
	~BotInternals();

	void start();

	bool isRunning() const { return running; }
	void setRunning(bool running) { this->running = running; }

  private:
	constexpr static const fmt::string_view DEFAULT_SERVER_URL =
		"ws://localhost:7654";
	constexpr static const fmt::string_view SERVER_URL = "SERVER_URL";
	constexpr static const fmt::string_view SERVER_SECRET = "SERVER_SECRET";

	std::string serverURL;
	std::string serverSecret;

	ix::WebSocket webSocket;

	std::unique_ptr<BotInfo> botInfo;

	std::optional<int> id;
	bool running;

	void initWebSocket();

	void onMessage(const ix::WebSocketMessagePtr &msg);

	void handleMessage(const nlohmann::json &message);
	void handleServerHandshake(const nlohmann::json &message);

	void connect();

	static std::string getServerURLFromEnv() {
		const char *URL = getenv(SERVER_URL.data());
		if (URL == nullptr)
			URL = DEFAULT_SERVER_URL.data();

		return std::string(URL);
	};
	static std::string getServerSecretFromEnv() {
		return getenv(SERVER_SECRET.data());
	};
};

#endif
