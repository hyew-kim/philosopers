#include "philosoper.h"

int	phlio_start(t_rule *rule)
{
	int		i;
	t_philo	*philo;
	
	i = -1;
	rule->run = 0;
	while (++i < rule->total_philo)
	{
		philo = &rule->philo[i];
		if (pthread_create(&philo->thread, NULL, routine, (void *)(philo)))
			return (ERR);
	}
	rule->begin = get_time_ms();
	rule->run = 1;
	i = -1;
	while (++i < rule->total_philo)
		pthread_join(rule->philo[i].thread, NULL);
	return (SUC);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	philo = (t_philo *)arg;
	
	while (philo->rule->run == 0)
		usleep(1);
	print_condition(100, philo);
	if (philo->id % 2)
		loop(100);
	while (1)
	{
		if (get_fork(philo))
			break;
		eating(philo);
		put_fork(philo);
		if (philo->eat_count >= philo->rule->limit)
			philo->rule->cnt_full_philo++;
		if (philo->rule->cnt_full_philo >= philo->rule->total_philo)
			break;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}