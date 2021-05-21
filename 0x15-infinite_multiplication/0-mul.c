#include <stdio.h>
#pragma GCC diagnostic ignored "-Wpedantic"

/**
 * main - entry point for infinite multiplication
 * @argc: should be 3
 * @argv: should contain 2 strings representing positive ints in base 10
 * Return: 0 on success, or 98 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 3) goto fail;
	char *n1 = argv[1], *n2 = argv[2];
	int i, j, sum;
	for (i = 0, sum = 0; n1[i] > 0; sum += n1[i++] - '0')
		if (n1[i] < '0' || n1[i] > '9') goto fail;
	if (sum == 0) { printf("0\n"); return (0);}
	for (j = 0, sum = 0; n2[j] > 0; sum += n2[j++] - '0')
		if (n2[j] < '0' || n2[j] > '9') goto fail;
	if (sum == 0) { printf("0\n"); return (0);}
	int ln1 = i, ln2 = j;
	char d1, d2, m, buf[BUFSIZ] = {0};
	for (i = ln1 - 1; i >= 0; i--)
	{
		d1 = n1[i] - '0';
		for (j = ln2 - 1; j >= 0; j--)
		{
			d2 = n2[j] - '0';
			m = (d1 * d2) + buf[i + j + 1];
			buf[i + j + 1] = m % 10;
			buf[i + j] += (m / 10);
		}
	}
	for (i = 0; i < ln1+ln2; buf[i++] += '0');
	printf("%s\n", (buf[0] == '0') ?  &buf[1] : buf);
	return (0);
fail:
	printf("Error\n");
	return (98);
}
