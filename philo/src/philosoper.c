/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosoper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:06:43 by hyewkim           #+#    #+#             */
/*   Updated: 2022/06/26 15:39:02 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosoper.h"

int	main(int argc, char *argv[])
{
	t_rule	rule;
	int		i;

	if (argc != 5 && argc != 6)
		return (ft_exit(ERR, "Input Error", &rule));
	i = 0;
	while (++i < argc)
	{
		if (ft_strncmp(argv[i], "0", 1) && ft_atoi(argv[i]) <= 0)
			return (ft_exit(ERR, "Input Error", &rule));
	}
	if (set_struct(argc, argv, &rule))
		return (ft_exit(ERR, "Setting Error", &rule));
	if (set_mutex(&rule))
		return (ft_exit(ERR, "Mutex Setting Error", &rule));
	if (phlio_start(&rule))
		return (ft_exit(ERR, "Thread Error", &rule));
	return (ft_exit(SUC, "", &rule));
}

int	set_struct(int argc, char *argv[], t_rule *rule)
{
	int	i;

	rule->total_philo = ft_atoi(argv[1]);
	rule->time_dead = ft_atoi(argv[2]);
	rule->time_eat = ft_atoi(argv[3]);
	rule->time_sleep = ft_atoi(argv[4]);
	rule->limit = 0;
	rule->cnt_full_philo = 0;
	if (argc == 6)
		rule->limit = ft_atoi(argv[5]);
	if (rule->total_philo < 1 || rule->total_philo > 200 || rule->time_dead < 0
		|| rule->time_eat < 0 || rule->time_sleep < 0 || rule->limit < 0)
		return (ERR);
	i = -1;
	while (++i < rule->total_philo)
	{
		rule->philo[i].id = i;
		rule->philo[i].eat_count = 0;
		rule->philo[i].fork_l = i;
		rule->philo[i].fork_r = i - 1;
		if (i == 0)
			rule->philo[i].fork_r = rule->total_philo - 1;
		rule->philo[i].rule = rule;
	}
	return (SUC);
}

int	set_mutex(t_rule *rule)
{
	int	i;

	i = -1;
	while (++i < rule->total_philo)
		if (pthread_mutex_init(&rule->f[i], NULL))
			return (ERR);
	if (pthread_mutex_init(&rule->print, NULL))
		return (ERR);
	if (pthread_mutex_init(&rule->eat, NULL))
		return (ERR);
	return (SUC);
}

int	ft_exit(int flag, char *message, t_rule *rule)
{
	int	i;

	i = -1;
	if (ft_strncmp(message, "Input", 5) && ft_strncmp(message, "Setting", 7))
	{
		pthread_mutex_destroy(&rule->print);
		pthread_mutex_destroy(&rule->eat);
		while (++i < rule->total_philo)
		{
			pthread_mutex_destroy(&rule->f[i]);
			pthread_detach(rule->philo[i].thread);
		}
	}
	if (flag == ERR)
	{
		print_exit(ERR, message, rule);
		return (EXIT_FAILURE);
	}
	else
	{
		return (EXIT_SUCCESS);
	}
}
