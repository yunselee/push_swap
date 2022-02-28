/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:02:04 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/25 20:39:16 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/run_operator.h"
#include "../lib/libft/libft.h"
#include "../include/error_exit.h"
#include <stdlib.h>

static int	swap(t_deck *a, t_deck *b, enum e_operator op)
{
	int	first;
	int	second;

	if (op == sa || op == ss)
	{
		first = deck_pop_back(a);
		second = deck_pop_back(a);
		deck_push_back(a, first);
		deck_push_back(a, second);
	}
	if (op == sb || op == ss)
	{
		first = deck_pop_back(b);
		second = deck_pop_back(b);
		deck_push_back(b, first);
		deck_push_back(b, second);
	}
	return (1);
}

static int	push(t_deck *src_deck, t_deck *dest_deck)
{
	const int	num = deck_pop_back(src_deck);

	deck_push_back(dest_deck, num);
	return (1);
}

static int	reverse_rotate(t_deck *deck)
{
	const int	num = deck_pop_front(deck);

	deck_push_back(deck, num);
	return (1);
}

static int	rotate(t_deck *deck)
{
	const int	num = deck_pop_back(deck);

	deck_push_front(deck, num);
	return (1);
}

void	run_operator(enum e_operator op, t_deck *a, t_deck *b, bool is_print)
{
	const char	*str[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
			"rr", "rra", "rrb", "rrr" };

	if (op == sa || op == sb || op == ss)
		swap(a, b, op);
	else if (op == pa)
		push(b, a);
	else if (op == pb)
		push(a, b);
	else if (op == ra)
		rotate(a);
	else if (op == rb)
		rotate(b);
	else if (op == rr)
		rotate(b) && rotate(a);
	else if (op == rra)
		reverse_rotate(a);
	else if (op == rrb)
		reverse_rotate(b);
	else if (op == rrr)
		reverse_rotate(a) && reverse_rotate(b);
	else
		error_exit();
	if (is_print)
		ft_putendl_fd(str[op], 1);
}
