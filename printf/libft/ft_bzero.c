/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:38:14 by cn-goie           #+#    #+#             */
/*   Updated: 2025/11/10 14:43:14 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*str_temp;

	str_temp = (unsigned char *)str;
	while (n-- > 0)
		*(str_temp++) = 0;
}
