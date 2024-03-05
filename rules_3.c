/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:31:51 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/05 20:33:07 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **stac_a, t_list **stac_b, int i)
{
	if (i == 1)
		write(1, "rrr\n", 4);
	rra(stac_a, 0);
	rrb(stac_b, 0);
}

void	rr(t_list **stac_a, t_list **stac_b, int i)
{
	if (i == 1)
		write(1, "rr\n", 3);
	ra(stac_a, 0);
	rb(stac_b, 0);
}

void	ss(t_list **stac_a, t_list **stac_b, int i)
{
	if (i == 1)
		write(1, "ss\n", 3);
	sa(stac_a, 0);
	sb(stac_b, 0);
}
