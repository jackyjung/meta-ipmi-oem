cmake_minimum_required(VERSION 3.5)
project(ves-oem-ipmi LANGUAGES CXX)
find_package(PkgConfig REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#pkg_check_modules(IPMI REQUIRED phosphor-ipmi-host)
pkg_check_modules(SDBUSPLUS REQUIRED sdbusplus)
pkg_check_modules(LOGGING REQUIRED phosphor-logging)

find_path(IPMI_INCLUDE_DIR ipmid/api.hpp)
if(NOT IPMI_INCLUDE_DIR)
    message(FATAL_ERROR "phosphor-ipmi-host headers not found")
endif()

add_library(ves_oem_cmd MODULE ves_oem_cmd.cpp)
target_include_directories(ves_oem_cmd PRIVATE
    ${IPMI_INCLUDE_DIRS}
    ${SDBUSPLUS_INCLUDE_DIRS}
    ${LOGGING_INCLUDE_DIRS}
)
target_link_libraries(ves_oem_cmd
    ${IPMI_LIBRARIES}
    ${SDBUSPLUS_LIBRARIES}
    ${LOGGING_LIBRARIES}
)
set_target_properties(ves_oem_cmd PROPERTIES
    PREFIX ""
    OUTPUT_NAME "libves_oem_cmd"
)
install(TARGETS ves_oem_cmd
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/ipmid-providers
)

