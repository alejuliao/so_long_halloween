/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:13:11 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/26 19:41:25 by laj              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_so_long *data)
{
	mlx_texture_t	*logo; //colocar na lista
	int				height;
	int				width;

	data->moves = 0;
	width = data->map.column * 64;
	height = data->map.line * 64;
	data->mlx = mlx_init(width, height, "The Nightmare Before Christmas", true);
	logo = mlx_load_png(PUMPKIN); //colocar na lista
	mlx_set_icon(data->mlx, logo); //colocar na lista
	create_image(data, &data->images.background, BACKGROUND);
	create_image(data, &data->images.wall, WALL);
	create_image(data, &data->images.jack, JACK);
	create_image(data, &data->gift->image, GIFT);
	create_image(data, &data->images.tree, TREE);
	mlx_resize_image(data->images.background, width, height);
	mlx_resize_image(data->images.jack, 0, 64);
	mlx_resize_image(data->gift->image, 64, 64);
	mlx_resize_image(data->images.wall, 64, 64);
	mlx_resize_image(data->images.tree, 0, 0);
	draw_walls(data, 64, 64);
	mlx_key_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
}
