#include "../push_swap.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && !word)
		{
			count++;
			word = 1;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*get_word(const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = word_len(s, c);
	word = malloc(len + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = *s;
		i++;
		s++;
	}
	word[i] = '\0';
	return (word);
}

static int	add_word(char **res, int *i, const char **s, char c)
{
	int	j;

	res[*i] = get_word(*s, c);
	if (!res[*i])
	{
		j = *i;
		while (--j >= 0)
			free(res[j]);
		free(res);
		return (0);
	}
	(*i)++;
	*s += word_len(*s, c);
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	int		i;
	char	**res;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!add_word(res, &i, &s, c))
				return (NULL);
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
