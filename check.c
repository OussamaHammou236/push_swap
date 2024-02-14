/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:13:36 by ohammou-          #+#    #+#             */
/*   Updated: 2024/02/12 21:15:15 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_error(char *str)
{
    printf("%s",str);
    exit(1);
}

void ft_check(char **av)
{
    int i;
    int j;
    int s;

    s = 0;
    j   =   1;
    while(av[j])
    {
        i   =   0;
        while(av[j][i])
        {
            if(!(av[j][i] >= '0' && av[j][i] <= '9') && av[j][i] != '-' && av[j][i] != '+' && av[j][i] != ' ')
                    ft_error("error");
            if((av[j][i] == '-' || av[j][i] == '+') && (av[j][i + 1] == '-' || av[j][i+1] == '+' || av[j][i + 1] == ' ' || av[j][i + 1] == '\0'))
                ft_error("error1");
            if((av[j][i-1] >= '0' && av[j][i-1] <= '9') && (av[j][i] == '-' || av[j][i] == '+') && (av[j][i+1] >= '0' && av[j][i+1] <= '9'))
                ft_error("error2");
           i++;
        }
        i = 0;
        while(av[j][i])
        {
            if(av[j][i] == ' ')
                s++;
            i++;
        }
        if(s == i)
            ft_error("error : finahwa r9m");
        j++;
    }
}

void check_repeat_nb(t_list *node,int nb)
{
    t_list *tmp;
    tmp = ft_lstlast(node);
    while(tmp)
     {
          if(tmp->content == nb)
              ft_error("double number");
        tmp = tmp->prev;
     }  
}
void print_stac(t_list *node)
{
    // t_list *tmp;
    // tmp = ft_lstlast(node);
    // while(tmp)
    //  {
    //      printf("%d\n",tmp->content);
    //     tmp = tmp->prev;
    //  }  
   while(node)
     {
        printf("%d\n",node->content);
        node = node->next;
     }  
}
t_list * list(char **av)
{
    int j;
    int i;
    int c = 0;
    j = 1;
    t_list *node = NULL;
    t_list *new;
    char **sp;
    while (av[j])
    {
        sp = ft_split(av[j],' ');
        i = 0;
        while(sp[i])
        {
            check_repeat_nb(node,ft_atoi(sp[i]));
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