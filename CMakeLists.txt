cmake_minimum_required(VERSION 3.10)
project(ObserverPattern)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/include)

add_library(weather STATIC
    src/weatherdata.cpp
    src/currentconditiondisplay.cpp
)

add_executable(weather_app app/main.cpp)
target_link_libraries(weather_app weather)

enable_testing()
add_executable(test_observer tests/test_observer.cpp)
add_executable(test_subject tests/test_subject.cpp)
add_executable(test_weatherdata tests/test_weatherdata.cpp)
add_executable(test_currentconditiondisplay tests/test_currentconditiondisplay.cpp)
target_link_libraries(test_observer weather)
target_link_libraries(test_subject weather)
target_link_libraries(test_weatherdata weather)
target_link_libraries(test_currentconditiondisplay weather)

add_test(NAME ObserverTest COMMAND test_observer)
add_test(NAME SubjectTest COMMAND test_subject)
add_test(NAME WeatherDataTest COMMAND test_weatherdata)
add_test(NAME DisplayTest COMMAND test_currentconditiondisplay)

include(InstallRequiredSystemLibraries)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "weatherapp")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "maintainer")
install(TARGETS weather_app DESTINATION bin)
include(CPack)
