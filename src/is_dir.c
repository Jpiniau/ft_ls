/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:06:27 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 13:53:47 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int		is_dir(char *in)
{
	struct stat filestat;

	if (stat(in, &filestat) < 0)
		return (-1);
	if (S_ISDIR(filestat.st_mode))
		return (1);
	return (0);
}
