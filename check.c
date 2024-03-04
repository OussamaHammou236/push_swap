/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:13:36 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/04 16:48:31 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_error()
{
    write(2,"\033[0;31merror\n",13);
    exit(1);
}

int check_repeat_nb(t_list *node,int nb)
{
    t_list *tmp;
    tmp = ft_lstlast(node);
    while(tmp)
     {
          if(tmp->content == nb)
                return 1;
        tmp = tmp->prev;
     }
     return 0;  
}
void print_stac(t_list *node)
{
    while(node)
      {
         printf("%d\n",node->content);
         node = node->next;
     }  
}
t_list *list(char **av)
{
    int j;
    int i;
    j = 1;
    t_list *node = NULL;
    t_list *new;
    char **sp;
    
    while (av[j])
    {
        sp = ft_split(av[j],' ');
        if(sp[0] == '\0')
		    ft_error();
        i = 0;
        while(sp[i])
        {
            if(check_repeat_nb(node,ft_atoi(sp[i])) == 1)
                ft_error();
            new = ft_lstnew(ft_atoi(sp[i]));
            ft_lstadd_back(&node,new);
            free(sp[i]);
            i++;
        }
        free(sp);
        j++;
    }
    return node;
}
