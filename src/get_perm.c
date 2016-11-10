/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_perm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:45:37 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 14:45:38 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

char	*get_perm(char *in)
{
	char	*perm;
	struct stat filestat;

	if (stat(in, &filestat) < 0)
		return (NULL);
	perm = ft_strdup("---------");
	perm[0] = filestat.st_mode & S_IRUSR ? 'r' : '-';
	perm[1] = filestat.st_mode & S_IWUSR ? 'w' : '-';
	perm[2] = filestat.st_mode & S_IXUSR ? 'x' : '-';
	perm[3] = filestat.st_mode & S_IRGRP ? 'r' : '-';
	perm[4] = filestat.st_mode & S_IWGRP ? 'w' : '-';
	perm[5] = filestat.st_mode & S_IXGRP ? 'x' : '-';
	perm[6] = filestat.st_mode & S_IROTH ? 'r' : '-';
	perm[7] = filestat.st_mode & S_IWOTH ? 'w' : '-';
	perm[8] = filestat.st_mode & S_IXOTH ? 'x' : '-';
	return (perm);
}
