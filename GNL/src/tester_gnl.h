/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_gnl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:20:01 by cnatanae          #+#    #+#             */
/*   Updated: 2023/11/18 10:41:23 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_GNL_H
# define TESTER_GNL_H


# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "minunit.h"
# include "../includes/get_next_line.h"
# ifdef BONUS
#  include "../includes/bonus/get_next_line_bonus.h"
#endif

int	main(void);

#endif
