/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:36:42 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/04 22:29:52 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	r = 0;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (str[i] == '\0')
		ft_error();
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		r = r * 10 + (str[i] - 48);
		i++;
		if ((r * s) > 2147483647 || (r * s) < -2147483648)
			ft_error();
	}
	if (str[i] != '\0')
		ft_error();
	return ((int)r * s);
}
