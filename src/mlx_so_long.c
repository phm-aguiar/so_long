/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:29:49 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/12 19:22:09 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_and_defines_so_long.h"

void	mlx_error_sl(char *str, t_sl *sl)
{
	int	i;
	int	k;

	i = -1;
	mlx_terminate(sl->mlx);
	k = sl->recurses.total_key;
	while (++i < k)
		mlx_delete_texture(sl->collectable[i].texture);
	i = -1;
	while (++i < 5)
		mlx_delete_texture(sl->image[i].texture);
	ft_error(str, sl, 42);
}

void	mlx_work(t_sl *sl)
{
	sl->recurses.total_key = sl->recurses.collectibles;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	sl->mlx = mlx_init(sl->map_file.width * 64, sl->map_file.height * 64,
			"papacu", 1);
	if (!sl->mlx)
		ft_error("mlx_init() failed", sl, 42);
	counter_wall(sl);
	all_image(sl);
	map_creator(sl);
	mlx_key_hook(sl->mlx, &my_keyhook, (void *)sl);
	mlx_loop(sl->mlx);
}
