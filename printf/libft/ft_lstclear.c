/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:29:17 by afabbri           #+#    #+#             */
/*   Updated: 2023/02/10 18:54:44 by afabbri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstsecondlast(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*secondlast;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		if ((*lst)->next)
		{
			secondlast = ft_lstsecondlast(*lst);
			del(secondlast->next->content);
			free(secondlast->next);
			secondlast->next = NULL;
		}
		else
		{
			del((*lst)->content);
			free(*lst);
			*lst = NULL;
		}
	}
}
