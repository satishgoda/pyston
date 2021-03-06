// This file is originally from CPython 2.7, with modifications for Pyston

#ifndef Py_PYDEBUG_H
#define Py_PYDEBUG_H
#ifdef __cplusplus
extern "C" {
#endif

PyAPI_DATA(int) Py_DebugFlag;
PyAPI_DATA(int) Py_VerboseFlag;
PyAPI_DATA(int) Py_InteractiveFlag;
PyAPI_DATA(int) Py_InspectFlag;
PyAPI_DATA(int) Py_OptimizeFlag;
PyAPI_DATA(int) Py_NoSiteFlag;
PyAPI_DATA(int) Py_BytesWarningFlag;
PyAPI_DATA(int) Py_UseClassExceptionsFlag;
PyAPI_DATA(int) Py_FrozenFlag;
PyAPI_DATA(int) Py_TabcheckFlag;
PyAPI_DATA(int) Py_UnicodeFlag;
PyAPI_DATA(int) Py_IgnoreEnvironmentFlag;
PyAPI_DATA(int) Py_DivisionWarningFlag;
PyAPI_DATA(int) Py_DontWriteBytecodeFlag;
PyAPI_DATA(int) Py_NoUserSiteDirectory;
/* _XXX Py_QnewFlag should go away in 3.0.  It's true iff -Qnew is passed,
  on the command line, and is used in 2.2 by ceval.c to make all "/" divisions
  true divisions (which they will be in 3.0). */
PyAPI_DATA(int) _Py_QnewFlag;
/* Warn about 3.x issues */
PyAPI_DATA(int) Py_Py3kWarningFlag;
PyAPI_DATA(int) Py_HashRandomizationFlag;

/* this is a wrapper around getenv() that pays attention to
   Py_IgnoreEnvironmentFlag.  It should be used for getting variables like
   PYTHONPATH and PYTHONHOME from the environment */
#define Py_GETENV(s) (Py_IgnoreEnvironmentFlag ? NULL : getenv(s))

// Pyston change: make Py_FatalError a macro so that it can access linenumber info, similar to assert:
//PyAPI_FUNC(void) Py_FatalError(const char *message) __attribute__((__noreturn__));
#define _STRINGIFY(N) #N
#define STRINGIFY(N) _STRINGIFY(N)
#define Py_FatalError(message)                                                                                          \
do {                                                                                                                    \
    fprintf(stderr, __FILE__ ":" STRINGIFY(__LINE__) ": %s: Fatal Python error: %s\n", __PRETTY_FUNCTION__, message);   \
    abort();                                                                                                            \
} while (0)

#ifdef __cplusplus
}
#endif
#endif /* !Py_PYDEBUG_H */
