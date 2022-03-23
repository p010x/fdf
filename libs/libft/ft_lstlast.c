/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <pcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:21:48 by pcottet           #+#    #+#             */
/*   Updated: 2020/10/16 01:26:18 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_tmp;

	if (!lst)
		return (NULL);
	lst_tmp = lst;
	while (lst_tmp->next)
		lst_tmp = lst_tmp->next;
	return (lst_tmp);
}
