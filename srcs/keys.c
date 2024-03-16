/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:30 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/15 22:47:53 by alexandreju      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_hook(mlx_key_data_t key, void *param)
{
	t_so_long	*data;

	data = (t_so_long *)param; 
	// refazer - verificar se é parede ou nao - refazer as keys
	if (key.key == MLX_KEY_ESCAPE)
		my_erros(data, 1,"You leave the presents to Sandy Claws ");
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		data->images.jack->instances[0].y -= 64;
	}
	if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		data->images.jack->instances[0].y += 64;
	}
	if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		data->images.jack->instances[0].x -= 64;
	}
	if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		data->images.jack->instances[0].x += 64;
	}
	// data->moves = data->moves + 1;
	// refazer - contador
	ft_printf("%d\n", data->moves);
}
