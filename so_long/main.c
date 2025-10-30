/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:55:51 by brjoves           #+#    #+#             */
/*   Updated: 2023/12/26 12:58:20 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_long	so_long;

	variables_init(&so_long);
	if (ac == 1)
		error_msg(&so_long, "Type a map to open");
	if (ac > 2)
		error_msg(&so_long, "Invalid arguments (too many)");
	parsing(&so_long, av[1]);
	display(&so_long);
	return (0);
}
