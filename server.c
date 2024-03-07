/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:08:06 by luyang            #+#    #+#             */
/*   Updated: 2024/01/08 21:08:08 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	svrhandler(int signum, siginfo_t *info, void *context)
{
	static int				bit_rot = 7;
	static unsigned char	c;

	(void)context;
	if (bit_rot == -1)
		bit_rot = 7;
	if (signum == SIGUSR1)
		c |= 1 << bit_rot;
	bit_rot--;
	if (bit_rot == -1)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_handle_error("Server failed to send"
				"back character received message!");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_handle_error("Server failed to send back SIGUSR1!");
}

void	configsig(void)
{
	struct sigaction	newsig;

	newsig.sa_sigaction = &svrhandler;
	newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &newsig, NULL) == -1)
		ft_handle_error("Failure to change SIGUSR1's behaviour");
	if (sigaction(SIGUSR2, &newsig, NULL) == -1)
		ft_handle_error("Failure to change SIGUSR2's behaviour");
}

int	main(void)
{
	pid_t	svrpid;

	svrpid = getpid();
	ft_printf("The server PID is: %d \n", svrpid);
	while (1)
		configsig();
}
