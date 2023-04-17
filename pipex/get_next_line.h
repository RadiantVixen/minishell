/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <aatki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:56:05 by aatki             #+#    #+#             */
/*   Updated: 2023/04/16 22:48:52 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdupg(char *src);
char	*ft_substrg(char *s, unsigned int start, size_t len);
char	*check(char **s);
int		ft_strlen(char *s);

#endif
