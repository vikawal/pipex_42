/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:41:41 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/31 11:28:33 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
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
// 	printf("%d\n", ft_lstsize(new_head));
// 	free(new_head->next);
// 	free(new_head);
// 	return (0);
// }