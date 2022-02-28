/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:28:32 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/28 21:21:02 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/error_exit.h"
#include "deck.h"
#include <stdlib.h>

void	deck_init(t_deck *deck, int capacity)
{
	deck->arr = (int *) malloc(capacity * sizeof(int));
	if (deck->arr == NULL)
	{
		error_exit();
	}
	deck->capacity = capacity;
	deck->size = 0;
}

void	deck_free(t_deck *deck)
{
	free(deck->arr);
	deck->capacity = 0;
	deck->size = 0;
}

int	deck_back(const t_deck *deck)
{
	return (deck->arr[deck->size - 1]);
}

int	deck_front(const t_deck *deck)
{
	return (deck->arr[0]);
}

bool	deck_is_empty(const t_deck *deck)
{
	return (deck->size == 0);
}
