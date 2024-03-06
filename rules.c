/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:03:22 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/06 23:11:33 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stac_a, int i)
{
	void	*tmp;

	if (i == 1)
		write(1, "sa\n", 3);
	if (ft_lstsize(*stac_a) <= 1)
		return ;
	tmp = (*stac_a)->next->next;
	(*stac_a)->prev = (*stac_a)->next;
	(*stac_a)->next->next = (*stac_a);
	(*stac_a)->next->prev = NULL;
	(*stac_a)->next = tmp;
	(*stac_a) = (*stac_a)->prev;
	if ((*stac_a)->next->next)
		(*stac_a)->next->next->prev = (*stac_a)->next;
}

void	sb(t_list **stac_a, int i)
{
	void	*tmp;

	if (i == 1)
		write(1, "sb\n", 3);
	if (ft_lstsize(*stac_a) <= 1)
		return ;
	tmp = (*stac_a)->next->next;
	(*stac_a)->prev = (*stac_a)->next;
	(*stac_a)->next->next = (*stac_a);
	(*stac_a)->next->prev = NULL;
	(*stac_a)->next = tmp;
	(*stac_a) = (*stac_a)->prev;
	if ((*stac_a)->next->next)
		(*stac_a)->next->next->prev = (*stac_a)->next;
}

void	pa(t_list **stac_a, t_list **stac_b, int i)
{
	t_list	*new_node;
	void	*tmp;

	if (i == 1)
		write(1, "pa\n", 3);
	if (!*stac_b)
		return ;
	tmp = *stac_b;
	new_node = ft_lstnew((*stac_b)->content);
	if (ft_lstsize(*stac_b) == 1)
	{
		ft_lstadd_front(stac_a, new_node);
		if ((*stac_a)->next)
			(*stac_a)->next->prev = new_node;
		free(tmp);
		*stac_b = NULL;
		return ;
	}
	(*stac_b)->next->prev = NULL;
	(*stac_b) = (*stac_b)->next;
	free(tmp);
	ft_lstadd_front(stac_a, new_node);
	if ((*stac_a)->next)
		(*stac_a)->next->prev = (*stac_a);
}

void	free_stac(t_list **stac)
{
	if (!*stac)
		return ;
	while ((*stac)->next)
	{
		(*stac) = (*stac)->next;
		free((*stac)->prev);
	}
	free(*stac);
	*stac = NULL;
}
