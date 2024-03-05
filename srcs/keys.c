/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:50:30 by alexandreju       #+#    #+#             */
/*   Updated: 2024/03/05 20:11:28 by laj              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_hook(mlx_key_data_t key, void *param)
{
	mlx_t* mlxx = (mlx_t *)param;
	t_so_long	*data;

	data = (t_so_long*)param;
	if (key.key == MLX_KEY_ESCAPE)
	{
		ffree(data);
		mlx_terminate(data->mlx);
		exit(0);
		// mlx_close_window(mlx);
	}
}


