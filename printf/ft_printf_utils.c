/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:05:28 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/04 15:39:23 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_count(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_count(int n)
{
	int			count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_count("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar_count('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_count(n / 10);
	count += ft_putchar_count(n % 10 + '0');
	return (count);
}

int	ft_putunbr_count(unsigned int nb)
{
	char	mod;
	int		count;

	count = 0;
	mod = nb % 10 + '0';
	if (nb / 10 != 0)
		count += ft_putunbr_count(nb / 10);
	write (1, &mod, 1);
	return (count + 1);
}

int	ft_putptr_count(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	else
	{
		count += ft_putstr_count("0x");
		count += ft_putunbr_base_count((unsigned long)ptr, "0123456789abcdef");
	}
	return (count);
}
