/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschaft <cecile.schaft@orange.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:00:47 by jschaft           #+#    #+#             */
/*   Updated: 2023/12/13 10:39:12 by jschaft          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
}				t_list;

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char const *s);
int		ft_atoi(char *nptr);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		get_len(char *str, int i);
int		word_count(char *str);
void	ft_putstr(const char *str);

int		test_tab_str(char **tab);
int		test_zero(char *s1, char *s2);
int		test_tab(char **tab, int ac);
int		verif_double(char **tab, int ac);
int		verif_double_str(char **tab);

t_list	*sa(t_list *stack);
t_list	*ra(t_list *stack);
t_list	*rra(t_list *stack);
t_list	**pa(t_list **stack);

t_list	*sb(t_list *stack);
t_list	*rb(t_list *stack);
t_list	*rrb(t_list *stack);
t_list	**pb(t_list **stack);

t_list	*ft_lstnew(int n_nbr);
void	ft_printlst(t_list *lst);
int		ft_lstsorted(t_list *lst);
int		ft_lstsize(t_list *lst);

int		verif_error(int ac, char **av);

int		get_smallest_index(t_list *stack);
int		get_nb_small(t_list *stack, int ministack);
int		get_biggest_index(t_list *stack);
int		get_second_smallest(t_list *stack, int smallest);
int		get_first_index(t_list *stack, int min, int max);
int		get_last_index(t_list *stack, int min, int max);

t_list	**push_closest(t_list **stack, int min, int max, int size);
t_list	**push_biggest(t_list **stack, int size);
int		nbr_to_move(int i, int size);

t_list	**complete_at_two(t_list **stack);
t_list	**sort_three(t_list **stack);
t_list	**sort_ft(t_list **stack);
t_list	**sort_five(t_list **stack, int size);
t_list	**sort_hundred(t_list **stack, int *size);
t_list	**sort_fhundred(t_list **stack, int *size);

void	free_all(t_list **stack, int *size);
void	free_split(char	**tab);

#endif