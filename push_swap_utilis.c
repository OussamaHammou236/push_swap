/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:38 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/05 18:28:04 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos(t_list **stac_a, t_data *data)
{
	int		i;
	void	*tmp;

	tmp = *stac_a;
	i = 0;
	while (*stac_a)
	{
		if (((*stac_a)->content > data->sort[data->start]
				&& (*stac_a)->content <= data->sort[data->end])
			|| (*stac_a)->content <= data->sort[data->start])
			break ;
		i++;
		*stac_a = (*stac_a)->next;
	}
	*stac_a = tmp;
	return (i);
}

int	wach_kbir(t_list **stac_a, int nb)
{
	void	*tmp;
	int		i;

	tmp = *stac_a;
	i = 0;
	while ((*stac_a))
	{
		if (nb >= (*stac_a)->content)
			i++;
		(*stac_a) = (*stac_a)->next;
	}
	*stac_a = tmp;
	if (ft_lstsize(*stac_a) == i)
		return (1);
	return (0);
}

void	ra_or_rra(t_data *data, t_list **stac_a)
{
	int	i;

	i = pos(stac_a, data);
	if (i <= ft_lstsize(*stac_a) / 2)
		ra(stac_a, 1);
	else
		rra(stac_a, 1);
}

void	range(t_list **stac_a, t_data *data)
{
	int	size;

	size = ft_lstsize(*stac_a);
	if (size >= 6 && size <= 16)
		data->range = 8;
	else if (size <= 100)
		data->range = 13;
	else if (size <= 500)
		data->range = 29;
	else
		data->range = 39;
	sort_arr(stac_a, data);
	data->start = 0;
	data->end = data->range;
}

void	algo(t_data *data, t_list **stac_a, t_list **stac_b)
{
	range(stac_a, data);
	while (*stac_a)
	{
		if (data->end >= data->size_of_arr)
			data->end = data->size_of_arr - 1;
		if ((*stac_a)->content > data->sort[data->start]
			&& (*stac_a)->content <= data->sort[data->end])
		{
			pb(stac_a, stac_b, 1);
			if (ft_lstsize(*stac_b) >= 2
				&& (*stac_b)->content < (*stac_b)->next->content)
				sb(stac_b, 1);
			data->end++;
			data->start++;
		}
		else if ((*stac_a)->content <= data->sort[data->start])
		{
			pb(stac_a, stac_b, 1);
			rb(stac_b, 1);
			data->end++;
			data->start++;
		}
		else
			ra_or_rra(data, stac_a);
	}
}
