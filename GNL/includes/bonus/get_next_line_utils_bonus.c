/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:53:12 by cnatanae          #+#    #+#             */
/*   Updated: 2023/11/18 07:49:31 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_all(t_char **str)
{
	t_char	*aux;

	while (*str)
	{
		aux = (*str)->next;
		free(*str);
		*str = aux;
	}
	return (NULL);
}

t_char	*ft_node(char c)
{
	t_char	*new_node;

	new_node = (t_char *)malloc(sizeof(t_char));
	if (!new_node)
		return (NULL);
	new_node->character = c;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_char *lst, t_list *struc)
{
	int	idx;

	idx = 0;
	while (lst->character != '\n' && lst->next)
	{
		lst = lst->next;
		idx++;
	}
	struc->len = idx;
	return (idx);
}

int	ft_find_n(t_list *struc)
{
	t_char	*aux;

	aux = struc->string;
	while (aux)
	{
		if (aux->character == '\n')
			return (1);
		aux = aux->next;
	}
	return (0);
}

t_char	*add_node_to_end(t_list *struc, t_char *end, char c)
{
	t_char	*new_node;

	new_node = ft_node(c);
	if (!new_node)
	{
		free(struc->buffer);
		free(struc[struc->fd].buffer);
		return (free_all(&struc->string));
	}
	if (end)
		end->next = new_node;
	else
		struc->string = new_node;
	return (new_node);
}
