/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:40:44 by cn-goie           #+#    #+#             */
/*   Updated: 2025/11/10 14:40:46 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	unsigned char	*str_temp;

	str_temp = (unsigned char *)str;
	while (len > 0)
	{
		*(str_temp++) = (unsigned char)value;
		len--;
	}
	return (str);
}
