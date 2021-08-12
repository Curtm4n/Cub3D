/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:46:44 by cdapurif          #+#    #+#             */
/*   Updated: 2021/05/05 23:09:31 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_at(t_list **begin_list, unsigned int nbr)
{
	unsigned int	i;
	t_list			*ptr;

	if (!begin_list)
		return (NULL);
	ptr = *begin_list;
	i = 0;
	while (ptr && i < nbr)
	{
		i++;
		ptr = ptr->next;
	}
	if (i < nbr && !ptr)
		return (NULL);
	return (ptr);
}
