/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:25:21 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/08 19:06:36 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************ */
/*                                      */
/*           EXTRA FUNCTIONS            */
/*                                      */
/* ************************************ */

int		ft_index(const char *s, char c)
{
	int 	i;

	if (s)
	{
		i = 0;
		while ((char)s[i])
		{
			if ((char)s[i] == c)
				EXIT(i);
			i++;
		}
	}
	EXIT(ERR);
}

int		ft_find(const char *s, char c)
{
	int		i;

	i = 0;
	while (s && s[i])
		if ((char)s[i++] == c)
			EXIT(1);
	EXIT(INULL);
}

/* ************************************ */
/*                                      */
/*          STRINGS FUNCTIONS           */
/*                                      */
/* ************************************ */
char	*ft_strsub(char **s, unsigned int start, size_t n)
{
	char			*ss;
	unsigned int	lens;
	unsigned int	i;

	i = 0;
	if (*s == NULL)
		EXIT(NULL);
	lens = ft_strlen(*s);
	if (start > lens)
		n = 0;
	if (!(ss = (char *)malloc(n + 1)))
		EXIT(NULL);
	while (i < n && start < lens)
		*(ss + i++) = *(*s + start++);
	*(ss + i) = CNULL;
	EXIT(ss);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ss;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 && s2)
	{
		ss = ft_strdup(s2);
		EXIT(ss);
	}
	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ss = malloc(len1 + len2 + 1)))
		EXIT(NULL);
	while (i < len1)
	{
		*(ss + i) = *((char *)(s1 + i));
		i++;
	}
	while (j < len2)
		*(ss + i++) = *((char *)(s2 + j++));
	*(ss + i) = CNULL;
	ft_free(&s1);
	//ft_free(&s2);
	EXIT(ss);
}

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	lens;
	lens = ft_strlen(s);
	if (!(ss = (char *)malloc(lens + 1)))
		EXIT(NULL);
	while (*s)
		*ss++ =  *s++;
	*ss = CNULL;
	EXIT(ss - lens);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i))
		i++;
	EXIT(i);
}