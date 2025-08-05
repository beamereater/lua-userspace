#include "lua.h"
#include "lauxlib.h"
#include <dirent.h>
#include <unistd.h>

int lclear(lua_State *l) {
	write(1,"\033[H\033[2J",8);
	return 0;
}

int lopendir(lua_State *l) {
	luaL_checkstring(l,1);
	DIR* fd = opendir(lua_tostring(l,1));
	lua_pushnumber(l,fd);
	return 1;
}

const struct luaL_Reg func[] = {
	{"clear",lclear},
	{NULL,NULL}
};

int luaopen_userspace(lua_State *L) {
	luaL_register(L,"_G",func);
	return 0;
}
