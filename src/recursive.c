/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:03:14 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 18:28:23 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include "ls.h"

void	recursive(t_list *list)
{
	DIR *rep2;
	struct dirent *fichier2;
	char *tmpjoin;
	t_ls	*rinfo;
	t_ls	*info;
	t_list	*new;
	t_list	*rlist;

	rlist = NULL;
	rinfo = NULL;
	while (list != NULL)
	{
		info = (t_ls *)list->content;
		if (is_dir(info->name) == 1 && (rep2 = opendir(info->name)) != NULL )
		{
			ft_putstr("\n./");
			ft_putstr(info->name);
			ft_putendl(":");
			while ((fichier2 = readdir(rep2)) != NULL)
			{
				if (fichier2->d_name[0] != '.')
				{
					tmpjoin = ft_strjoin(info->name, ft_strjoin("/", fichier2->d_name));
					rinfo = set_info(tmpjoin, info);
					new = ft_lstnew(rinfo, sizeof(t_ls));
					ft_lstaddback(&rlist, new);
					free(tmpjoin);
				}
			}
			ft_lstiter(rlist, print_ls);
			//ft_lstdel(&rlist, del_ls);
			rlist = NULL;
			ft_putendl("");
		}
		list = list->next;
	}
}
