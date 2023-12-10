/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:19:35 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/10 00:30:25 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*fill_stack(int ac, char **av, t_stack **stack)
{
	int		i;
	int		ret;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < ac)
	{
		ret = set_node(av[i], &node, stack);
		if (!ret)
		{
			i = 0;
			if (node)
				free(node);
			if (stack)
			{
				while (stack[i])
				{
					free(stack[i]);
					stack[i] = NULL;
					i++;	
				}
			}
			print_error();
		}
	}
	if (!node->next)
		(*stack)->bottom = node;
	while (node->prev)
		node = node->prev;
	return (node);
}
