/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banthony <banthony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:57:04 by banthony          #+#    #+#             */
/*   Updated: 2019/11/08 18:51:38 by banthony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SERVER_H
# define	SERVER_H

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "utils.h"
#include "libft.h"

# define MAX_PENDING_CLIENT 3
# define MAX_CLIENT 3
# define READ_BUFFER_SIZE 4096
# define SERVER_STARTED "Server has started!\n"
# define NEW_CLIENT "New client connected:"

// Temporary const password (totally unsecure)
# define PASSWORD "4242\n"

typedef struct s_server
{
	int			port;
	int			srv_sock;
	int			srv_log;
	fd_set		masterfdset;
	char		padd[4];
	size_t		clients;
	t_list		*client_lst;
}				t_server;

typedef struct	s_client
{
	t_bool		granted;
	int			socket;
	char		*addr;
}				t_client;

t_bool			create_server(t_server *server, int port);
t_bool			connection_handler(t_server *server);

#endif















