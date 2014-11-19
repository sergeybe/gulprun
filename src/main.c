#include <stdlib.h>
#include <stdio.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "gulprun.h"

void die(lua_State *L, char *msg){
    fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n",
        msg, lua_tostring(L, -1));
    exit(EXIT_FAILURE);
}


int main(int argc, char **argv)
{
    char *script_name = NULL;
    int i;

    for (i = 1; argv[i] != NULL; i++) {
        if (argv[i][0] != '-') {
            script_name = argv[i];
            break;
	}
    }

    if (script_name == NULL) {
        fprintf(stderr, "\nFATAL ERROR:\n  Please specify filename of script!\n\n");
	exit(EXIT_FAILURE);
    }

    lua_State *L;

    L = luaL_newstate();

    if (L == NULL) {
	die(L, "luaL_newstate() failed");
    }

    luaL_openlibs(L);

    luaopen_gulprun(L);

    if (luaL_loadfile(L, script_name)) {
	die(L, "luaL_loadfile() failed");
    }

    if (lua_pcall(L, 0, 0, 0)) {
	die(L, "lua_pcall() failed");
    }

    lua_close(L);

    return EXIT_SUCCESS;
}
