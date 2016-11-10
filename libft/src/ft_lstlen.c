#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != next)
	{
		lst = lst->next;
		size++
	}
	retrun size;
}
