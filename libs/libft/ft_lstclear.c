/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:49:06 by pcottet           #+#    #+#             */
/*   Updated: 2021/02/19 14:47:41 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_tmp;

	if (*lst)
	{
		lst_tmp = *lst;
		while (lst_tmp)
		{
			if (del)
				del(lst_tmp->content);
			*lst = lst_tmp->next;
			free(lst_tmp);
			lst_tmp = *lst;
		}
		lst = NULL;
	}
}
