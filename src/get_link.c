/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:17:37 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 16:22:25 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

int		get_link(char *in)
{
	struct stat filestat;

	if (stat(in, &filestat) < 0)
		return (-1);
	return (filestat.st_nlink);
}
