/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:25:30 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 17:35:59 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ls.h"

void	del_ls(void *elem, size_t size)
{
	t_ls	*data;

	(void)size;
	data = (t_ls *)elem;
	free(data->name);
	free(data->path);
	free(elem);
	data->name = NULL;
	data->path = NULL;
	elem = NULL;
}
