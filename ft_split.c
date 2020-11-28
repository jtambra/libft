/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtambra <talya_1998@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:52:13 by jtambra           #+#    #+#             */
/*   Updated: 2020/11/28 20:54:55 by jtambra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nword(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static size_t	ln(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void		ft_clean(char **s)
{
	size_t	i;

	i = 0;
	while (s[i++])
		free(s[i]);
	free(s);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	i;
	size_t	n;
	size_t	j;

	n = -1;
	i = 0;
	if (!s || !(dst = ((char **)malloc(sizeof(char *) * (ft_nword(s, c) + 1)))))
		return (NULL);
	while (++n < (ft_nword(s, c)))
	{
		j = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		if (!(dst[n] = ((char *)malloc(sizeof(char) * ((ln(&s[i], c)) + 1)))))
		{
			ft_clean(dst);
			return (NULL);
		}
		while (s[i] != c && s[i] != '\0')
			dst[n][j++] = s[i++];
		dst[n][j] = '\0';
	}
	dst[n] = NULL;
	return (dst);
}
