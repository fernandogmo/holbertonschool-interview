#include "palindrome.h"

/**
 * is_palindrome - checks is unsigned long is a palindrome
 * @n: unsigned long integer to check
 * Return: 1 if palindrome else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, x = n;

	if (n < 10)
		return (1);
	do {
		rev = (rev * 10) + x % 10;
	} while (x /= 10);

	return (n == rev);
}
