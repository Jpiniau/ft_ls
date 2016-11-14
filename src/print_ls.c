/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:23:30 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 17:33:16 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ls.h"

void	print_ls(t_list	*elem)
{
	t_ls	*data;

	data = (t_ls *)elem->content;
	ft_putstr(data->name);
	ft_putstr("    ");
}
