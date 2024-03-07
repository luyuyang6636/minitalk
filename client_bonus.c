/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:07:59 by luyang            #+#    #+#             */
/*   Updated: 2024/01/08 21:08:01 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	g_msglen;

void	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		ft_handle_error("wrong no. of arguments entered, you should "
			"enter the server PID and the string to be sent!");
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
			ft_handle_error("PID should only include numbers!");
	}
	if (!argv[2][0])
		ft_handle_error("empty string!");
}

void	send_msg(pid_t svrpid, char *str)
{
	int	i;

	while (*str)
	{
		i = 8;
		while (i)
		{
			if (*str & 0b10000000)
				kill(svrpid, SIGUSR1);
			else
				kill(svrpid, SIGUSR2);
			usleep(50);
			i--;
			*str <<= 1;
		}
		str++;
	}
}

void	clnthandler(int signum)
{
	if (signum == SIGUSR2)
	{
		if (--g_msglen == 0)
			write(STDOUT_FILENO, "Server has successfully "
				"received the message!\n", 47);
	}
}

void	configsig(void)
{
	struct sigaction	newsig;

	newsig.sa_handler = &clnthandler;
	newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &newsig, NULL) == -1)
		ft_handle_error("Failed to change SIGUSR1's behaviour");
	if (sigaction(SIGUSR2, &newsig, NULL) == -1)
		ft_handle_error("Failure to change SIGUSR2's behaviour");
}

int	main(int argc, char **argv)
{
	pid_t	svrpid;

	svrpid = ft_atoi(argv[1]);
	ft_check_args(argc, argv);
	g_msglen = ft_strlen(argv[2]);
	configsig();
	send_msg(svrpid, argv[2]);
}
