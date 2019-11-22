/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:28:52 by banthony          #+#    #+#             */
/*   Updated: 2019/11/22 12:01:08 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "Durex.h"
#include "server.h"
#include "Daemon.h"
#include "libft.h"

static t_bool	is_root(char *bin)
{
	if (getgid())
	{
		printf("%s :%s\n", bin, "Permission denied, please run as root.");
		return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	t_server server;

	(void)ac;
	if (!is_root(av[0]))
		return (EXIT_FAILURE);
	puts("banthony\nlfourque");
	if (!daemonize("./"))
	{
		durex_log("Daemonize failed.", LOG_ERROR);
		return (EXIT_FAILURE);
	}
	durex_log("======== Durex  has started! ========", LOG_WARNING);
	install_service(av[0]);
	ft_memset(&server, 0, sizeof(server));
	server.require_pass = true;
	if (create_server(&server, 4242, MAX_CLIENT))
		server_loop(&server);
	return (EXIT_SUCCESS);
}
