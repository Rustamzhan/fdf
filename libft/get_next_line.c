/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kreilly <kreilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 21:32:58 by kreilly           #+#    #+#             */
/*   Updated: 2019/04/15 13:25:26 by kreilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*find_fd(size_t fd, t_list *root)
{
	t_list	*p;

	if (root == NULL)
		return (NULL);
	p = root;
	while (p->content_size != fd)
	{
		if (p->next == NULL)
			return (NULL);
		p = p->next;
	}
	return (p);
}

void	make_new_list(t_list **root, char *buff, size_t fd)
{
	t_list *p;

	if ((p = find_fd(fd, *root)))
		p->content = buff;
	else
	{
		p = ft_lstnew(NULL, 0);
		p->content = buff;
		p->content_size = fd;
		ft_last_list_add(root, p);
	}
}

int		makeline(char **line, char **buff, size_t size_buff)
{
	char	*temp_line;
	char	*temp_buff;
	char	*n;
	int		size;

	if ((n = ft_strchr(*buff, '\n')) == NULL)
	{
		temp_line = ft_strjoin(*line, *buff);
		free(*line);
		*line = temp_line;
		return ((ft_strlen(*line) < size_buff) ? 1 : 0);
	}
	size = n - *buff;
	(*buff)[size] = '\0';
	temp_line = ft_strjoin(*line, *buff);
	temp_buff = ft_strdup(&(*buff)[size + 1]);
	ft_strdel(buff);
	*buff = temp_buff;
	ft_strdel(line);
	*line = temp_line;
	return (1);
}

int		check_ostatok(size_t fd, t_list **root, t_list **p_fd, char **line)
{
	if ((*p_fd = find_fd((size_t)fd, *root)) != NULL && (*p_fd)->content)
	{
		if ((makeline(line, ((char**)(&(*p_fd)->content)),
				ft_strlen((*p_fd)->content))) > 0)
			return (1);
		else
			ft_strdel((char**)&(*p_fd)->content);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	int				r;
	static t_list	*root;
	t_list			*p;

	buff = NULL;
	IF_RET((fd < 0 || !line || BUFF_SIZE < 1 || (read(fd, buff, 0) < 0)), -1);
	*line = ft_strnew(1);
	IF_RET((check_ostatok((size_t)fd, &root, &p, line) == 1), 1);
	IF_RET(!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))), -1);
	ft_bzero(buff, (size_t)BUFF_SIZE);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (makeline(line, &buff, ft_strlen(buff)) > 0)
			break ;
		ft_bzero(buff, (size_t)BUFF_SIZE);
	}
	(buff && *buff) ? make_new_list(&root, buff, (size_t)fd) : ft_strdel(&buff);
	IF_RET((**line || (!**line && r > 0) || (p && p->content != NULL)), 1);
	ft_destroy_element(&root, &p);
	ft_strdel(line);
	return (0);
}
