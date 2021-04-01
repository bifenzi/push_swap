#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

int		    ft_atoi(const char *str);
int         ft_error(char *error);
size_t	    ft_strlen(const char *str);

#endif