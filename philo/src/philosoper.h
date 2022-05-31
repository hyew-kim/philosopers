/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosoper.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:06:51 by hyewkim           #+#    #+#             */
/*   Updated: 2022/05/31 17:23:22 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPER_H
# define PHILOSOPER_H

/*include*/
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

/*macro*/
# define PHILO_MAX 200
# define TIME_MIN 60

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mu;

typedef enum e_flag{
	SUC = 0,
	ERR,
	FORK,
	EAT,
	THINK,
	SLEEP,
	DEAD
}t_flag;
/*struct*/
typedef struct s_philo
{
	int				id;
	int				eat_count;
	t_th			thread;
	long long		last_eat;
	int				fork_l;
	int				fork_r;
	struct s_rule	*rule;
}					t_philo;

typedef struct s_rule
{
	int				total_philo;
	int				time_dead;
	int				time_eat;
	int				time_sleep;
	int				limit;
	int				cnt_full_philo;
	t_mu			f[PHILO_MAX];
	t_mu			print;
	t_mu			eat;
	t_philo			philo[PHILO_MAX];
	long long		begin;
	int				run;
	int				dead;
}					t_rule;

/*prototype*/
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				loop(long long interval);

long long			get_time_ms(void);
int					set_struct(int argc, char *argv[], t_rule *rule);
int					set_mutex(t_rule *rule);
int					phlio_start(t_rule *rule);
int					ft_exit(int flag, char *message, t_rule *rule);
void				print_exit(int flag, char *message, t_rule *rule);
void				print_condition(int flag, t_philo *philo);
void				*routine(void *arg);

int					get_fork(t_philo *philo);
int					eating(t_philo *philo);
int					put_fork(t_philo *philo);
int					sleeping(t_philo *philo);
int					thinking(t_philo *philo);

void				check_full(t_rule *rule);
void				check_dead(t_rule *rule);
#endif
