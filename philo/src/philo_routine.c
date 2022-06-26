/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:06:58 by hyewkim           #+#    #+#             */
/*   Updated: 2022/06/26 16:20:06 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosoper.h"

int	get_fork(t_philo *philo)
{
	int	l;
	int	r;

	l = philo->fork_l;
	r = philo->fork_r;
	if (l == r)
		return (ERR);
	if (philo->rule->dead)
		return (ERR);
	pthread_mutex_lock(&philo->rule->f[l]);
	pthread_mutex_lock(&philo->rule->f[r]);
	print_condition(FORK, philo);
	print_condition(FORK, philo);
	return (SUC);
}

int	eating(t_philo *philo)
{
	if (philo->rule->dead)
		return (ERR);
	print_condition(EAT, philo);
	philo->eat_count++;
	philo->last_eat = get_time_ms();
	loop(philo->rule->time_eat);
	return (SUC);
}

int	put_fork(t_philo *philo)
{
	int	l;
	int	r;

	if (philo->rule->dead)
		return (ERR);
	l = philo->fork_l;
	r = philo->fork_r;
	pthread_mutex_unlock(&philo->rule->f[l]);
	pthread_mutex_unlock(&philo->rule->f[r]);
	return (SUC);
}

int	sleeping(t_philo *philo)
{
	if (philo->rule->dead)
		return (ERR);
	print_condition(SLEEP, philo);
	loop(philo->rule->time_sleep);
	return (SUC);
}

int	thinking(t_philo *philo)
{
	if (philo->rule->dead)
		return (ERR);
	print_condition(THINK, philo);
	return (SUC);
}
