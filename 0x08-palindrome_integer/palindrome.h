#ifndef PALINDROME_H
#define PALINDROME_H 1

/**
 * struct _qr - defines a divmod_t
 * @q: unsigned long quotient
 * @r: unsigned int remainder
 */
typedef struct _qr
{
	unsigned long q;
	unsigned int r;
} divmod_t;

void divmod(unsigned long, unsigned int, divmod_t *);
int is_palindrome(unsigned long);

#endif /* PALINDROME_H */
