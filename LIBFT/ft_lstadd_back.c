/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:01:07 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/31 12:28:37 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL || new == NULL)
	{
		*lst = new;
		return ;
	}
	if (*lst)
		ft_lstlast(*lst)-> next = new;
}

// int main(void)
// {
// 	char	*str;
// 	char	*str2;
// 	t_list	*head;
// 	t_list	*added;
// 	str = "This is head NOW at the start";
// 	head = ft_lstnew((void *)str);
// 	printf("Starting head node is: %s\n", (char *)head->content);
// 	str2 = "This NEW added node";
// 	added = ft_lstnew((void *)str2);
// 	ft_lstadd_back(&head, added);
// 	printf("LAst node is: %s\n", (char *)head->next->content);
// 	free(head->next);
// 	free(head);
// 	return (0);
// }