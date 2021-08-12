/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:36:12 by cdapurif          #+#    #+#             */
/*   Updated: 2021/08/05 16:36:56 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_back_mod(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

static t_list	*ft_lstnew_mod(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

static void	ft_lstclear_mod(t_list *ptr, void (*del)(void *))
{
	t_list	*tmp;

	while (ptr)
	{
		tmp = ptr->next;
		(*del)(ptr->content);
		free(ptr);
		ptr = tmp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new_elem;

	if (!f || !del || !lst)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		new_elem = ft_lstnew_mod((*f)(lst->content));
		if (!new_elem)
		{
			ft_lstclear_mod(ptr, del);
			return (NULL);
		}
		ft_lstadd_back_mod(&ptr, new_elem);
		lst = lst->next;
	}
	return (ptr);
}
