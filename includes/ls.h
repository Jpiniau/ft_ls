/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiniau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:16:45 by jpiniau           #+#    #+#             */
/*   Updated: 2016/11/10 16:21:15 by jpiniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

int		is_dir(char *in);
char	*get_perm(char *in);
char	*get_uid(char *in);
char	*get_gid(char *in);
int		get_size(char *in);
char	*get_mod(char *in);
int		get_link(char *in);

#endif
