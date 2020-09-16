int nth(unsigned digit, unsigned long n)
{
	unsigned i = 1;

	while (digit-- > 0)
		i *= 10;
	if (n < i) /* has bugs! (but works for my usecase) */
		return (n);
	return ((n / i) % 10);
}

int is_palindrome(unsigned long n)
{
	/* 0, 11, 121, 1221 */
	/* 12, 123, 1231, 1234 */

	unsigned sum, count, back, odd, m = n;

	sum = count = back = odd = 0;
	if (n > 10)
	{
		while (n)
		{
			sum += n % 10;
			count += 1;
			n /= 10;
		}
		back = count / 2;
		odd = count % 2;
		/* 1 + 2 + (3) != 4 + 5 */
		while (--count > back)
		{
			n += nth(count, m);

		}
		sum -= n;
		if (odd)
			sum -= nth(count, m);
		return (sum == n);
	}
	else
		return (1);
}

int main(void)
{
	return (is_palindrome(1221));
}
