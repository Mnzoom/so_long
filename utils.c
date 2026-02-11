/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clementngoie <clementngoie@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:55:29 by clementngoi       #+#    #+#             */
/*   Updated: 2026/02/11 15:23:13 by clementngoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_doc(int fd, char *buf, char *backup)
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
	static char	*backup;
	char		*line;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE +1));
	if (!buf)
		return (NULL);
	line = read_doc(fd, buf, backup);
	if (line == NULL)
		free (backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = set_line(line);
	return (line);
}

void free_grid(char **grid, int height)
{
    int i;

    i = 0;
    while (i < height)
    {
        free(grid[i]);
        i++;
    }
    free(grid);
}