#include "substring.h"

/**
* hash - hash function
* @s: string to hash
* @end: end index of @s
* Return: hash val of @s
*/
unsigned long hash(const char *s, int end)
{
	const int p = 31;
	const int m = 1e9 + 9;
	int i;
	unsigned long hash_value = 0;
	unsigned long p_pow = 1;

	for (i = 0; i < end; ++i)
	{
		hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	return (hash_value);
}

/**
* make_hash - create a array of hashes from @words
* @words: list of words
* @nb_words: size of @words
* Return: list of hashes
*/
unsigned long *make_hash(char const **words, int nb_words)
{
	unsigned long *hashes = calloc(nb_words, sizeof(*hashes));
	int i;

	if (!hashes)
	{
		exit(1);
	}
	for (i = 0; i < nb_words; ++i)
	{
		hashes[i] = hash(words[i], strlen(words[i]));
	}
	return (hashes);
}

/**
* find_substring - finds all the possible substrings containing a list
* of words, within a given string.
* @s: string to check
* @words: list of words
* @nb_words: size of @words
* @n: size of result array
* Return: list of indecies where permutations start
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, str_len, cnt;
	int *res = calloc(1000, sizeof(*res));
	int *count = malloc(nb_words * sizeof(*count));
	int i, j, k;
	unsigned long *hashes, hash_val;

	if (!res || !count || !s || !words || !*words || !nb_words || !n)
	{
		return (NULL);
	}
	hashes = make_hash(words, nb_words);
	str_len = strlen(s), len = strlen(words[0]), *n = 0;
	for (i = 0; i <= str_len - nb_words * len; ++i)
	{
		memset(count, 0, nb_words * sizeof(*count));
		cnt = 0;
		for (j = 0; j < nb_words; ++j)
		{
			hash_val = hash(s + i + j * len, len);
			for (k = 0; k < nb_words; ++k)
			{
				if (count[k] == 1)
					continue;
				if (hashes[k] == hash_val && !strncmp(s + i + j * len, words[k], len))
				{
					count[k] = 1;
					++cnt;
					break;
				}
			}
		}
		if (cnt == nb_words)
		{
			res[*n] = i;
			*n += 1;
		}
	}
	free(count), free(hashes);
	return (res);
}
