AC_PREREQ([2.71])
AC_INIT([Space-Invaders], [1.0])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_SRCDIR([Main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_SEARCH_LIBS([SDL_Init], [SDL2], [], [echo "SDL2 library not found"; exit])
AC_SEARCH_LIBS([IMG_LoadTexture], [SDL2_image], [], [echo "SDL2_image library not found"; exit])
AC_SEARCH_LIBS([TTF_Init], [SDL2_ttf], [], [echo "SDL2_ttf library not found"; exit])

AC_OUTPUT
