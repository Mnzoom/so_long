/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:40:33 by cn-goie           #+#    #+#             */
/*   Updated: 2025/11/10 14:40:35 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*desttemp;
	unsigned char	*srctemp;

	desttemp = (unsigned char *)dest;
	srctemp = (unsigned char *)src;
	if ((!src) && (!dest))
		return (dest);
	while (n > 0)
	{
		*(desttemp++) = *(srctemp++);
		n--;
	}
	return (dest);
}
