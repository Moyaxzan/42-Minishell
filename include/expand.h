/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:50:45 by tsaint-p          #+#    #+#             */
/*   Updated: 2023/12/05 12:57:33 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H
# include "structs.h"

/*-------------asterisk.c-------------*/
char	**expand_wildcard(char *str);

/*--------------expand.c--------------*/
int		expand(t_node *node, char **env);

/*-----------expand_utils.c-----------*/
int		is_varsep(char c);
int		nonvarlen(char *str, int quote, int i);
char	**sumtab(char **t1, char **t2);
char	**tab_addback(char **tab, char *new);

/*----------expand_process.c----------*/
char	*expand_exceptions(char *str, int *i);
char	*get_nonvarstr(char *str, int *i, int *quote);
char	*get_varstr(char *str, int *i, char **env);

#endif
