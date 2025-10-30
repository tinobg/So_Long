/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:56:04 by brjoves           #+#    #+#             */
/*   Updated: 2024/01/01 19:40:10 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file(char *str, t_long *game)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
	{
		i = open(str, O_RDONLY);
		if (i == -1)
			error_msg(game, "Invalid file name");
		else
			close(i);
		return (0);
	}
	error_msg(game, "File must be .ber type");
	return (0);
}

int	floodandfill(t_long *game, int mapy, int mapx)
{
	if (game->map[mapy][mapx] == 'a' ||
	game->map[mapy][mapx] == 'c' || game->map[mapy][mapx] == 'd'
	|| game->map[mapy][mapx] == 'e')
	{
		if (check_walls(mapx, mapy, game) == 0)
			error_msg(game, "Map must be surrounded by walls");
		floodandfill2(game, mapy, mapx);
		floodandfill(game, mapy, mapx + 1);
		floodandfill(game, mapy, mapx - 1);
		floodandfill(game, mapy + 1, mapx);
		floodandfill(game, mapy - 1, mapx);
	}
	return (1);
}

void	floodandfill2(t_long *game, int mapy, int mapx)
{
	if (game->map[mapy][mapx] == 'a')
		game->map[mapy][mapx] = '0';
	if (game->map[mapy][mapx] == 'c')
		game->map[mapy][mapx] = 'P';
	if (game->map[mapy][mapx] == 'd')
	{
		game->map[mapy][mapx] = 'E';
		game->exits_found++;
	}
	if (game->map[mapy][mapx] == 'e')
	{
		game->map[mapy][mapx] = 'C';
		game->collectibles_found++;
	}
}

int	check_walls(int mapx, int mapy, t_long *game)
{
	if (game->map[0][0] != '1' || game->map[0][game->x - 1] != '1' ||
		game->map[game->y - 1][0] != '1' ||
		game->map[game->y - 1][game->x - 1] != '1')
	{
		error_msg(game, "Corners must be surrounded by walls");
		return (0);
	}
	if (mapy == 0 || mapy == game->y - 1
		|| mapx == 0 || mapx == game->x - 1)
		error_msg(game, "Map must be surrounded by walls");
	if (checkifgood(game->map[mapy + 1][mapx]) == 0)
		return (0);
	if (checkifgood(game->map[mapy - 1][mapx]) == 0)
		return (0);
	if (checkifgood(game->map[mapy][mapx + 1]) == 0)
		return (0);
	if (checkifgood(game->map[mapy][mapx - 1]) == 0)
		return (0);
	return (1);
}

int	check_walls2(t_long *game)
{
	int	mapx;
	int	mapy;

	mapy = (int)game->player_x;
	mapx = (int)game->player_y;
	game->collectibles_found = 0;
	game->exits_found = 0;
	floodandfill(game, mapx, mapy + 1);
	floodandfill(game, mapx, mapy - 1);
	floodandfill(game, mapx + 1, mapy);
	floodandfill(game, mapx, mapy - 1);
	if (game->collectibles_found != game->collectible_total)
		error_msg(game, "Collectibles are misplaced");
	if (game->exits_found == 0)
		error_msg(game, "No exit found");
	return (0);
}
