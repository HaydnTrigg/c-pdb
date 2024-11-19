#pragma once
#include <stdint.h>
#include <stdio.h>

#define DYNARRAY_PUSH(array, count, element)                          \
    do                                                                \
    {                                                                 \
        (count)++;                                                    \
        (array) = realloc((array), (count) * sizeof(element));        \
        assert(array);                                                \
        memcpy((array) + ((count) - 1), &(element), sizeof(element)); \
    } while (0)

__attribute__((__format__(__printf__, 3, 4))) void fprintf_depth(FILE *stream, uint32_t depth, char *fmt, ...);
