#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_data
{
	int		*a;
	int		*b;
	char	*inst;
	int		len_a;
	int		len_b;
	int		*sorted;
}	t_data;
/*remplissage*/
void		ft_remplir(t_data *stack, char **av);
void		ft_read_arguments(t_data *stack, char **argv);
void		ft_sort_table(t_data *stack);
int			check_overflow(long r);
/*gnl functions*/
int			ft_finish(char **str, char **line);
int			ft_remplissage(char **str, char **line, int len);
int			ft_read(int fd, char **str);
int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
/*checker*/
long		ft_atoi(const char *str);
int			ft_error(char *error);
int			ft_success(char *success);
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_allocate( int argc);
int			ft_read_instructions(t_data *stack);
int			ft_instructions(t_data *stack);
int			ft_free(t_data *stack);
int			ft_isdigit(char c);
void		ft_check_numbers(char **argv);
int			ft_check_sort(t_data *stack);

/*instructions*/
int			rotate(t_data *stack);
int			reverte(t_data *stack);
int			swap(t_data *stack);
void		pa_instruction(t_data *stack);
void		pb_instruction(t_data *stack);
void		sa_instruction(t_data *stack);
void		sb_instruction(t_data *stack);
void		ss_instruction(t_data *stack);
void		rra_instruction(t_data *stack);
void		rrb_instruction(t_data *stack);
void		rrr_instruction(t_data *stack);
void		ra_instruction(t_data *stack);
void		rb_instruction(t_data *stack);
void		rr_instruction(t_data *stack);
#endif