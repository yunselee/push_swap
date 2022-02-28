/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_passing.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:33:28 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/25 19:23:41 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENT_PASSING_H
# define ARGUMENT_PASSING_H

# include "../lib/deck/deck.h"

void	push_argument_to_stack(int argc, char *argv[], t_deck *out_deck);
int		get_num_argument(int argc, char *argv[]);

#endif
