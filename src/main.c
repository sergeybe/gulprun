#include <stdlib.h>
#include <stdio.h>

#include "lua.h"
#include <lauxlib.h>
#include <lualib.h>

void die(lua_State *L, char *msg){
	fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n",
		msg, lua_tostring(L, -1));
	exit(1);
}

int main(void)
{
    lua_State *L;

    L = luaL_newstate();

    luaL_openlibs(L);

    if (luaL_loadfile(L, "hello.lua")) {
	die(L, "luaL_loadfile() failed");
    }

    if (lua_pcall(L, 0, 0, 0)) {
	die(L, "lua_pcall() failed");
    }

    lua_close(L);

    return 0;
}
