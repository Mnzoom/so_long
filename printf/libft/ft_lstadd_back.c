/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:39:24 by cn-goie           #+#    #+#             */
/*   Updated: 2025/11/10 14:43:52 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;

	start = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (start->next)
			start = start->next;
		start->next = new;
	}
}
