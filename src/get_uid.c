/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:14:22 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 11:56:21 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/stat.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include "libft.h"

char	*get_uid(struct stat filestat)
{
	struct passwd *pwuid;
	char	*uid;

	if ((pwuid = getpwuid(filestat.st_uid)) == NULL)
		uid = ft_itoa(filestat.st_uid);
	else
		uid = pwuid->pw_name;
	return (uid);
}
