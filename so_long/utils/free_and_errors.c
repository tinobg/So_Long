/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:56:27 by brjoves           #+#    #+#             */
/*   Updated: 2024/01/03 16:49:58 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_map(t_long *game)
{
	int	i;

	i = 0;
	if (game->maptofree == -1)
		return (1);
	while (i < game->y)
	{
		free(game->map[i]);
		i++;
	}
	if (game->map)
		free(game->map);
	return (1);
}

int	exit_and_free(t_long *game)
{
	int	i;

	i = 0;
	if (game->mlx_ptr != NULL)
	{
		while (i < 5)
		{
			mlx_destroy_image(game->mlx_ptr, game->text[i]);
			i++;
		}
		mlx_destroy_image(game->mlx_ptr, game->img);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
	}
	free_map(game);
	free(game->mlx_ptr);
	write(1, "\n\033[31m ~~ so_long closed successfully! ~~\n", 42);
	exit(0);
}

int	error_msg(t_long *game, char *str)
{
	write(1, "\033[31mError\n\033[0;37m", 12);
	ft_putstr(str);
	write(1, "\n", 1);
	exit_and_free(game);
	return (0);
}
