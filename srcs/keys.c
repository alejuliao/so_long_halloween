/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuliao- <ajuliao-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:30 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/16 15:35:59 by ajuliao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_hook(mlx_key_data_t key, void *param)
{
	t_so_long	*data;

	data = (t_so_long *)param;
	if (key.key == MLX_KEY_ESCAPE)
		my_errors(data, 1,"You leave the presents to Sandy Claws ");
	// refazer - verificar se é parede ou nao - refazer as keys
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		// ft_printf(">>Y:%d",data->images.jack->instances[0].y /64);
		// ft_printf(">>X:%d",data->images.jack->instances[0].x /64);
		no_wall(data->images.jack->instances[0].y, data);
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
	// ft_printf("%d\n", data->moves);
}
void	no_wall(int	position, t_so_long *data)
{
	int x;
	int y;

	y = data->images.jack->instances[0].y /64;
	x = data->images.jack->instances[0].x /64;
	if(data->map.matrix[x][y + 1] != '1')
	{
		ft_printf("errrrro");
	}
	else
	{
		data->images.jack->instances[0].y -= 64;
	}
}
