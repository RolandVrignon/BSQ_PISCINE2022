/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eannesta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:33:42 by eannesta          #+#    #+#             */
/*   Updated: 2022/03/27 23:33:43 by eannesta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*process_split_value(char *str, char *ret)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		ret[i] = *str;
		i++;
		str++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_split_value(char *str)
{
	char	*ret;
	int		i;

	while (*str >= '0' && *str <= '9')
		str++;
	while (*str == ' ')
		str++;
	if (*str != ':')
		return (NULL);
	else
		str++;
	while (*str == ' ')
		str++;
	i = 0;
	while (str[i] != '\0')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	ret = process_split_value(str, ret);
	return (ret);
}

// t_dict	*create_element(char *str, t_dict *tmp)
// {
// 	t_dict	*elem;

// 	elem = (t_dict *)malloc(sizeof(t_dict));
// 	elem->key = ft_split_key(str);
// 	elem->value = ft_split_value(str);
// 	elem->next = NULL;
// 	elem->previous = tmp;
// 	return (elem);
// }

// void	add_element(char *str, t_dict *elem)
// {
// 	t_dict	*tmp;

// 	while (elem->next != NULL)
// 		elem = elem->next;
// 	tmp = elem;
// 	elem->next = create_element(str, tmp);
// }

// t_dict	*create_list(int ac, char *file)
// {
// 	t_dict	*dict;
// 	int		fd;
// 	int		i;
// 	char	read_buffer[1000];
// 	char	**lines;

// 	fd = open(file, O_RDONLY);
// 	if (fd != -1 && ac)
// 	{
// 		read(fd, read_buffer, 1000);
// 		close(fd);
// 		lines = ft_split(read_buffer, "\n");
// 		i = 0;
// 		dict = create_element(lines[i], 0);
// 		while (lines[i] != NULL)
// 		{
// 			add_element(lines[i], dict);
// 			i++;
// 		}
// 		lines[i] = 0;
// 	}
// 	return (dict);
// }
