/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:21:00 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 19:17:37 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include "ls.h"

t_ls	*set_info(char *file, t_ls *parent)
{
	static int nooption = 0;
	struct stat	filestat;
	t_ls	*info;

	if (!ft_strcmp(file, "--") || file[0]!= '-')
		nooption = 1;
	if (nooption == 1)
	{
		if (stat(file, &filestat) >= 0)
		{
			if (!(info = (t_ls *)malloc(sizeof(t_ls))))
				return (NULL);
		}
		else
			return (NULL);
		info->name = ft_strdup(file);
		if (!parent)
		//Seg fault ==NULL pas bon
			info->path = ft_strdup("./");
		else
			info->path = ft_strdup(ft_strjoin(parent->path, ft_strjoin(parent->name, "/")));
		info->stat = filestat;
		return (info);
	}
	return (NULL);
}
