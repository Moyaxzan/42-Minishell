/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elrichar <elrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:25:18 by elrichar          #+#    #+#             */
/*   Updated: 2023/11/03 16:01:53 by elrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "structs.h"

/*------------------env.c-----------------*/
int		get_env(char *env[], t_data *data);
void	free_env(t_env **lst_env);

#endif