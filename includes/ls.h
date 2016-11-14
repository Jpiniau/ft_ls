/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:16:45 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/14 18:32:56 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

#include <sys/stat.h>

typedef struct	s_ls
{
	char		*name;
	char		*path;
	struct stat	stat;
}				t_ls;

int		is_dir(char *file);
char	*get_perm(struct stat filestat);
char	*get_uid(struct stat filestat);
char	*get_gid(struct stat filestat);
int		get_size(struct stat filestat);
int		get_mod(struct stat filestat);
int		get_link(struct stat filestat);
void	recursive(t_list *list);
t_ls	*set_info(char *file, t_ls *parent);
void	print_ls(t_list *elem);
void	del_ls(void *elem, size_t size);

#endif
