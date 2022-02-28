/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:29:53 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/25 19:33:11 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error_exit.h"
#include <unistd.h>
#include <stdlib.h>

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
