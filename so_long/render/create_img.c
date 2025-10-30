/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:56:48 by brjoves           #+#    #+#             */
/*   Updated: 2023/12/26 12:56:51 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	put_pxl(t_long *game, int x, int y, unsigned int c)
{
	char		*dest;

	if (y >= game->height || x >= game->width || x < 0 \
	|| y < 0)
		return (0);
	dest = game->pxl + game->s_line * y + x * (game->bpp / 8);
	*(unsigned int *)dest = c;
	return (0);
}

int	visible(t_long *game)
{
	render(game);
	player_position(game);
	mlx_put_image_to_window(game->mlx_ptr,
		game->mlx_win, game->img, 0, 0);
	return (0);
}
