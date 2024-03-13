/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:13:36 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/11 14:31:00 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_repeat_nb(t_list *node, int nb)
{
	t_list	*tmp;

	tmp = ft_lstlast(node);
	while (tmp)
	{
		if (tmp->content == nb)
			return (1);
		tmp = tmp->prev;
	}
	return (0);
}

void	copy_stac_to_arry(t_list **copy, t_data *data)
{
	void	*tmp;
	int		i;

	tmp = *copy;
	i = 0;
	data->lst_size = ft_lstsize(*copy);
	data->sort = malloc(data->lst_size * sizeof(int));
	while (i < data->lst_size)
	{
		data->sort[i] = (*copy)->content;
		(*copy) = (*copy)->next;
		i++;
	}
	*copy = tmp;
}

t_list	*list(char **av)
{
	t_list	*node;
	t_list	*new;
	t_data	data;

	data.j = 1;
	node = NULL;
	while (av[data.j])
	{
		data.sp = ft_split(av[data.j], ' ');
		if (data.sp[0] == '\0')
			ft_error();
		data.i = 0;
		while (data.sp[data.i])
		{
			if (check_repeat_nb(node, ft_atoi(data.sp[data.i])) == 1)
				ft_error();
			new = ft_lstnew(ft_atoi(data.sp[data.i]));
			ft_lstadd_back(&node, new);
			free(data.sp[data.i]);
			data.i++;
		}
		free(data.sp);
		data.j++;
	}
	return (node);
}
