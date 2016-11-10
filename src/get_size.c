/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:09:12 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 15:22:42 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/stat.h>
#include <pwd.h>
#include "libft.h"

int		get_size(char *in)
{
	struct stat filestat;

	if (stat(in, &filestat) < 0)
		return (-1);
	return (filestat.st_size);
}
