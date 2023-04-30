AC_PREREQ([2.71])
AC_INIT([Space-Invaders], [1.0])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_SRCDIR([Main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

have_sdl2=no
have_sdl2_image=no
have_sdl2_ttf=no

# Checks for libraries.
AC_SEARCH_LIBS([SDL_Init], [SDL2], [have_sdl2=yes])

if test "x${have_sdl2}" = xyes; then
    AC_CHECK_HEADERS([SDL.h], [], [have_sdl2=no])
fi

if test "x${have_sdl2}" = xno; then
    AC_MSG_ERROR([
    ---------------------------------------
    The SDL2 library and / or header files
    are not found, stopping...
    Check 'config.log' for more information
    ---------------------------------------])
fi

AC_SEARCH_LIBS([IMG_LoadTexture], [SDL2_image], [have_sdl2_image=yes])

if test "x${have_sdl2_image}" = xyes; then
    AC_CHECK_HEADERS([SDL_image.h], [], [have_sdl2_image=no])
fi

if test "x${have_sdl2_image}" = xno; then
    AC_MSG_ERROR([
    ---------------------------------------
    The SDL2_image library and / or header
    files are not found, stopping...
    Check 'config.log' for more information
    ---------------------------------------])
fi

AC_SEARCH_LIBS([TTF_Init], [SDL2_ttf], [have_sdl2_ttf=yes])

if test "x${have_sdl2_ttf}" = xyes; then
    AC_CHECK_HEADERS([SDL_ttf.h], [], [have_sdl2_ttf=no])
fi

if test "x${have_sdl2_ttf}" = xno; then
    AC_MSG_ERROR([
    ---------------------------------------
    The SDL2_ttf library and / or header
    files are not found, stopping...
    Check 'config.log' for more information
    ---------------------------------------])
fi

AC_OUTPUT
