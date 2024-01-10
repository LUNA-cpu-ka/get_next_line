/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 09:17:48 by saait-si          #+#    #+#             */
/*   Updated: 2024/01/10 11:50:54 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *gt_read_line(int fd, char *stash)
{
    char *buffer;
    ssize_t byte_read;
    
    byte_read = 1;
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if(!buffer)
        return(free(stash), NULL);
    while (byte_read > 0)
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if(byte_read <= 0)   
            break ;
        buffer[byte_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        free(stash);
        if(ft_strchr(buffer, '\n'))
            break ;  
    }
    free(buffer);
    if(byte_read <= 0 && (ft_strlen(stash) == 0))
        return(free(stash), NULL);
    return(stash);
}
char *get_next_line(int fd)
{
    static char stash;
    char *line;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    stash = malloc(sizeof(char));
    if(!stash)
        return(NULL);
    if(!ft_strchr(stash, '\n'))
        stash = gt_read_line(fd,stash);
    if(!stash)
        return(NULL);
    line = get_line();
    stash = get_rest();
    return(line);
}