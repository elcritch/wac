#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef
#define WAC_DEBUG 0
#endif

#ifndef
#define WAC_INFO 0
#endif

#ifndef
#define WAC_WARN 0
#endif

#ifndef
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

#endif // of UTIL_H
