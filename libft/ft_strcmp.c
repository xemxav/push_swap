/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 15:05:44 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 15:05:47 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] != '\0' && (unsigned char)s2 != '\0' &&
	(unsigned char)s2[i] == (unsigned char)s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
