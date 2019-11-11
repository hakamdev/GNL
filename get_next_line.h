/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehakam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:26:09 by ehakam            #+#    #+#             */
/*   Updated: 2019/11/08 19:05:38 by ehakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
/* *************** */
# include <stdio.h>

/* ************************************ */
/*                                      */
/*                 VARS                 */
/*                                      */
/* ************************************ */
# ifndef NL
#  define NL '\n'
# endif

# ifndef CNULL
#  define CNULL '\0'
# endif

# ifndef INULL
#  define INULL 0
# endif

# ifndef ERR
#  define ERR -1
# endif

# ifndef MAXINT
#  define MAXINT 2147483647
# endif

/* ************************************ */
/*                                      */
/*                MACROS                */
/*                                      */
/* ************************************ */
# ifndef BS_VALID
#  define BS_VALID(BS)  (((BS) < (MAXINT) && (BS) >= (0)) ? 1 : 0)
# endif

# ifndef FD_VALID
#  define FD_VALID(FD)  ((FD) >= 0 ? 1 : 0)
# endif

# ifndef EXIT_CODE
#  define EXIT_CODE(V)  (V) > 0 ? 1 : (V)
# endif

# ifndef EXIT
#  define EXIT(EXT_CD)  return (EXT_CD)
# endif

/* ************************************ */
/*                                      */
/*              PROTOTYPES              */
/*                                      */
/* ************************************ */
int		get_next_line(int fd, char **line);
void	ft_bzero(char **s);
int	    ft_index(const char *s, char c);
int		ft_find(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strsub(char **s, unsigned int start, size_t n);
void	ft_free(char **s);
int		ft_handle_nl(char **_line, char **_temp, char **_rest);
int		ft_handle_rest(char **_line, char **_temp, char **_rest);

#endif