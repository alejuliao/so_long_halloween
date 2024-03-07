/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erros.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandrejuliao <alexandrejuliao@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:04:44 by laj               #+#    #+#             */
/*   Updated: 2024/03/06 20:16:14 by alexandreju      ###   ########.fr       */
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

void	my_erros(t_so_long *data, char *message)
{
	ft_printf("%s\n", message);
	ffree(data);
	mlx_terminate(data->mlx);
	exit(0);
}
