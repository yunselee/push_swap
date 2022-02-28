/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:26:51 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/28 21:21:13 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deck.h"
#include <stdlib.h>

bool	deck_is_in(const t_deck *deck, int num)
{
	const int	*arr = deck->arr;
	int			n;
	int			i;

	if (deck->size == 0)
		return (false);
	i = 0;
	while (i < deck->size)
	{
		n = arr[i];
		if (num == n)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

bool	deck_is_sorted(const t_deck *deck)
{
	const int	*arr = deck->arr;
	int			i;

	i = 0;
	while (i + 1 < deck->size)
	{
		if (arr[i] < arr[i + 1])
		{
			return (false);
		}
		i++;
	}
	return (true);
}
