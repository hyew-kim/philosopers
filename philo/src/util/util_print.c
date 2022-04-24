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
	pthread_mutex_lock(&philo->rule->print);
	if (flag == FORK)
		printf("%lldms %d has taken a fork\n", philo->current - philo->rule->begin, philo->id);
	else if (flag == EAT)
		printf("%lldms %d is eating\n", philo->current - philo->rule->begin,philo->id);
	else if (flag == SLEEP)
		printf("%lldms %d is sleeping\n", philo->current - philo->rule->begin, philo->id);
	else if (flag == THINK)
		printf("%lldms %d is thinking\n", philo->current - philo->rule->begin, philo->id);
	else if (flag == DEAD)
		printf("%lldms %d is died\n", philo->current - philo->rule->begin, philo->id);
	pthread_mutex_unlock(&philo->rule->print);
	return ;
}