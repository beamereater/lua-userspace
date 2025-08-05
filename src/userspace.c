#include "lua.h"
#include "lauxlib.h"
#include <unistd.h>

int lclear(lua_State *l) {
	write(1,"\033[H\033[2J",8);
	return 0;
}

const struct luaL_Reg func[] = {
	{"clear",lclear},
	{NULL,NULL}
};

int luaopen_userspace(lua_State *L) {
	luaL_register(L,"_G",func);
	return 0;
}
