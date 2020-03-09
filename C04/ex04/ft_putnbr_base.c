/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 08:36:49 by mravily           #+#    #+#             */
/*   Updated: 2019/09/19 02:03:37 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		checkbase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[i])
	{
		j = i + 1;
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		if ((base[i] == ' ') || (base[i] == '\t') || (base[i] == '\n')
		|| (base[i] == '\r') || (base[i] == '\v') || (base[i] == '\f'))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	int			size;

	nb = nbr;
	size = 0;
	if (checkbase(base))
	{
		size = ft_strlen(base);
		if (nbr < 0)
		{
			nb = nb * (-1);
			ft_putchar('-');
		}
		if (nb >= size)
			ft_putnbr_base(nb / size, base);
		ft_putchar(base[nb % size]);
	}
	return ;
}

int main()
{
	ft_putnbr_base("67594", "poneyvif");
}
