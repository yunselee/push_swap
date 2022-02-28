/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:42:54 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/28 21:19:30 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/run_operator.h"
#include "../include/push_swap.h"
#include <stdlib.h>

void	sort_small(t_deck *a, t_deck *b);

static void	push_chunks(t_deck *a, t_deck *b, int step)
{
	int	num;

	num = 0;
	while (!deck_is_empty(a))
	{
		if (deck_back(a) <= num)
		{
			run_operator(pb, a, b, true);
			run_operator(rb, a, b, true);
			num++;
		}
		else if (deck_back(a) <= num + step)
		{
			run_operator(pb, a, b, true);
			num++;
		}
		else
			run_operator(ra, a, b, true);
	}
}

static void	put_num_to_top_b(t_deck *b, int num)
{
	int	index;

	index = 0;
	while (index < b->size && b->arr[index] != num)
		index++;
	while (index < b->size / 2 && index >= 0)
	{
		run_operator(rrb, NULL, b, true);
		index--;
	}
	while (index >= b->size / 2 && index < b->size - 1)
	{
		run_operator(rb, NULL, b, true);
		index++;
	}
}

static void	sorting_back(t_deck *a, t_deck *b)
{
	int	num;

	num = b->size;
	while (!deck_is_empty(b))
	{
		num--;
		put_num_to_top_b(b, num);
		run_operator(pa, a, b, true);
	}
}

static void	sort(t_deck *a, t_deck *b)
{
	int	step;

	step = 15;
	if (a->size > 250)
		step += 15;
	push_chunks(a, b, step);
	sorting_back(a, b);
}

void	push_swap(t_deck *a, t_deck *b)
{
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort(a, b);
}
