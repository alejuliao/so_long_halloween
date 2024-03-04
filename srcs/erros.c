/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laj <laj@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:04:44 by laj               #+#    #+#             */
/*   Updated: 2024/03/03 14:06:12 by laj              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ffree(t_so_long *data)
{
	int	i; //fazer um free pra quando der erro de leitura

	i = 0;
	while(data->map.matrix[i])
	{
		free(data->map.matrix[i++]);
	}
	free(data->map.matrix);
	// mlx_terminate(data->mlx);
}
