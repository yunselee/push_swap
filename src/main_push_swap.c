/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:47:12 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/28 21:20:19 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/argument_passing.h"
#include "../include/push_swap.h"
#include "../lib/deck/deck.h"
#include "../include/error_exit.h"
#include "unistd.h"
#include <stdbool.h>
#include <stdlib.h>

static void	indexing_stack(t_deck *a)
{
	int		*tmp;
	int		i;
	int		j;

	tmp = (int *)malloc(sizeof(int) * a->capacity);
	if (tmp == NULL)
	{
		error_exit();
	}
	i = 0;
	while (i < a->size)
	{
		j = 0;
		tmp[i] = 0;
		while (j < a->size)
		{
			if (a->arr[i] > a->arr[j])
				tmp[i]++;
			j++;
		}
		i++;
	}
	free(a->arr);
	a->arr = tmp;
}

int	main(int argc, char *argv[])
{
	t_deck		stack_a;
	t_deck		stack_b;
	const int	capacity = get_num_argument(argc, argv);

	deck_init(&stack_a, capacity);
	deck_init(&stack_b, capacity);
	push_argument_to_stack(argc, argv, &stack_a);
	indexing_stack(&stack_a);
	if (!deck_is_sorted(&stack_a))
	{
		push_swap(&stack_a, &stack_b);
	}
	deck_free(&stack_a);
	deck_free(&stack_b);
	return (0);
}
