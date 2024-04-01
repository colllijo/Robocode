#ifndef COLL_TANKROYAL_BOTAPI_BOTINFO_HPP
#define COLL_TANKROYAL_BOTAPI_BOTINFO_HPP

#include <fstream>
#include <set>
#include <string>
#include <vector>

#include <fmt/core.h>

#include <nlohmann/json.hpp>

#pragma once

class BotInfo {
  public:
	constexpr static const int MAX_NAME_LENGTH = 30;
	constexpr static const int MAX_VERSION_LENGTH = 20;
	constexpr static const int MAX_AUTHOR_LENGTH = 50;
	constexpr static const int MAX_DESCRIPTION_LENGTH = 250;
	constexpr static const int MAX_HOMEPAGE_LENGTH = 150;
	constexpr static const int MAX_GAME_TYPE_LENGTH = 20;
	constexpr static const int MAX_PLATFORM_LENGTH = 30;
	constexpr static const int MAX_PROGRAMMING_LANG_LENGTH = 30;
	constexpr static const int MAX_NUMBER_OF_AUTHORS = 5;
	constexpr static const int MAX_NUMBER_OF_COUNTRY_CODES = 5;
	constexpr static const int MAX_NUMBER_OF_GAME_TYPES = 10;

	BotInfo(const std::string &name, const std::string &version,
			const std::vector<std::string> &authors,
			const std::string &description, const std::string &homepage,
			const std::vector<std::string> &countryCodes,
			const std::set<std::string> &gameTypes, const std::string &platform,
			const std::string &programmingLang);
	~BotInfo();

	static BotInfo fromFile(const std::string &file);
	static BotInfo fromStream(std::ifstream &stream);

	std::string getName() const { return name; }
	std::string getVersion() const { return version; }
	std::vector<std::string> getAuthors() const { return authors; }
	std::string getDescription() const { return description; }
	std::string getHomepage() const { return homepage; }
	std::vector<std::string> getCountryCodes() const { return countryCodes; }
	std::set<std::string> getGametypes() const { return gameTypes; }
	std::string getPlatform() const { return platform; }
	std::string getProgrammingLang() const { return programmingLang; }

	std::string processName(const std::string &name);
	std::string processVersion(const std::string &version);
	std::vector<std::string>
	processAuthors(const std::vector<std::string> &authors);
	std::string processDescription(const std::string &description);
	std::string processHomepage(const std::string &homepage);
	std::vector<std::string>
	processCountryCodes(const std::vector<std::string> &countryCodes);
	std::set<std::string>
	processGameTypes(const std::set<std::string> &gameTypes);
	std::string processPlatform(const std::string &platform);
	std::string processProgrammingLang(const std::string &programmingLang);

  private:
	// Required fields.
	std::string name;
	std::string version;
	std::vector<std::string> authors;
	// Optional fields.
	std::string description;
	std::string homepage;
	std::vector<std::string> countryCodes;
	std::set<std::string> gameTypes;
	std::string platform;
	std::string programmingLang;
	// Optional special fields.
	// Initial position
};

#endif
