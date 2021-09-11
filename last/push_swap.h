/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:09:12 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/09/11 18:48:34 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_data
{
	int     *a;
    int     *b;
    char    *inst;
    int     *len_a;
    int     *len_b;
    int     *max_len;
}           t_data;

int    ft_stack_b(t_data stack);
int    ft_stack_a(t_data stack, int len2);
int    ft_check_sort_b(t_data stack);
int    ft_finish_him(t_data stack, int len2);
//int  ft_execute_sort(t_data stack)

/*gnl functions*/
int		    ft_finish(char **str, char **line);
int		    ft_remplissage(char **str, char **line, int len);
int		    ft_read(int fd, char **str);
int		    get_next_line(int fd, char **line);
char	    *ft_strdup(const char *s);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    *ft_strchr(const char *s, int c);
/*checker*/
long		ft_atoi(const char *str);
int         ft_error(char *error);
int         ft_success(char *success);
size_t	    ft_strlen(const char *str);
int		    ft_strcmp(const char *s1, const char *s2);
//void        ft_allocate(t_data stack, , int argc);
void        ft_args(t_data stack, char **argv);
int         ft_read_instructions(t_data stack);
int         ft_instructions(t_data stack);         
int         ft_free(t_data stack);
int		    ft_isdigit(char c);
void        ft_check_numbers(char **argv);
void        ft_check_duplicate(t_data stack);
int         ft_check_sort(t_data stack);
int         *ft_read_arguments(t_data stack, int *a, char **argv);

/*instructions*/
void         pa_instruction(t_data stack);
int          pb_instruction(t_data stack);

void         sa_instruction(t_data stack, int l);
void         sb_instruction(t_data stack, int l);
void         ss_instruction(t_data stack);
void         rra_instruction(t_data stack, int k);
void         rrb_instruction(t_data stack, int k);
void         rrr_instruction(t_data stack);
void         ra_instruction(t_data stack, int j);
void         rb_instruction(t_data stack, int j);
void         rr_instruction(t_data stack);
void	     ft_pa_instruction(t_data  stack, int len2);
void         ft_generate_instructions(t_data stack, int len );
//

// split
// static int		ft_hm(char const *s, char c);
// static char		**ft_mal(char **strs, char const *s, char c);
// static char		**ft_cpy(char **strs, char const *s, char c);
// char			**ft_split(char const *s, char c);

int *ft_sort_table(int *a);

#endif