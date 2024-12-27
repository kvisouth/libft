/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:05:48 by kevisout          #+#    #+#             */
/*   Updated: 2024/12/27 18:06:00 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			write(1, &str[i++], 1);
		return (i);
	}
	return (ft_putstr("(null)"));
}

int	ft_putnbr(long int nb)
{
	int	cpt;

	cpt = 0;
	if (nb < 0)
	{
		cpt += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		cpt += ft_putnbr(nb / 10);
		cpt += ft_putnbr(nb % 10);
	}
	else
		cpt += ft_putchar(nb + 48);
	return (cpt);
}

int	ft_puthex(unsigned long nb, char x)
{
	int	cpt;

	cpt = 0;
	if (nb >= 16)
	{
		cpt += ft_puthex(nb / 16, x);
		cpt += ft_puthex(nb % 16, x);
	}
	else
	{
		if (nb < 10)
			cpt += ft_putnbr(nb);
		else
			cpt += ft_putchar(nb - 10 + 'a' + (x - 'x'));
	}
	return (cpt);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(ptr, 'x');
	return (count);
}
