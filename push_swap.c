/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:02:44 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/04 15:35:24 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac,char **av)
{
    t_list *stac_a;
    t_list *stac_b;
    t_data data;
    stac_b = NULL;
    stac_a = list(av);
    if(ft_lstsize(stac_a) == 2)
    {
        if(stac_a->content > stac_a->next->content)
            sa(&stac_a,1);
        return 0;
    }
    if(ac > 2)
    {
        algo(&data,&stac_a,&stac_b);
        sort_a(&stac_b,&stac_a,&data);
        free_stac(&stac_a);
        free_stac(&stac_b);
    }
    // printf("------------stac_b----------\n"); 
    // print_stac(stac_b);
    // printf("------------stac_a----------\n");
    // print_stac(stac_a);
    return 0;
}
