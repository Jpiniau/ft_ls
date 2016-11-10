/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:14:22 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 14:45:53 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/stat.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "libft.h"

char	*get_uid(char *in)
{
	struct stat filestat;
	struct passwd *pwuid;
	char	*uid;

	if (stat(in, &filestat) < 0)
		return (NULL);
	if ((pwuid = getpwuid(filestat.st_uid)) == NULL)
		uid = ft_itoa(filestat.st_uid);
	else
		uid = pwuid->pw_name;
	return (uid);
}
