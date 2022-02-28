/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:40:12 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/25 19:16:14 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECK_H
# define DECK_H

# include <stdbool.h>

typedef struct s_deck {
	int	*arr;
	int	size;
	int	capacity;
}t_deck;

void	deck_init(t_deck *deck, int capacity);
void	deck_free(t_deck *deck);

void	deck_push_front(t_deck *deck, int data);
int		deck_pop_front(t_deck *deck);
void	deck_push_back(t_deck *deck, int data);
int		deck_pop_back(t_deck *deck);

bool	deck_is_in(const t_deck *deck, int num);
int		deck_front(const t_deck *deck);
int		deck_back(const t_deck *deck);

bool	deck_is_sorted(const t_deck *deck);
bool	deck_is_empty(const t_deck *deck);

#endif