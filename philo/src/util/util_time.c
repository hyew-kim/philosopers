#include "../philosoper.h"

long long	get_time_ms(void)
{
	struct timeval	now;
	long long		time;
	
	if (gettimeofday(&now, NULL) < 0)
		return (ERR);
	time = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (time);
}

void	loop(long long interval)
{
	long long	termination;

	termination = interval + get_time_ms();
    while (termination > get_time_ms())
		;
	return ;
}