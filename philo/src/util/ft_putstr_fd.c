/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyewonkim <hyewonkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 00:28:37 by hyewkim           #+#    #+#             */
/*   Updated: 2022/04/17 18:22:33 by hyewonkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosoper.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, strlen((const char *)s));
	return ;
}
