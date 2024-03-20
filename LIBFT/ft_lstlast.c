/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:33:16 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/31 11:56:38 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

// int main(void)
// {
// 	char	*str;
// 	char	*str2;

// 	t_list	*result;
// 	t_list	*head;
// 	t_list	*new_head;
// 	str = "This is head NOW at the start";
// 	head = ft_lstnew((void *)str);
// 	printf("Starting head node is: %s\n", (char *)head->content);
// 	str2 = "This NEW is UPDATED head";
// 	new_head = ft_lstnew((void *)str2);
// 	ft_lstadd_front(&head, new_head);
// 	printf("Updated head node is: %s\n", (char *)new_head->content);
// 	// printf("Old node is: %s\n", (char *)new_head->next->content);
// 	result = ft_lstlast(new_head);
// 	printf("Old node is LAST: %s\n", (char *)result->content);
// 	free(new_head->next);
// 	free(new_head);
// 	return (0);
// }