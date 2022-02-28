/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:25:18 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/25 19:15:53 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deck.h"
#include <stdlib.h>

void	deck_push_front(t_deck *deck, int data)
{
	int	i;

	i = deck->size;
	while (i > 0)
	{
		deck->arr[i] = deck->arr[i - 1];
		i--;
	}
	deck->arr[0] = data;
	deck->size++;
}

int	deck_pop_front(t_deck *deck)
{
	const int	data = deck->arr[0];
	int			i;

	i = 0;
	deck->size--;
	while (i < deck->size)
	{
		deck->arr[i] = deck->arr[i + 1];
		i++;
	}
	return (data);
}

void	deck_push_back(t_deck *deck, int data)
{
	deck->arr[deck->size] = data;
	deck->size++;
}

int	deck_pop_back(t_deck *deck)
{
	deck->size--;
	return (deck->arr[deck->size]);
}
