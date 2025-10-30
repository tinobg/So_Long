/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:56:42 by brjoves           #+#    #+#             */
/*   Updated: 2023/12/26 12:56:44 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_moves(int nb, t_long *game)
{
	if (nb == 1)
		if (game->map[game->player_y - 1][game->player_x] != '1')
			show_moves(game, nb);
	if (nb == -1)
		if (game->map[game->player_y + 1][game->player_x] != '1')
			show_moves(game, nb);
	if (nb == 2)
		if (game->map[game->player_y][game->player_x - 1] != '1')
			show_moves(game, nb);
	if (nb == 3)
		if (game->map[game->player_y][game->player_x + 1] != '1')
			show_moves(game, nb);
	return (0);
}

int	show_moves(t_long *game, int nb)
{
	write(1, "\b\b\b\b\b\b\b\b\b\b\b", 11);
	if (nb == 1)
		game->player_y--;
	if (nb == -1)
		game->player_y++;
	if (nb == 2)
		game->player_x--;
	if (nb == 3)
		game->player_x++;
	game->move++;
	write(1, "Moves : ", 9);
	ft_putnbr(game->move);
	final_moves(game);
	return (0);
}

int	final_moves(t_long *game)
{
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->collectible++;
		game->map[game->player_y][game->player_x] = '0';
	}
	if (game->map[game->player_y][game->player_x] == 'E')
	{
		if (game->collectible == game->collectible_total)
		{
			write(1, "\b\b\b\b\b\b\b\b\b\b", 10);
			write(1, "Congratulations! You finished within ", 37);
			ft_putnbr(game->move);
			write(1, " moves.\n", 9);
			exit_and_free(game);
		}
	}
	return (0);
}

int	player_position(t_long *game)
{
	if (game->lastplayer_x != -1)
	{
		get_texture(game->lastplayer_x, game->lastplayer_y, game);
		print_texture(game, game->lastplayer_x, game->lastplayer_y);
	}
	get_texture(game->player_x, game->player_y, game);
	print_texture(game, game->player_x, game->player_y);
	game->texture = 3;
	print_texture(game, game->player_x, game->player_y);
	game->lastplayer_x = game->player_x;
	game->lastplayer_y = game->player_y;
	reset_keyboard(game);
	return (0);
}

void	reset_keyboard(t_long *game)
{
	game->keyboard[ESC] = 0;
	game->keyboard[RIGHT] = 0;
	game->keyboard[LEFT] = 0;
	game->keyboard[BACK] = 0;
	game->keyboard[ADVANCE] = 0;
}
