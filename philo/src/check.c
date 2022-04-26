/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:06:30 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/26 21:06:33 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosoper.h"

void	check_dead(t_rule *rule)
{
	int			i;
	long long	chk_time;

	while (rule->dead == 0)
	{
		check_full(rule);
		i = 0;
		while (i < rule->total_philo && rule->dead == 0)
		{
			pthread_mutex_lock(&(rule->eat));
			chk_time = get_time_ms() - rule->philo[i].last_eat;
			if (chk_time > rule->time_dead)
			{
				print_condition(DEAD, &rule->philo[i]);
				rule->dead = 1;
			}
			pthread_mutex_unlock(&(rule->eat));
			i++;
		}
	}
}

void	check_full(t_rule *rule)
{
	int	i;

	i = -1;
	while (rule->limit && ++i < rule->total_philo
		&& rule->philo[i].eat_count >= rule->limit)
		rule->cnt_full_philo++;
	if (rule->cnt_full_philo >= rule->total_philo)
		rule->dead = 1;
	return ;
}