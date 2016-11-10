/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:46:26 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 15:05:58 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include "libft.h"

char	*get_gid(char *in)
{
	struct stat filestat;
	struct group *grgid;
	char	*gid;

	if (stat(in, &filestat) < 0)
		return (NULL);
	if ((grgid = getgrgid(filestat.st_gid)) == NULL)
		gid = ft_itoa(filestat.st_gid);
	else
		gid = grgid->gr_name;
	return (gid);
}
