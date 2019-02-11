/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrestles <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:13:27 by vrestles          #+#    #+#             */
/*   Updated: 2018/12/10 19:13:17 by vrestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define CHECK(x) if (x == NULL) return (-1)

int		get_next_line(const int fd, char **line);

#endif
