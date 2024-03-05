/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:02:44 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/05 18:28:37 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	random_numbers_3(t_list **stac_a)
{
	if ((*stac_a)->content > (*stac_a)->next->content
		&& (*stac_a)->content < (*stac_a)->next->next->content)
		sa(stac_a, 1);
	else if ((*stac_a)->content > (*stac_a)->next->content
		&& (*stac_a)->next->content > (*stac_a)->next->next->content)
	{
		sa(stac_a, 1);
		rra(stac_a, 1);
	}
	else if ((*stac_a)->content > (*stac_a)->next->content
		&& (*stac_a)->next->content < (*stac_a)->next->next->content)
		ra(stac_a, 1);
	else if ((*stac_a)->content < (*stac_a)->next->content
		&& (*stac_a)->content < (*stac_a)->next->next->content
		&& (*stac_a)->next->content > (*stac_a)->next->next->content)
	{
		sa(stac_a, 1);
		ra(stac_a, 1);
	}
	else if ((*stac_a)->content < (*stac_a)->next->content
		&& (*stac_a)->content > (*stac_a)->next->next->content)
		rra(stac_a, 1);
}

void	push_min(t_list **stack_a, t_list **stack_b)
{
	void	*tmp;
	int		nb;

	tmp = *stack_a;
	nb = (*stack_a)->content;
	while (*stack_a)
	{
		if (nb > (*stack_a)->content)
			nb = (*stack_a)->content;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = tmp;
	while (*stack_a)
	{
		if (nb == (*stack_a)->content)
			break ;
		ra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
}

void	random_numbers_5(t_list **stack_a, t_list **stack_b)
{
	push_min(stack_a, stack_b);
	push_min(stack_a, stack_b);
	random_numbers_3(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}

int	main(int ac, char **av)
{
	t_list	*stac_a;
	t_list	*stac_b;
	t_data	data;

	stac_b = NULL;
	stac_a = list(av);
	if (ac >= 3)
	{
		if (ft_lstsize(stac_a) == 2 && stac_a->content > stac_a->next->content)
			sa(&stac_a, 1);
		else if (ft_lstsize(stac_a) == 3)
			random_numbers_3(&stac_a);
		else if (ft_lstsize(stac_a) <= 5)
			random_numbers_5(&stac_a, &stac_b);
		else if (ft_lstsize(stac_a) > 5)
		{
			algo(&data, &stac_a, &stac_b);
			free(data.sort);
			sort_a(&stac_b, &stac_a, &data);
		}
		free_stac(&stac_a);
		free_stac(&stac_b);
	}
	return (0);
}
