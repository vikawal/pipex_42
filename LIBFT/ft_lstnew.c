/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:42:45 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/31 11:22:18 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_box_node;

	new_box_node = malloc(sizeof(t_list));
	if (new_box_node == NULL)
		return (NULL);
	new_box_node -> content = content;
	new_box_node -> next = NULL;
	return (new_box_node);
}

// int main(void)
// {
// 	char	*str;
// 	t_list	*new_node;
// 	str = "Let's try";
// 	new_node = ft_lstnew((void *)str);
// 	printf("%s\n", (char *)new_node->content);
// 	free (new_node);
// 	return (0);
// }