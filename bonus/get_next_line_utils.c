/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmoreil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:14:30 by thmoreil          #+#    #+#             */
/*   Updated: 2023/06/17 14:14:32 by thmoreil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	n_search(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		return (i);
	else
		return (-1);
}

int	mv_first_line(char *str, char **dest)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		dest[0] = malloc(1);
		dest[0][0] = 0;
		return (0);
	}
	while (str[i] != '\n' && str[i] != 0 && str[i] != EOF)
		i++;
	dest[0] = malloc(sizeof(char) * i + 1);
	if (!(dest[0]))
		return (-1);
	dest[0][i--] = 0;
	while (i >= 0)
	{
		dest[0][i] = str[i];
		i--;
	}
	return (1);
}

char	*sup_first_line(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	new_str = NULL;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if ((len - i++ - 1) >= 0)
	{
		new_str = malloc(sizeof(*new_str) * len + 1);
		if (!(new_str))
			return (0);
		while (j < len)
		{
			new_str[j] = str[i++];
			j++;
		}
		new_str[j] = 0;
	}
	free(str);
	return (new_str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((unsigned char)s1[i] != '\0')
		&& ((unsigned char)s2[i] != '\0')
		&& (i < n - 1))
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	int			i;

	if (s == NULL || *s == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
