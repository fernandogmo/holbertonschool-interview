#ifndef _LISTS_H_
#define _LISTS_H_

#include <stddef.h>


#ifndef DEBUG
#define RELEASE 0
#endif

#define RED	"\033[0;31m"
#define BLUE    "\033[0;34m"
#define GREEN   "\033[0;32m"
#define GRAY    "\033[1;30m"
#define WHITE   "\033[1;37m"
#define GRAY    "\033[1;30m"
#define NC	"\033[0m"

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);

listint_t *find_listint_loop(listint_t *head);

/* Utility nacros */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvariadic-macros"

#ifndef C99
#define C99(...)                \
do {                        \
_Pragma("GCC diagnostic push")          \
_Pragma("GCC diagnostic ignored \"-Wpedantic\"")\
_Pragma("GCC diagnostic ignored \"-Wvla\"") \
    __VA_ARGS__             \
_Pragma("GCC diagnostic pop")           \
} while (0)
#endif /* C99 */

#ifndef DBG
#if !RELEASE
#include <stdio.h>
#define DBG(...)            \
C99(do {                \
printf("%s:%d: ", __func__, __LINE__);  \
    __VA_ARGS__;            \
} while (0);)
#else
#define DBG(...)
#endif
#endif

#pragma GCC diagnostic pop

#define FMT "%6.3f"
#define QUADCOLORS(x,y,w,h,c1,c2,c3,c4) \
	((x < w/2) ? ((y < h/2) ? c1 FMT NC : c3 FMT NC) \
		   : ((y < h/2) ? c2 FMT NC : c4 FMT NC))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ROUND(a) ((a > 0) ? (uint_fast32_t)(a + 0.5f) : (uint_fast32_t)(a - 0.5f))
#define FPTOLERANCE 0.00001f
#define EQUALISH(a, b) (((a) - FPTOLERANCE) < b && ((a) + FPTOLERANCE) > b)

#endif /* _LISTS_H_ */
