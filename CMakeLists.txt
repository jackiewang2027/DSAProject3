cmake_minimum_required(VERSION 3.16)
project(DSAProject3 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(DSAProject3
        src/star.cpp
        src/star.h
        src/main_interface.cpp
        src/main.cpp
        src/WelcomeScreen.h
        src/PlayScreen.h
        src/SortVisualizationScreen.h)
target_link_libraries(DSAProject3 PRIVATE sfml-graphics sfml-audio)
target_compile_features(DSAProject3 PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET DSAProject3
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:DSAProject3>
        VERBATIM)
endif()

install(TARGETS DSAProject3)
