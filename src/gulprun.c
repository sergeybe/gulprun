#include <stdlib.h>

#define LUA_LIB
#include <lua.h>

#include "gulprun.h"

#define VERSION "0.0.1"

static int gulprun_version(lua_State *L) {
    const char *s;
    lua_pushstring(L, VERSION);
    return 1;
}

static const luaL_Reg gulprunlib[] = {
    {"version", gulprun_version},
    {NULL, NULL}
};

LUAMOD_API int luaopen_gulprun (lua_State *L) {
   luaL_openlib(L, LUA_GULPRUNLIBNAME, gulprunlib, 0);

    return 1;
}

