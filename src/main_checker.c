/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:31:26 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/26 17:27:41 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/libft/get_next_line.h"
#include "../lib/deck/deck.h"
#include "../include/argument_passing.h"
#include "../include/run_operator.h"
#include "../include/error_exit.h"
#include <unistd.h>

enum e_operator	get_op2(char *operator)
{
	if (ft_strcmp(operator, "ra") == 0)
		return (ra);
	else if (ft_strcmp(operator, "rb") == 0)
		return (rb);
	else if (ft_strcmp(operator, "rr") == 0)
		return (rr);
	else if (ft_strcmp(operator, "rra") == 0)
		return (rra);
	else if (ft_strcmp(operator, "rrb") == 0)
		return (rrb);
	else if (ft_strcmp(operator, "rrr") == 0)
		return (rrr);
	else
		error_exit();
	return (1);
}

enum e_operator	get_op(char *operator)
{
	if (ft_strcmp(operator, "sa") == 0)
		return (sa);
	else if (ft_strcmp(operator, "sb") == 0)
		return (sb);
	else if (ft_strcmp(operator, "ss") == 0)
		return (ss);
	else if (ft_strcmp(operator, "pa") == 0)
		return (pa);
	else if (ft_strcmp(operator, "pb") == 0)
		return (pb);
	else
	{
		return (get_op2(operator));
	}
}

int	main(int argc, char *argv[])
{
	t_deck		stack_a;
	t_deck		stack_b;
	char		*operator;
	const int	capacity = get_num_argument(argc, argv);

	deck_init(&stack_a, capacity);
	deck_init(&stack_b, capacity);
	push_argument_to_stack(argc, argv, &stack_a);
	if (argc < 2)
		return (0);
	while (get_next_line(0, &operator))
	{
		run_operator(get_op(operator), &stack_a, &stack_b, false);
		free(operator);
	}
	free(operator);
	if (deck_is_sorted(&stack_a) && deck_is_empty(&stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	deck_free(&stack_a);
	deck_free(&stack_b);
	return (0);
}
