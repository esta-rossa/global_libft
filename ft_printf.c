/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arraji <arraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 07:38:46 by arraji            #+#    #+#             */
/*   Updated: 2019/12/04 16:52:16 by arraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		*declare(void)
{
	t_data *new;

	if (!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	new->type = 0;
	new->flag = 0;
	new->printed = NULL;
	new->fill_char = ' ';
	new->printed_c = 0;
	new->precision = 0;
	new->width = 0;
	new->size_rt = 0;
	new->pr_size = 0;
	new->index = 0;
	return (new);
}

int			strc_end(t_data **ptr, int rt)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (rt);
}

/*
**	X x u i		d p s c
**	0 0 0 0		0 0 0 0
*/

int			here_we_go(const char *arg1, va_list ar, t_data *data)
{
	int ret;

	ret = 1;
	(data->index)++;
	check_flag(arg1, ar, data);
	if (!(data->type = check_type(arg1[(data->index)])))
		ft_putchar_fd(arg1[(data->index)++], 1);
	else if (data->type == C_T)
		print_char(ar, data);
	else if (data->type == S_T)
		ret = print_string(ar, data);
	else if (data->type == P_T)
		ret = print_pointer(ar, data);
	else if (data->type == D_T)
		ret = print_decimal(ar, data);
	else if (data->type == U_T)
		ret = print_unsigned(ar, data);
	else if (data->type == X_T || data->type == XX_T)
		ret = print_hexa(ar, data);
	else if (data->type == PERC)
		print_perc(data);
	ft_reset(data);
	return (ret);
}

int			ft_printf(const char *arg1, ...)
{
	t_data				*data;
	va_list				ar;
	int					ret;

	ret = 0;
	data = declare();
	va_start(ar, arg1);
	while (arg1[data->index])
	{
		if (arg1[data->index] == '%')
			ret = here_we_go(arg1, ar, data);
		else
		{
			ft_putchar_fd(arg1[(data->index)++], 1);
			(data->size_rt)++;
		}
		if (ret == -1)
		{
			va_end(ar);
			return (strc_end(&data, -1));
		}
	}
	ret = data->size_rt;
	va_end(ar);
	return (strc_end(&data, ret));
}
