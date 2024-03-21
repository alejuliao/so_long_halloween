/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:30 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/20 22:35:48 by laj              ###   ########.fr       */
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
		move(0, -64, data);
	}
	if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		move(0, +64, data);
	}
	if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		move(-64, 0, data);
	}
	if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
	{
		move(+64, 0, data);

	}
	// data->moves = data->moves + 1;
	// refazer - contador
	// ft_printf("%d\n", data->moves);
}
void	move(int position_x, int position_y, t_so_long *data)
{
	int x;
	int y;
	int i;

	i = 0;
	x = data->images.jack->instances[0].x + position_x;
	y = data->images.jack->instances[0].y + position_y;
	if (check_walls(data, x, y))
	{
		data->images.jack->instances[0].x = x;
		data->images.jack->instances[0].y = y;
	}

}


int	check_walls(t_so_long *data, int x, int y)
{
	int	wall_x;
	int	wall_y;
	int	i;

	i = -1;
	while (data->numbers.wall > ++i)
	{
		wall_x = data->images.wall->instances[i].x;
		wall_y = data->images.wall->instances[i].y;
		if (x == wall_x && y == wall_y)
			return (0);
	}
	return (1);
}
