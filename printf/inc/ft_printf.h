/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:04:56 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/04 13:07:50 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	check_format(char c, va_list args);
int	ft_putunbr_count(unsigned int nb);
int	ft_putunbr_base_count(unsigned long nb, char *base);

#endif