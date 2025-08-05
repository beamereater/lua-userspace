#include "lua.h"
#include "lauxlib.h"
//#include <dirent.h>
#include <unistd.h>
#include <time.h>

int lclear(lua_State *l) {
	int ret = write(1,"\033[H\033[2J",8);
	lua_pushnumber(l,ret);
	return 1;
}

int lsleep(lua_State *l) {
	luaL_checknumber(l,1);
	usleep(lua_tonumber(l,1)*1000000);
	lua_pushnumber(l,0);
	return 1;
}

int lclock(lua_State *l) {
	lua_pushnumber(l,clock());
	return 1;
}

int lgettime(lua_State *l) {
	struct timespec tp;
	clock_gettime(0,&tp);
	double nsec = (double) tp.tv_sec;
	nsec += (double) tp.tv_nsec/1000000000.0;
	lua_pushnumber(l,nsec);
	return 1;
}

/*int lopendir(lua_State *l) { // planned for future, going to be used for ls
	luaL_checkstring(l,1);
	DIR* fd = opendir(lua_tostring(l,1));
	lua_pushnumber(l,fd);
	return 1;
}*/

const struct luaL_Reg func[] = {
	{"gettime",lgettime},
	{"clock",lclock},
	{"sleep",lsleep},
	{"clear",lclear},
	{NULL,NULL}
};

int luaopen_userspace(lua_State *L) {
	lua_pushnumber(L,CLOCKS_PER_SEC);
	lua_setglobal(L,"CLOCKS_PER_SEC");
	luaL_register(L,"_G",func);
	return 0;
}
