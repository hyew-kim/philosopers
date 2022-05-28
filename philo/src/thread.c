/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:07:05 by hyewkim           #+#    #+#             */
/*   Updated: 2022/05/28 16:46:54 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosoper.h"

int	phlio_start(t_rule *rule)
{
	int		i;
	t_philo	*philo;

	i = -1;
	rule->run = 0;
	rule->dead = 0;
	while (++i < rule->total_philo)
	{
		philo = &rule->philo[i];
		philo->last_eat = get_time_ms();
		if (pthread_create(&philo->thread, NULL, routine, (void *)(philo)))
			return (ERR);
	}
	rule->begin = get_time_ms();
	rule->run = 1;
	check_dead(rule);
	return (SUC);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->rule->run == 0)
		usleep(1);
	if (philo->id % 2)
		loop(philo->rule->time_eat);
	while (philo->rule->dead == 0)
	{
		if (get_fork(philo))
			break ;
		eating(philo);
		put_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
