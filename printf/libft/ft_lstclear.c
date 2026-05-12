/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cn-goie <cn-goie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:39:35 by cn-goie           #+#    #+#             */
/*   Updated: 2025/11/10 14:43:56 by cn-goie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*backup;

	if (!(*del) || !lst || !*lst)
		return ;
	backup = *lst;
	while (*lst && lst)
	{
		*lst = backup->next;
		ft_lstdelone(backup, (*del));
		backup = *lst;
	}
}
