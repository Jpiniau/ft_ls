/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:00:19 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 17:18:56 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include "libft.h"
#include "ls.h"

void	get_options(char *file)
{
	int i;
	int nooption;
	static int affnoop = 1;
	char	*perm;
	char	*uid;
	char	*gid;
	char	*mod;

	i = 0;
	nooption = 0;
	if (!ft_strcmp(file, "--") || file[0]!= '-')
		nooption = 1;
	if (nooption == 1)
	{
		if (affnoop == 1)
		{
			ft_putendl("\nno_option:");
			affnoop = 0;
		}
		ft_putstr(file);
		ft_putendl(" :");
		if (is_dir(file) == 1)
			ft_putstr("DIR - ");
		else if (is_dir(file) == 0)
			ft_putstr("FILE - ");
		if ((perm = get_perm(file)) != NULL)
		{
			ft_putstr(perm);
			free(perm);
		}
		ft_putstr(" - ");
		if ((i = get_link(file)) != -1)
			ft_putnbr(i);
		ft_putstr(" - ");
		if ((uid = get_uid(file)) != NULL)
		{
			ft_putstr(uid);
		}
		ft_putstr(" - ");
		if ((gid = get_gid(file)) != NULL)
		{
			ft_putstr(gid);
		}
		ft_putstr(" - ");
		if ((i = get_size(file)) != -1)
			ft_putnbr(i);
		ft_putstr(" - ");
		if ((mod = get_mod(file)) != NULL)
		{
			ft_putstr(mod);
			free(mod);
		}
	}
	ft_putendl("\n");
}

int		main(int ac, char **av)
{
	DIR *rep;
	DIR *rep2;
	struct dirent *fichier;
	struct dirent *fichier2;
	int i;
	int r = 0;
	char	*tmpjoin;

	(void)av;
	if (ac == 1)
	{
		if ((rep = opendir(".")) == NULL)
			return (0);
		while ((fichier = readdir(rep)) != NULL)
		{
			get_options(fichier->d_name);		
		}
		if (r == 1)
		{
			ft_putendl("TEST RRRRRRRRRRRRRRRRRRRR");
			if ((rep = opendir(".")) != NULL)
			{
				while ((fichier = readdir(rep)) != NULL)
				{
					if (is_dir(fichier->d_name) == 1 && (rep2 = opendir(fichier->d_name)) != NULL )
					{
						ft_putendl("--------");
						ft_putendl(fichier->d_name);
						ft_putendl("--------");
						while ((fichier2 = readdir(rep2)) != NULL)
						{
							tmpjoin =ft_strjoin(fichier->d_name, ft_strjoin("/",fichier2->d_name));
							get_options(fichier->d_name);
							free(tmpjoin);
						}
					}
				}
			}
		}
	}
	else
	{
		i = 0;
		while (++i < ac)
			get_options(av[i]);
	}
	while (1);
	return (0);
}
