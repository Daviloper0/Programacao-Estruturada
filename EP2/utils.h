#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

void *malloc_safe(size_t tamanho);
void *realloc_safe(void *ptr, size_t tamanho);

#endif