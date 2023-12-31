cmake_minimum_required(VERSION 3.16)
project(RaptorsGameOfLife LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${CMAKE_SOURCE_DIR}/include)


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(RaptorsGameOfLife src/main.cpp "src/Cell.cpp" "src/Grid.cpp" "src/Game.cpp")
target_link_libraries(RaptorsGameOfLife PRIVATE sfml-graphics)
target_compile_features(RaptorsGameOfLife PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET RaptorsGameOfLife
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:RaptorsGameOfLife>
        VERBATIM)
endif()

install(TARGETS RaptorsGameOfLife)
