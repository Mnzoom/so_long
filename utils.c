/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:55:29 by clementngoi       #+#    #+#             */
/*   Updated: 2026/01/28 14:10:17 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_doc(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (!(backup && ft_strchr(backup, '\n')) && read_line > 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*set_line(char *line_buffer)
{
	size_t	count;
	size_t	total_len;
	char	*backup;

	count = 0;
	while (line_buffer[count] != '\n' && line_buffer[count] != '\0')
		count++;
	if (line_buffer[count] == '\0')
		return (NULL);
	total_len = ft_strlen(line_buffer);
	backup = ft_substr(line_buffer, count + 1, total_len - (count + 1));
	if (backup && backup[0] == 0)
	{
		free(backup);
		backup = NULL;
	}
	line_buffer[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[MAX_FD];
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buf)
		return (NULL);
	line = read_doc(fd, buf, backup[fd]);
	if (line == NULL)
		free (*backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup[fd] = set_line(line);
	return (line);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		str = (malloc(sizeof(char)));
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while ((s[start + i]) && (i < len))
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while ((s[start + i]) && (i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}