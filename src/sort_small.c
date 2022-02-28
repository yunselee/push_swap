/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:52:12 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/25 20:38:57 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/run_operator.h"
#include "../lib/deck/deck.h"
#include <stdlib.h>

static void	sort_3(t_deck *a)
{
	const int	*arr = a->arr;

	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		run_operator(sa, a, NULL, true);
	else if (arr[0] < arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
	{
		run_operator(sa, a, NULL, true);
		run_operator(rra, a, NULL, true);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		run_operator(ra, a, NULL, true);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		run_operator(sa, a, NULL, true);
		run_operator(ra, a, NULL, true);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
		run_operator(rra, a, NULL, true);
}

static int	get_mid(const t_deck *a)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		k = 0;
		while (j < a->size)
		{
			if (a->arr[j] - a->arr[i] > 0)
			{
				k++;
			}
			j++;
		}
		if (k == 2)
		{
			return (a->arr[i]);
		}
		i++;
	}
	return (1);
}

static void	sort_4_to_5(t_deck *a, t_deck *b)
{
	const int	mid = get_mid(a);

	while (3 < a->size)
	{
		while (deck_back(a) >= mid)
			run_operator(ra, a, b, true);
		run_operator(pb, a, b, true);
	}
	sort_3(a);
	while (b->size > 0)
		run_operator(pa, a, b, true);
	if (a->arr[a->size - 1] > a->arr[a->size - 2])
		run_operator(sa, a, b, true);
}

void	sort_small(t_deck *a, t_deck *b)
{
	if (a->size == 2)
		run_operator(sa, a, b, true);
	else if (a->size == 3)
		sort_3(a);
	else
		sort_4_to_5(a, b);
}
