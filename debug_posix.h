#ifndef DEBUG_POSIX_H
#define DEBUG_POSIX_H

#include <dlfcn.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define WAC_DEBUG 0
#define WAC_INFO 0
#define WAC_WARN 0
#define WAC_TRACE 0

#define FATAL(...)                                                             \
    {                                                                          \
        fprintf(stderr, "Error(%s:%d): ", __FILE__, __LINE__);                 \
        fprintf(stderr, __VA_ARGS__);                                          \
        exit(1);                                                               \
    }

#define ASSERT(exp, ...)                                                       \
    {                                                                          \
        if (!(exp)) {                                                          \
            fprintf(stderr, "Assert Failed (%s:%d): ", __FILE__, __LINE__);    \
            fprintf(stderr, __VA_ARGS__);                                      \
            exit(1);                                                           \
        }                                                                      \
    }

#if WAC_TRACE
#define TRACE(...) fprintf(stderr, __VA_ARGS__);
#else
#define TRACE(...) ;
#endif

#if WAC_DEBUG
#define DEBUG(...) fprintf(stderr, __VA_ARGS__);
#else
#define DEBUG(...) ;
#endif

#if WAC_INFO
#define INFO(...) fprintf(stderr, __VA_ARGS__);
#else
#define INFO(...) ;
#endif

#if WAC_WARN
#define WARN(...) fprintf(stderr, __VA_ARGS__);
#else
#define WARN(...) ;
#endif

#define LOG(...) fprintf(stderr, __VA_ARGS__);

#define ERROR(...) fprintf(stderr, __VA_ARGS__);

// Dynamic lib resolution
bool resolvesym(char *filename, char *symbol, void **val, char **err);

#endif // of UTIL_H
