#include "hash.h"
#include <stack.h>
#include <stdlib.h>

uint32_t oat_hash(void *s, size_t len)
{
    unsigned char *p = (unsigned char *)s;

    uint32_t h = 0;

    while(len--) {
        h += *p++;
        h += (h << 10);
        h ^= (h >> 6);
    }

    h += (h << 3);
    h ^= (h >> 11);
    h += (h << 15);

    return h;
}

