/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:53:33 by cn-goie           #+#    #+#             */
/*   Updated: 2025/12/04 13:07:05 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

int	ft_putchar_count(char c);
int	ft_putstr_count(char *str);
int	ft_putnbr_count(int n);
int	ft_putunbr_count(unsigned int nb);
int	ft_putptr_count(void *ptr);

#endif