#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef POSIX
#include "debug_posix.h"
#else
#include "debug_posix.h"
#endif

#ifndef WAC_DEBUG
#define WAC_DEBUG 0
#endif

#ifndef WAC_INFO
#define WAC_INFO 0
#endif

#ifndef WAC_WARN
#define WAC_WARN 0
#endif

#ifndef WAC_TRACE
#define WAC_TRACE 0
#endif

uint64_t read_LEB(uint8_t *bytes, uint32_t *pos, uint32_t maxbits);
uint64_t read_LEB_signed(uint8_t *bytes, uint32_t *pos, uint32_t maxbits);

uint32_t read_uint32(uint8_t *bytes, uint32_t *pos);

char *read_string(uint8_t *bytes, uint32_t *pos, uint32_t *result_len);

uint8_t *mmap_file(char *path, uint32_t *len);

void *acalloc(size_t nmemb, size_t size, char *name);
void *arecalloc(void *ptr, size_t old_nmemb, size_t nmemb, size_t size,
                char *name);
char **split_string(char *str, int *count);

// Math
void sext_8_32(uint32_t *val);
void sext_16_32(uint32_t *val);
void sext_8_64(uint64_t *val);
void sext_16_64(uint64_t *val);
void sext_32_64(uint64_t *val);
uint32_t rotl32(uint32_t n, unsigned int c);
uint32_t rotr32(uint32_t n, unsigned int c);
uint64_t rotl64(uint64_t n, unsigned int c);
uint64_t rotr64(uint64_t n, unsigned int c);
double wa_fmax(double a, double b);
double wa_fmin(double a, double b);

// Dynamic lib resolution
bool resolvesym(char *filename, char *symbol, void **val, char **err);

// Error handling stuff
enum exceptions {
    EX_CALL_SIG_MISMATCH = 0,
    EX_UNREACHABLE,
    EX_UNDEFINED_ELEMENT,
    EX_INDIRECT_CALL_SIGNATURE_MISMATCH,
    EX_OUT_OF_BOUNDS_MEMORY_ACCESS,
    EX_DIV_BY_ZERO,
    EX_INTEGER_OVERFLOW,
    EX_UNKNOWN_OPCODE,
    EX_INVALID_CONVERSION_TO_INT,
};

void exception(enum exceptions id);
void exception_arg(enum exceptions id, long arg);
char *exception_msg();

#endif // of UTIL_H
