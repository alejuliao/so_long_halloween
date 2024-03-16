/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuliao- <ajuliao-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:34:09 by ajuliao-          #+#    #+#             */
/*   Updated: 2024/03/16 10:37:17 by ajuliao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long int n)
{
	int	count;

	count = 0;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	if (n < 10)
		count++;
	return (count);
}

// char	*ft_itoa(int n)
// {
// 	char		*result;
// 	long int	num;
// 	int			count;
// 	int			i;

// 	num = n;
// 	if (n < 0)
// 		num *= -1;
// 	count = ft_count(num);
// 	if (n < 0)
// 		count++;
// 	result = (char *)malloc(sizeof(char) * count + 1);
// 	if (result == 0)
// 		return (0);
// 	i = 0;
// 	while (i < count)
// 	{
// 		result[count - i - 1] = num % 10 + '0';
// 		num = num / 10;
// 		i++;
// 	}
// 	if (n < 0)
// 		result[0] = '-';
// 	result[i] = '\0';
// 	return (result);
// }

char	*ft_itoa_u(unsigned int n)
{
	char		*result;
	long int	num;
	int			count;
	int			i;

	num = n;
	count = ft_count(num);
	result = (char *)malloc(sizeof(char) * count + 1);
	if (result == 0)
		return (0);
	i = 0;
	while (i < count)
	{
		result[count - i - 1] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	result[i] = '\0';
	return (result);
}
