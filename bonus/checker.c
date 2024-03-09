/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:38:29 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/09 17:52:49 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_movse(char *line, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else
		ft_error();
}

void	is_sorted(t_list **stack_a, t_list **stack_b)
{
	if (*stack_b)
		write(1, "\033[0;31m KO\n", 11);
	else if (check_1(*stack_a) == 0)
		write(1, "\033[0;31m KO\n", 11);
	else
		write(1, "\033[0;32m OK\n", 11);
}

int	main(int ac, char **av)
{
	char	*line;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = list(av);
	stack_b = NULL;
	if (ac < 2)
		return (0);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		read_movse(line, &stack_a, &stack_b);
		free(line);
	}
	free(line);
	is_sorted(&stack_a, &stack_b);
	free_stac(&stack_a);
	free_stac(&stack_b);
}
