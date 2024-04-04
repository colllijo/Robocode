cmake_minimum_required(VERSION 3.22)

project(CollTankRoyalBotAPILibrary)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(LIBRARY_NAME coll-tankroyal-botapi)
set(LIBRARY_HEADERS_DIR include/${LIBRARY_NAME})
set(LIBRARY_HEADERS
	${LIBRARY_HEADERS_DIR}/events/BotEvents.hpp
	${LIBRARY_HEADERS_DIR}/events/ConnectionEvents.hpp
	${LIBRARY_HEADERS_DIR}/events/Events.hpp
	${LIBRARY_HEADERS_DIR}/events/GameEvents.hpp
	${LIBRARY_HEADERS_DIR}/events/Messages.hpp
	${LIBRARY_HEADERS_DIR}/internals/BotEventHandler.hpp
	${LIBRARY_HEADERS_DIR}/internals/BotInternals.hpp
	${LIBRARY_HEADERS_DIR}/internals/EventHandler.hpp
	${LIBRARY_HEADERS_DIR}/Bot.hpp
	${LIBRARY_HEADERS_DIR}/BotInfo.hpp
	${LIBRARY_HEADERS_DIR}/BotResult.hpp
	${LIBRARY_HEADERS_DIR}/BotState.hpp
	${LIBRARY_HEADERS_DIR}/BulletState.hpp
	${LIBRARY_HEADERS_DIR}/Color.hpp
	${LIBRARY_HEADERS_DIR}/GameSetup.hpp
)
set(LIBRARY_SOURCES_DIR src)
set(LIBRARY_SOURCES
	${LIBRARY_SOURCES_DIR}/internals/BotInternals.cpp
	${LIBRARY_SOURCES_DIR}/internals/BotEventHandler.cpp
	${LIBRARY_SOURCES_DIR}/Bot.cpp
	${LIBRARY_SOURCES_DIR}/BotInfo.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/src$
)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCES})
target_include_directories(
	${LIBRARY_NAME}
	PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}> $<INSTALL_INTERFACE:include/${LIBRARY_NAME}/>
	PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}/events> $<INSTALL_INTERFACE:include/${LIBRARY_NAME}/events/>
	PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}/internals> $<INSTALL_INTERFACE:include/${LIBRARY_NAME}/internals/>
	PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}/message> $<INSTALL_INTERFACE:include/${LIBRARY_NAME}/message/>
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)
target_link_libraries(${LIBRARY_NAME} PRIVATE fmt::fmt nlohmann_json::nlohmann_json ixwebsocket::ixwebsocket)
