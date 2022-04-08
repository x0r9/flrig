AC_DEFUN([AC_FLRIG_NP_COMPAT], [
  AC_REQUIRE([AC_FL_MACOSX])
  AC_REQUIRE([AC_FL_WIN32])

  if test "x$target_mingw32" = "xyes"; then
      sem_libs="pthreadGC2"
  else
      sem_libs="pthread rt"
  fi
  other_libs=""

  if test "x$ac_cv_want_ptw32" = "xyes"; then
      CFLAGS_saved="$CFLAGS"
      LDFLAGS_saved="$LDFLAGS"
      EXTRA_LIBS_saved="$EXTRA_LIBS"
      CFLAGS="$CFLAGS $PTW32_CFLAGS"
      LDFLAGS="$LDFLAGS $PTW32_LIBS"
      other_libs=-lws2_32
  fi

  AC_FLRIG_SEARCH_LIBS([dlopen], [dl], [$other_libs])
  AC_FLRIG_SEARCH_LIBS([clock_gettime], [rt], [$other_libs])
  AC_FLRIG_SEARCH_LIBS([sem_unlink], [$sem_libs], [$other_libs])
  AC_FLRIG_SEARCH_LIBS([sem_timedwait], [$sem_libs], [$other_libs])

  if test "x$ac_cv_want_ptw32" = "xyes"; then
      CFLAGS="$CFLAGS_saved"
      LDFLAGS="$LDFLAGS_saved"
      EXTRA_LIBS="$EXTRA_LIBS_saved"
  fi
  AC_SUBST([EXTRA_LIBS])

  AM_CONDITIONAL([COMPAT_STRCASESTR], [test "x$ac_cv_func_strcasestr" != "xyes"])
])
