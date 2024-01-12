
#include "get_next_line.h"

char	*ft_read_to_temp(int fd, char *temp)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(temp, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(temp);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	free(buff);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = ft_read_to_temp(fd, temp);
	if (!temp)
		return (NULL);
	line = ft_get_line(temp);
	temp = ft_new_temp(temp);
	return (line);
}

int main(){
	int fd = open("text.txt", 'r');
	char *resu;
	while ((resu = get_next_line(fd))!= NULL)
	{
		printf("%s",resu);
		free(resu);
	}
	close(fd);
}