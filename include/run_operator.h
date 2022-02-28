/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_operator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:00:42 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/25 20:39:12 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_OPERATOR_H
# define RUN_OPERATOR_H

# include "../lib/deck/deck.h"

enum	e_operator {
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

void	run_operator(enum e_operator op, t_deck *a, t_deck *b, bool is_print);

#endif