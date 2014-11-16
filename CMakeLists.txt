cmake_minimum_required(VERSION 2.8)
project(gulprun)

include(ExternalProject)


ExternalProject_Add(
    lua
    GIT_REPOSITORY https://github.com/LuaDist/lua.git
#    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lua
   
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=. -DBUILD_SHARED_LIBS:BOOL=OFF -DLUA_WIN:BOOL=OFF -DLUA_BUILD_WLUA:BOOL=OFF
#    LOG_DOWNLOAD 1 LOG_UPDATE 1 LOG_CONFIGURE 1 LOG_BUILD 1 LOG_INSTALL 1
)


ExternalProject_Get_Property(lua INSTALL_DIR)
ExternalProject_Get_Property(lua BINARY_DIR)

set(LUA_LIBRARIES ${BINARY_DIR}/lib)
set(LUA_INCLUDE_DIR ${BINARY_DIR}/include)

find_package(Lua REQUIRED) 

message("INSTALL_DIR=${INSTALL_DIR}")
message("BINARY_DIR=${BINARY_DIR}")
message("CMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX}")
message("LUA_FOUND=${LUA_FOUND}")
message("LUA_LIBRARIES=${LUA_LIBRARIES}")
message("LUA_INCLUDE_DIR=${LUA_INCLUDE_DIR}")    

include_directories(${BINARY_DIR} ${LUA_INCLUDE_DIR})

set(SRC src/main.c)

add_executable(gulprun ${SRC})
add_dependencies(gulprun lua)

if (WIN32 AND NOT CYGWIN AND NOT MINGW)
    target_link_libraries(gulprun ${LUA_LIBRARIES}/lua.lib)
else ()
    target_link_libraries(gulprun ${LUA_LIBRARIES}/liblua.a)
endif ()
