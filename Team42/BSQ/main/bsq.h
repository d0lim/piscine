/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung-j <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 03:50:44 by lyoung-j          #+#    #+#             */
/*   Updated: 2018/08/15 03:50:47 by lyoung-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_linecolumn
{
	int			line;
	int			column;
	char		info[3];
}				t_lc;

typedef struct	s_loop
{
	int			i;
	int			j;
	int			max;
	int			m;
}				t_loop;

typedef struct	s_small_loop
{
	int			i;
	int			j;
}				t_ij;

char			*ft_strcpy(char *dest, char *src);
char			*recalloc(char *ptr, size_t size);
int				info_line(char buf, char **info_string);
int				column_count(char buf, t_lc *lc);
t_lc			*get_info(char *name, char ***qst);
int				buf_check(char ***qst, char buf, t_lc *lc, t_ij *ij);
t_lc			*get_file(char *name, char ***qst);
int				ft_min(int a, int b, int c);
void			solve_mark(char ***solved, t_lc *lc, t_loop *lp);
void			solve_draw(int **grid, char ***solved, t_lc *lc, t_loop *lp);
void			solve_alloc(char ***solved, t_lc *lc);
void			solve_print(int **grid, int max, t_lc *lc);
void			input_data(char ***qst, t_lc *lc);
void			column_realloc(char ***qst, t_lc *lc);
t_lc			*input(char ***qst);
void			prb_sol(int **prb, int ***sol, t_lc *lc, int *max);
int				qst_prb(char **qst, int ***prb, t_lc *lc);
void			alloc2arr(int ***arr, t_lc *lc);
int				after_input(t_lc *lc, char **qst);
void			info_realloc(char **info_string, char buf);
void			read_info(t_lc *lc, char *info_string);

#endif
