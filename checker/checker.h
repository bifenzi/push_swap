#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

/*gnl functions*/
int		ft_finish(char **str, char **line);
int		ft_remplissage(char **str, char **line, int len);
int		ft_read(int fd, char **str);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
/*checker*/
int		    ft_atoi(const char *str);
int         ft_error(char *error);
size_t	    ft_strlen(const char *str);
int		    ft_strcmp(const char *s1, const char *s2);
int     ft_instructions(char **inst, int *stack, int len);


#endif