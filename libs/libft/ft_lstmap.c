/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:54:22 by pcottet           #+#    #+#             */
/*   Updated: 2021/02/19 15:18:36 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_tmp;
	t_list	*lst_first;

	if (!lst || !f)
		return (NULL);
	lst_first = ft_lstnew(f(lst->content));
	if (!(lst))
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		lst_tmp = ft_lstnew(f(lst->content));
		if (!(lst_tmp))
		{
			ft_lstclear(&lst_first, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_first, lst_tmp);
		lst = lst->next;
	}
	return (lst_first);
}
