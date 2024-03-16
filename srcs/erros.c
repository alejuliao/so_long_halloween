/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuliao- <ajuliao-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:04:44 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/16 12:02:41 by ajuliao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ffree(t_so_long *data)
{
	int	i;

	i = 0;
	while(data->map.matrix[i])
		free(data->map.matrix[i++]);
	free(data->map.matrix);
}

void	my_errors(t_so_long *data, int mlx_valid, char *message)
{
	ft_printf("%s\n", message);
	if(data->map.matrix != NULL)
		ffree(data);
	if(mlx_valid == 1)
	{
		mlx_terminate(data->mlx);
		exit(0);
	}
	else
	{
		exit(1);
	}
}
