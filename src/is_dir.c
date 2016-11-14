/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:06:27 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 14:21:49 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int		is_dir(char *file)
{
	struct stat filestat;

	if (stat(file, &filestat) < 0)
		return (-1);
	if (S_ISDIR(filestat.st_mode))
		return (1);
	return (0);
}
