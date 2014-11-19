#ifndef GULPRUN_H
#define GULPRUN_H

#define LUA_LIB
#include <lua.h>
#include <lauxlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>


#define LUA_GULPRUNLIBNAME "gulp"

LUAMOD_API int (luaopen_gulprun) (lua_State *L);


#endif