/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:02:12 by conoel            #+#    #+#             */
/*   Updated: 2019/04/28 15:41:20 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*concat(char *s1, char *s2, char *s3)
{
	size_t len;
	char	*ret;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	ret = malloc(sizeof(char) * len + 1);
	ft_bzero(ret, len);
	ft_strcat(ret, s1);
	ft_strcat(ret, s2);
	ft_strcat(ret, s3);
	return (ret);
}