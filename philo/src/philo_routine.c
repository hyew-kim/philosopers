#include "philosoper.h"

int	get_fork(t_philo *philo)
{
	int	l;
	int	r;

	l = philo->fork_l;
	r = philo->fork_r;
	print_condition(FORK, philo);
	if (l == r)
		return (ERR);
	pthread_mutex_lock(&philo->rule->f[l]);
	print_condition(FORK, philo);
	pthread_mutex_lock(&philo->rule->f[r]);
	return (SUC);
}

int	eating(t_philo *philo)
{
	philo->eat_count++;
	print_condition(EAT, philo);
	loop(philo->rule->time_eat);
	return (SUC);
}

int	put_fork(t_philo *philo)
{
	int	l;
	int	r;

	l = philo->fork_l;
	r = philo->fork_r;
	pthread_mutex_unlock(&philo->rule->f[l]);
	pthread_mutex_unlock(&philo->rule->f[r]);
	return(SUC);
}

int	sleeping(t_philo *philo)
{
	print_condition(SLEEP, philo);
	loop(philo->rule->time_sleep);
	return (SUC);
}

int	thinking(t_philo *philo)
{
	print_condition(THINK, philo);
	return (SUC);
}