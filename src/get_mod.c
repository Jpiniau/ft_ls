/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:33:22 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 16:10:52 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>
#include <stddef.h>
#include <time.h>

char	*get_mod(char *in)
{
	struct stat filestat;

	if (stat(in, &filestat) < 0)
		return (NULL);
	return (ft_strndup(ctime(&filestat.st_mtime) + 4, 12));
}
