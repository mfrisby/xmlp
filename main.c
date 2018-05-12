#include "incs/xmlp.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_xmlp	*xmlp;

	if (ac > 1)
	{
		xmlp = new_xmlp(av[1]);
		if (!xmlp)
		{
			printf("Something went wrong\n");
			return (-1);
		}
		//printf("content:\n%s\n", xmlp->content);
		printf("file_size: %d\n", xmlp->len);
		printf("path: %s\n", xmlp->path);
		printf("fd: %d\n", xmlp->fd);
	}
	return (0);
}