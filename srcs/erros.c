/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:04:44 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/15 22:43:28 by alexandreju      ###   ########.fr       */
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

void	my_erros(t_so_long *data, int mlx_valid, char *message)
{
	ft_printf("%s\n", message);
	ffree(data);
	if(mlx_valid)
	{
		mlx_terminate(data->mlx);	
		exit(0);
	}
	else
	{	
			exit(1);
	}
}
