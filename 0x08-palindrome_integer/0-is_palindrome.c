#include "palindrome.h"

/**
 * is_palindrome - checks is unsigned long is a palindrome
 * @n: unsigned long integer to check
 * Return: 1 if palindrome else 0
 */
int is_palindrome(unsigned long n)
{
	divmod_t qr;
	unsigned long i = 0, y = 0, x = n;

	if (n < 10)
		return (1);

	while (x && ++i)
	{
		divmod(x, 10, &qr);
		y = (y * 10) + qr.r;
		x = qr.q;
	}
	while (--i && (n % 10) == (y % 10))
	{
		n /= 10;
		y /= 10;
	}
	return (i == 0);
}

/**
 * divmod - updates @qr with the quotient and remainder of @n and @d
 * @n: unsigned long dividend.
 * @d: unsigned int divisor.
 * @qr: pointer to divmod_t to update with values.
 */
void divmod(unsigned long n, unsigned int d, divmod_t *qr)
{
	qr->q = n / d;
	qr->r = n - (qr->q * 10);
}
