/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:29:11 by cdapurif          #+#    #+#             */
/*   Updated: 2021/04/22 18:23:17 by curtman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		cpt;

	cpt = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		cpt++;
	}
	return (cpt);
}
