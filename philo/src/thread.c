#include "philosoper.h"

void	*r(void *arg)
{
	t_philo *ph;

	ph =  (t_philo*)arg;
	while (ph->rule->run == 0)
		usleep(1);
	ph->current = get_time_ms();
	print_condition(100, ph);
	return (NULL);
}

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
	printf("Thread make\n");
	rule->begin = get_time_ms();
	rule->run = 1;
	printf("%lldms Waiting\n", get_time_ms() - rule->begin);
	for (int i=0;i<rule->total_philo;++i)
		pthread_join(rule->philo[i].thread, NULL);
	printf("%lldms Done\n", get_time_ms() - rule->begin);
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
		/*if (philo->rule->limit && philo->eat_count == philo->rule->limit)
			if (++(philo->rule->cnt_eat) >= philo->rule->total_philo)
				break;*/
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}