/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:28:39 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/31 11:27:56 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

// int main(void)
// {
// 	char	*str;
// 	char	*str2;
// 	t_list	*head;
// 	t_list	*new_head;
// 	str = "This is head NOW at the start";
// 	head = ft_lstnew((void *)str);
// 	printf("Starting head node is: %s\n", (char *)head->content);
// 	str2 = "This NEW is UPDATED head";
// 	new_head = ft_lstnew((void *)str2);
// 	ft_lstadd_front(&head, new_head);
// 	printf("Updated head node is: %s\n", (char *)new_head->content);
// 	printf("Old node is: %s\n", (char *)new_head->next->content);
// 	free(new_head->next);
// 	free(new_head);
// 	return (0);
// }