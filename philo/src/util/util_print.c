/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewkim <hyewkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:07:15 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/26 21:07:19 by hyewkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosoper.h"

void	print_exit(int flag, char *message, t_rule *rule)
{
	pthread_mutex_lock(&rule->print);
	if (flag == ERR)
		ft_putendl_fd(message, 2);
	else if (flag == SUC)
		ft_putendl_fd(message, 1);
	pthread_mutex_unlock(&rule->print);
	return ;
}

void	print_condition(int flag, t_philo *philo)
{
	long long	current;
	long long	start_time;

	pthread_mutex_lock(&philo->rule->print);
	current = get_time_ms();
	start_time = philo->rule->begin;
	if (flag == FORK)
		printf("%lldms %d has taken a fork\n", current - start_time, philo->id);
	else if (flag == EAT)
		printf("%lldms %d is eating\n", current - start_time, philo->id);
	else if (flag == SLEEP)
		printf("%lldms %d is sleeping\n", current - start_time, philo->id);
	else if (flag == THINK)
		printf("%lldms %d is thinking\n", current - start_time, philo->id);
	else if (flag == DEAD)
		printf("%lldms %d is died\n", current - start_time, philo->id);
	pthread_mutex_unlock(&philo->rule->print);
	return ;
}
