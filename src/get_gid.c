/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:46:26 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 11:57:13 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include "libft.h"

char	*get_gid(struct stat filestat)
{
	struct group *grgid;
	char	*gid;

	if ((grgid = getgrgid(filestat.st_gid)) == NULL)
		gid = ft_itoa(filestat.st_gid);
	else
		gid = grgid->gr_name;
	return (gid);
}
