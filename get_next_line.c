/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:22:33 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/10 14:22:39 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************ */
/*                                      */
/*           HELPER FUNCTIONS           */
/*                                      */
/* ************************************ */

void	ft_free(char **s)
{
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}

int		ft_handle_nl(char **_line, char **_temp, char **_rest)
{
	int		nl_index;
	char	*addup;

	//ft_free(_rest);
	nl_index = ft_index(*_temp, NL);
	if (nl_index != ERR)
	{
		addup = ft_strsub(_temp, 0, nl_index);
		*_line = ft_strjoin(*_line, addup);
		ft_free(&addup);
		*_rest = ft_strdup(&_temp[0][nl_index + 1]);
		ft_free(_temp);
		EXIT(1);
	}
	EXIT(INULL);
}

int		ft_handle_rest(char **_line, char **_temp, char **_rest)
{
	if (*_rest)
	{
		if (ft_find(*_rest, NL))
		{
			ft_free(_temp);
			*_temp = *_rest;
			if (ft_handle_nl(_line, _temp, _rest))
				EXIT(1);
		}
		else
		{
			*_line = ft_strjoin(*_line, *_rest);
			ft_free(_rest);
		}
	}
	EXIT(INULL);
}

/* ************************************ */
/*                                      */
/*             GNL FUNCTION             */
/*                                      */
/* ************************************ */
int		get_next_line(int fd, char **line)
{
	static char	*rest;
	char		*temp;
	int			_read;

	_read = 0;
	*line = ft_strdup("");

	if (!line || !BS_VALID(BUFFER_SIZE) || !FD_VALID(fd) ||
		!(temp = malloc(BUFFER_SIZE + 1)))
		EXIT(ERR);
	if (ft_handle_rest(line, &temp, &rest))
		EXIT(1);
	while ((_read = read(fd, temp, BUFFER_SIZE)) > INULL)
	{
		temp[_read] = CNULL;
		if (ft_find(temp, NL))
			if (ft_handle_nl(line, &temp, &rest))
				EXIT(1);
		*line = ft_strjoin(*line, temp);
		//ft_bzero(&temp);
	}
	if (!_read)
		ft_free(&temp);
	EXIT(EXIT_CODE(_read));
}