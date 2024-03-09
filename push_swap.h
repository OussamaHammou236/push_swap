/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohammou- <ohammou-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:51:15 by ohammou-          #+#    #+#             */
/*   Updated: 2024/03/09 15:33:51 by ohammou-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_data
{
	int				lst_size;
	int				x;
	int				i;
	int				j;
	int				*sort;
	int				offset;
	int				size;
	int				start;
	int				end;
	int				mid;
	int				ac;
	int				range;
	int				size_of_arr;
	int				nb;
	char			**sp;
}					t_data;

void				ra(t_list **stac_a, int i);
void				rb(t_list **stac_b, int i);
void				rra(t_list **stac_a, int i);
void				rrb(t_list **stac_b, int i);
void				sa(t_list **stac_a, int i);
void				sb(t_list **stac_b, int i);
void				ss(t_list **stac_a, t_list **stac_b, int i);
void				rr(t_list **stac_a, t_list **stac_b, int i);
void				rrr(t_list **stac_a, t_list **stac_b, int i);
void				pb(t_list **stac_a, t_list **stac_b, int i);
void				pa(t_list **stac_a, t_list **stac_b, int i);

t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
int					ft_lstsize(t_list *lst);

void				ft_error(void);
int					ft_atoi(const char *str);
t_list				*list(char **av);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *str);
void				free_stac(t_list **stac);
int					check_repeat_nb(t_list *node, int nb);
void				sort_a(t_list **stac_b, t_list **stac_a, t_data *data);
int					pos_of_nb(t_list **stac_a, int nb);
int					wach_kbir(t_list **stac_a, int nb);
void				sort_a(t_list **stac_b, t_list **stac_a, t_data *data);
void				sort_arr(t_list **stac_a, t_data *data);
void				copy_stac_to_arry(t_list **copy, t_data *data);
int					chehal(t_list **stac_a, int nb);
int					pos(t_list **stac_a, t_data *data);
int					wach_kbir(t_list **stac_a, int nb);
void				ra_or_rra(t_data *data, t_list **stac_a);
void				algo(t_data *data, t_list **stac_a, t_list **stac_b);
int					check_1(t_list *stack_a);

#endif