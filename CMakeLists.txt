cmake_minimum_required(VERSION 3.2)

project(bulk VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

add_executable(bulk bulk.cpp
	Application.cpp
	CommandBlock.cpp
	LineProcessor.cpp
	Observer.cpp
)

set_target_properties(bulk PROPERTIES
	CXX_STANDART 14
	CXX_STANDART_REQUIRED ON
	COMPILE_OPTION -Wpedantic -Wall -Wextra
)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT erkinvs@gmail.com)

include(CPack)