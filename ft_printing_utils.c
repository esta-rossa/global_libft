/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 13:10:39 by arraji            #+#    #+#             */
/*   Updated: 2019/12/04 17:27:08 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hexa(va_list ar, t_data *data)
{
	int max;

	if (x_type(ar, data) == -1)
		return (-1);
	max = (data->flag & PRE) == PRE ? 0 : data->pr_size;
	if (((data->flag & PRE) == PRE) && (data->flag & CRI) == 0)
		while ((data->printed)[max] != '\0')
			max++;
	if ((data->flag & LE_ALI) == LE_ALI && (data->flag & CRI) == 0)
	{
		ft_putstr_fd(data->printed, 1);
		data->size_rt += ft_strlen(data->printed, 1);
	}
	while ((data->width)-- > max && (data->flag & WIDTH) == WIDTH)
	{
		ft_putchar_fd(data->fill_char, 1);
		(data->size_rt)++;
	}
	if ((data->flag & LE_ALI) == 0 && (data->flag & CRI) == 0)
	{
		ft_putstr_fd(data->printed, 1);
		data->size_rt += ft_strlen(data->printed, 1);
	}
	return (ft_end(&(data->printed), NULL, 1));
}

void	print_string_utils(t_data *data, int type)
{
	int jndex;

	jndex = 0;
	if (type > 0)
	{
		while ((data->printed)[jndex] != '\0' &&
		(data->flag & LE_ALI) == LE_ALI)
		{
			if (jndex >= data->precision && (data->flag & PRE) == PRE)
				break ;
			ft_putchar_fd((data->printed)[jndex++], 1);
			(data->size_rt)++;
		}
	}
	else
	{
		while ((data->printed)[jndex] != '\0' && (data->flag & LE_ALI) == 0)
		{
			if (jndex >= data->precision && (data->flag & PRE) == PRE)
				break ;
			ft_putchar_fd((data->printed)[jndex++], 1);
			(data->size_rt)++;
		}
	}
}

void	print_pointer_utils(t_data *data, int type)
{
	if (type > 0)
	{
		data->size_rt = (data->flag & LE_ALI) == LE_ALI ?
		data->size_rt + 2 : data->size_rt;
		if ((data->flag & LE_ALI) == LE_ALI)
			ft_putstr_fd("0x", 1);
		if ((data->flag & LE_ALI) == LE_ALI && (data->flag & CRI) == 0)
		{
			ft_putstr_fd(data->printed, 1);
			(data->size_rt) += ft_strlen(data->printed, 1);
		}
	}
	else
	{
		data->size_rt = (data->flag & LE_ALI) == 0 ?
		data->size_rt + 2 : data->size_rt;
		if ((data->flag & LE_ALI) == 0)
			ft_putstr_fd("0x", 1);
		if ((data->flag & LE_ALI) == 0 && (data->flag & CRI) == 0)
		{
			ft_putstr_fd(data->printed, 1);
			(data->size_rt) += ft_strlen(data->printed, 1);
		}
	}
}

void	print_perc(t_data *data)
{
	int rt;

	rt = 0;
	data->pr_size = 1;
	if ((data->flag & LE_ALI) == LE_ALI)
		ft_putchar_fd('%', 1);
	while ((data->width)-- > data->pr_size && (data->flag & WIDTH) == WIDTH)
	{
		ft_putchar_fd(data->fill_char, 1);
		(data->size_rt)++;
	}
	if ((data->flag & LE_ALI) == 0)
		ft_putchar_fd('%', 1);
	(data->size_rt)++;
	(data->index)++;
}
