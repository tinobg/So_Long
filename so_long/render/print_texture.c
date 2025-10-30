/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:42:52 by brjoves           #+#    #+#             */
/*   Updated: 2023/12/16 15:42:57 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_textures(t_long *game)
{
	game->text[0] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./images/floor-64.xpm",
			&game->widthtext[0], &game->heighttext[0]);
	game->ptr_text[0] = mlx_get_data_addr(game->text[0],
			&(game->bpp_text[0]), &(game->sline_text[0]), &(game->ed_text[0]));
	game->text[1] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./images/walls-64t.xpm",
			&game->widthtext[1], &game->heighttext[1]);
	game->ptr_text[1] = mlx_get_data_addr(game->text[1],
			&(game->bpp_text[1]), &(game->sline_text[1]), &(game->ed_text[1]));
	game->text[3] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./images/player.xpm",
			&game->widthtext[3], &game->heighttext[3]);
	return (0);
}

int	load_textures2(t_long *game)
{
	game->ptr_text[3] = mlx_get_data_addr(game->text[3],
			&(game->bpp_text[3]), &(game->sline_text[3]), &(game->ed_text[3]));
	game->text[2] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./images/collectible.xpm",
			&game->widthtext[2], &game->heighttext[2]);
	game->ptr_text[2] = mlx_get_data_addr(game->text[2],
			&(game->bpp_text[2]), &(game->sline_text[2]), &(game->ed_text[2]));
	game->text[4] = mlx_xpm_file_to_image(game->mlx_ptr, \
					"./images/exit.xpm",
			&game->widthtext[4], &game->heighttext[4]);
	game->ptr_text[4] = mlx_get_data_addr(game->text[4],
			&(game->bpp_text[4]), &(game->sline_text[4]), &(game->ed_text[4]));
	return (0);
}

int	print_texture(t_long *game, int starter_X, int starter_Y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->heighttext[game->texture])
	{
		while (x < game->widthtext[game->texture])
		{
			game->color = *(unsigned int *)(game->ptr_text[game->texture]
					+ game->sline_text[game->texture] * y + x
					* (game->bpp_text[game->texture] / 8));
			if (game->color != 0)
			{
				put_pxl(game, starter_X * 64 + x, starter_Y * 64 + \
						y, game->color);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	get_texture(int X, int Y, t_long *game)
{
	if (game->map[Y][X] == '0' || game->map[Y][X] == 'a')
		game->texture = 0;
	if (game->map[Y][X] == '1')
		game->texture = 1;
	if (game->map[Y][X] == 'C')
		game->texture = 2;
	if (game->map[Y][X] == 'E')
		game->texture = 4;
	if (game->map[Y][X] == 'P')
		game->texture = 0;
	return (0);
}
