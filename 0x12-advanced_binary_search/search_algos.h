#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdlib.h>

#define SZ_NEW_U ((u = m) - l + 1)
#define SZ_NEW_L (u - (l = m + 1) + 1)
#define RESET_STATICS (u = l = 0)

int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
