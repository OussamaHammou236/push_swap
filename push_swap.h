/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:51:15 by ohammou-          #+#    #+#             */
/*   Updated: 2024/02/25 15:27:01 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
    struct s_list   *prev;
}					t_list;

typedef struct s_data
{
	int lst_size;
	int x;
	int i;
	int j;
	int *sort;
	int offset;
	int size;
	int start;
	int end;
	int mid;
}	t_data;


t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);
void ft_check(char **av);
void ft_error(char *str);
int	ft_atoi(const char *str);
t_list *list(char **av);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
void print_stac(t_list *node);
void pb(t_list **stac_a,t_list **stac_b);
void pa(t_list **stac_a,t_list **stac_b);
void free_stac(t_list **stac);
void ra(t_list **stac_a);
void rra(t_list **stac_a);
void sb(t_list **stac_b);
void sa(t_list **stac_a);
void rrb(t_list **stac_b);
int check_repeat_nb(t_list *node,int nb);
void sort_a(t_list **stac_b,t_list **stac_a,t_data *data);
int pos_of_nb(t_list **stac_a,int nb);
int chehal(t_list **stac_a,int nb);

#endif