/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:02:44 by ohammou-          #+#    #+#             */
/*   Updated: 2024/02/14 10:02:22 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac,char **av)
{
    t_list *stac_a;
    t_list *stac_b;
    
    stac_b = NULL;
    ft_check(av);
    stac_a = list(av);
    while(stac_a->next->next)
         pb(&stac_a,&stac_b);
    while(stac_b)
       {
           if(stac_b->content < stac_a->content)
               pa(&stac_a,&stac_b);
           else
           {
               pa(&stac_a,&stac_b);
               ra(&stac_a);
           }
          
      }
    
    printf("------------stac_a----------\n");
    print_stac(stac_a);
    printf("------------stac_b----------\n");
    print_stac(stac_b);
    return 0;
}