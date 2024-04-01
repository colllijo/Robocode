#include "BotInfo.hpp"

BotInfo::BotInfo(const std::string &name, const std::string &version,
				 const std::vector<std::string> &authors,
				 const std::string &description, const std::string &homepage,
				 const std::vector<std::string> &countryCodes,
				 const std::set<std::string> &gameTypes,
				 const std::string &platform,
				 const std::string &programmingLang)
	: name(processName(name)), version(processVersion(version)),
	  authors(processAuthors(authors)),
	  description(processDescription(description)),
	  homepage(processHomepage(homepage)),
	  countryCodes(processCountryCodes(countryCodes)),
	  gameTypes(processGameTypes(gameTypes)),
	  platform(processPlatform(platform)),
	  programmingLang(processProgrammingLang(programmingLang)) {}

BotInfo::~BotInfo() = default;

std::string BotInfo::processName(const std::string &name) {
	if (name.empty())
		throw std::invalid_argument("Property \"name\" cannot be empty.");

	if (name.size() > MAX_NAME_LENGTH)
		throw std::invalid_argument(fmt::format(
			"Property \"name\" length exceeds the maximum of {} charcters",
			MAX_NAME_LENGTH));

	return name;
}

std::string BotInfo::processVersion(const std::string &version) {
	if (version.empty())
		throw std::invalid_argument("Property \"version\" cannot be empty.");

	if (version.size() > MAX_VERSION_LENGTH)
		throw std::invalid_argument(fmt::format(
			"Property \"version\" length exceeds the maximum of {} charcters",
			MAX_VERSION_LENGTH));

	return version;
}

std::vector<std::string>
BotInfo::processAuthors(const std::vector<std::string> &authors) {
	if (authors.empty() ||
		std::accumulate(authors.begin(), authors.end(), std::string(""))
			.empty())
		throw std::invalid_argument("Property \"authors\" cannot be empty.");

	if (authors.size() > MAX_NUMBER_OF_AUTHORS)
		throw std::invalid_argument(fmt::format(
			"Size of property \"authors\" exceeds the maximum of {}",
			MAX_NUMBER_OF_AUTHORS));

	for (const auto &author : authors) {
		if (author.size() > MAX_AUTHOR_LENGTH)
			throw std::invalid_argument(
				fmt::format("Property \"author\" lenght exceeds the maximum of "
							"{} characters.",
							MAX_AUTHOR_LENGTH));
	}

	return authors;
}

std::string BotInfo::processDescription(const std::string &description) {
	if (description.size() > MAX_DESCRIPTION_LENGTH)
		throw std::invalid_argument(
			fmt::format("Property \"description\" length exceeds the maximum "
						"of {} charcters",
						MAX_DESCRIPTION_LENGTH));

	return description;
}

std::string BotInfo::processHomepage(const std::string &homepage) {
	if (homepage.size() > MAX_HOMEPAGE_LENGTH)
		throw std::invalid_argument(fmt::format(
			"Property \"homepage\" length exceeds the maximum of {} charcters",
			MAX_HOMEPAGE_LENGTH));

	return homepage;
}

std::vector<std::string>
BotInfo::processCountryCodes(const std::vector<std::string> &countryCodes) {
	if (countryCodes.size() > MAX_NUMBER_OF_COUNTRY_CODES)
		throw std::invalid_argument(fmt::format(
			"Size of Property \"countryCodes\" exceeds maximum of {}.",
			MAX_NUMBER_OF_COUNTRY_CODES));

	return countryCodes;
}

std::set<std::string>
BotInfo::processGameTypes(const std::set<std::string> &gameTypes) {
	if (gameTypes.size() > MAX_NUMBER_OF_GAME_TYPES)
		throw std::invalid_argument(
			fmt::format("Size of Property \"gameTypes\" exceeds maximum of {}.",
						MAX_NUMBER_OF_GAME_TYPES));

	for (const auto &gameType : gameTypes) {
		if (gameType.size() > MAX_GAME_TYPE_LENGTH)
			throw std::invalid_argument(
				fmt::format("Property \"gameType\" length exceeds maximum of "
							"{} characters.",
							MAX_GAME_TYPE_LENGTH));
	}

	return gameTypes;
}

std::string BotInfo::processPlatform(const std::string &platform) {
	if (platform.size() > MAX_PLATFORM_LENGTH)
		throw std::invalid_argument(fmt::format(
			"Property \"platform\" length exceeds the maximum of {} charcters",
			MAX_PLATFORM_LENGTH));

	return platform;
}

std::string
BotInfo::processProgrammingLang(const std::string &programmingLang) {
	if (programmingLang.size() > MAX_PROGRAMMING_LANG_LENGTH)
		throw std::invalid_argument(
			fmt::format("Property \"programmingLang\" length exceeds the "
						"maximum of {} charcters",
						MAX_PROGRAMMING_LANG_LENGTH));

	return programmingLang;
}

BotInfo BotInfo::fromFile(const std::string &file) {
	std::ifstream infoFile(file);

	if (infoFile)
		return fromStream(infoFile);
	else
		throw std::invalid_argument("File not found.");
}

BotInfo BotInfo::fromStream(std::ifstream &stream) {
	auto data = nlohmann::json::parse(stream);

	if (!data.contains("name"))
		throw std::invalid_argument("Property \"name\" required for BotInfo.");

	if (!data.contains("version"))
		throw std::invalid_argument(
			"Property \"version\" required for BotInfo.");
	if (!data.contains("authors"))
		throw std::invalid_argument(
			"Property \"authors\" required for BotInfo.");

	return BotInfo(data.value("name", std::string{}),
				   data.value("version", std::string{}),
				   data.value("authors", std::vector<std::string>{}),
				   data.value("description", std::string{}),
				   data.value("homepage", std::string{}),
				   data.value("countryCodes", std::vector<std::string>{}),
				   data.value("gameTypes", std::set<std::string>{}),
				   data.value("platform", std::string{}),
				   data.value("programmingLang", std::string{}));
}
