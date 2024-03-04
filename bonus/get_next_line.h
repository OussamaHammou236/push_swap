/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:05:09 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/04 12:02:34 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

//# include <fcntl.h>
//# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../push_swap.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, char *s3);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);

#endif