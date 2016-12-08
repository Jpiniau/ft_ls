/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:00:19 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 19:17:03 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include "ls.h"

int		main(int ac, char **av)
{
	DIR *rep;
	DIR *rep2;
	struct dirent *fichier;
	struct dirent *fichier2;
	int i;
	int r = 1;
	char	*tmpjoin;
	t_ls	*info;
	t_list	*new;
	t_list	*list;

	(void)av;
	(void)fichier2;
	(void)r;
	(void)rep2;
	(void)tmpjoin;
	i = 0;
	list = NULL;
	if (ac == 1)
	{
		ft_putendl("ac = 1");
		if ((rep = opendir(".")) == NULL)
			return (0);
		while ((fichier = readdir(rep)) != NULL)
		{
			if (fichier->d_name[0] != '.')
			{
				if ((info = set_info(fichier->d_name, NULL)) != NULL)
				{
					new = ft_lstnew(info, sizeof(t_ls));
					ft_lstaddback(&list, new);
				}
			}
		}
		ft_lstiter(list, print_ls);
		if (r == 1)
		{
			recursive(list);
		}
		list = NULL;
		ft_lstdel(&list, del_ls);
	}
	else
	{
		i = 0;
		while (++i < ac)
			info = set_info(av[i], NULL);
	}
	return (0);
}
