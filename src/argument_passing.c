/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_passing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 17:05:14 by yunselee          #+#    #+#             */
/*   Updated: 2022/02/26 17:26:53 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include "../lib/deck/deck.h"
#include <stdbool.h>
#include <unistd.h>
#include "../include/argument_passing.h"
#include "../include/error_exit.h"

static long long	get_num(const char *str, bool *is_num)
{
	long long	num;

	num = 0;
	while ((*str) >= '0' && (*str) <= '9')
	{
		*is_num = true;
		num = num * 10 + (long long)(*str) - '0';
		str++;
	}
	return (num);
}

static long long	fft_atoi(const char *str)
{
	long long	num;
	int			sign;
	bool		is_num;

	num = 0;
	sign = 0;
	is_num = false;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	num = get_num(str, &is_num);
	if (sign & 1)
		num *= -1;
	if (!is_num)
		error_exit();
	return (num);
}

int	get_num_argument(int argc, char *argv[])
{
	char	**words;
	int		i;
	int		j;
	int		num;

	num = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		words = ft_split(argv[i], ' ');
		while (words[j] != NULL)
		{
			num++;
			free(words[j]);
			j++;
		}
		i++;
		free(words);
	}
	return (num);
}

void	push_argument_to_stack(int argc, char *argv[], t_deck *out_deck)
{
	const int	min_int = -2147483648;
	char		**words;
	long long	num;
	int			i;
	int			j;

	i = 0;
	while (++i < argc)
	{
		words = ft_split(argv[i], ' ');
		j = 0;
		if (words[0] == NULL)
			error_exit();
		while (words[j] != NULL)
		{
			num = fft_atoi(words[j]);
			if (num > (long long)0x7fffffff || num < (long long)min_int \
			|| deck_is_in(out_deck, (int)num))
				error_exit();
			deck_push_front(out_deck, (int)num);
			free(words[j]);
			j++;
		}
		free(words);
	}
}
