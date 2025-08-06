# Lua Userspace
Attempts to add functions needed for GNU/Posix userspace utilities into Lua 5.1
# Compile
To compile, run this command:
```make -j$(nproc) PLAT```
where PLAT is the platform you are compiling for. (linux,freebsd,bsd,solaris,posix,mingw,macosx,generic,aix,ansi)
# Install
To install, run this command:
```doas make install```
Replace `doas` with `sudo` if you use sudo.
# WORK IN PROGRESS!!
This project is a work in progress!
