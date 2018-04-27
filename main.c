#include "incs/xmlp.h"
#include <stdio.h>

int			main(void)
{
	t_xmlp	*xmlp;

	xmlp = new_xmlp("files/note.xml");
	printf("content:\n%s\n", xmlp->content);
	printf("file_size: %d\n", xmlp->len);
	printf("path: %s\n", xmlp->path);
	printf("fd: %d\n", xmlp->fd);
	return (0);
}