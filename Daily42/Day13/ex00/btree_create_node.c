/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolim <dolim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 22:52:45 by dolim             #+#    #+#             */
/*   Updated: 2018/08/09 23:38:16 by dolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*newnode;

	newnode = malloc((t_btree*)sizeof(newnode));
	newnode->item = item;
	newnode->left = 0;
	newnode->right = 0;
	return (newnode);
}
