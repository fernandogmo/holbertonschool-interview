#include "regex.h"

/**
* regex_match - matches patterns ('*' and '.') with string
* @str: string
* @pattern: pattern which contains alphabetic chars, '*', and '.'
* Return: 1 if string matches pattern 0 otherwise
*/
int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);
	if (!*str)
	{
		if (*(pattern + 1) == '*')
			return (regex_match(str, pattern + 2));
		return (!*pattern);
	}
	if (*(pattern + 1) == '*')
	{
		if (*pattern == '.' || *pattern == *str)
			return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
		return (regex_match(str, pattern + 2));
	}
	if (*pattern == '.' || *pattern == *str)
	{
		return (regex_match(str + 1, pattern + 1));
	}
	return (0);
}
