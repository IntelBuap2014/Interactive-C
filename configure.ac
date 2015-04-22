#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Interactive-C], [1.0], [edilberto.huerta0290@gmail.com])
AC_CONFIG_SRCDIR([src/interfaces])
AC_CONFIG_SRCDIR([src/controlador])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_INIT_AUTOMAKE

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([gtk-3.0/gtk/gtk.h arpa/inet.h libintl.h locale.h netdb.h netinet/in.h stdlib.h string.h sys/socket.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([inet_ntoa memset select setlocale socket])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
