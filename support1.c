#include "phil.h"

/*
** ERRORS' MESSAGES LIST
** 1) Error: too less arguments, should be 4-5
** 2) Error: too many arguments, should be 4-5
** 3) Error: wrong philosophers quantity
** 4) Error: wrong death time
** 5) Error: wrong eat time
** 6) Error: wrong sleep time
** 7) Error: wrong number of times each philosopher must eat
** 8) Error: malloc t_ph
** 9) Error: sem unlink failed
** 10) Error: gettimeofday failed
** 11) Error: sem operation failed (check_status)
** 12) Error: pthread create failed (actions)
** 13) Error: sem open failed
** 14) Error: pthread create failed (parallelize)
** 15) Error: sem operation failed (take_forks)
** 16) Error: sem operation failed (place_forks)
** 17) Error: mutex operation failed (print_msg)
*/

t_err	g_err[] =
{
	{"Error: too less arguments, should be 4-5\n"},
	{"Error: too many arguments, should be 4-5\n"},
	{"Error: wrong philosophers quantity\n"},
	{"Error: wrong death time\n"},
	{"Error: wrong eat time\n"},
	{"Error: wrong sleep time\n"},
	{"Error: wrong number of times each philosopher must eat\n"},
	{"Error: malloc t_ph\n"},
	{"Error: sem unlink failed\n"},
	{"Error: gettimeofday failed\n"},
	{"Error: sem operation failed (check_status)\n"},
	{"Error: pthread create failed (actions)\n"},
	{"Error: sem open failed\n"},
	{"Error: pthread create failed (parallelize)\n"},
	{"Error: sem operation failed (take_forks)\n"},
	{"Error: sem operation failed (place_forks)\n"},
	{"Error: sem operation failed (print_msg)\n"},
};

static char		*ft_rewind(const char *str)
{
	int i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f' ||
		str[i] == '\n' || str[i] == ' ' || str[i] == '\r')
		i++;
	return ((char *)str + i);
}

static uint64_t	ft_get_num(const char *str, int sign)
{
	int			i;
	uint64_t	tmp;

	i = 0;
	tmp = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			tmp = tmp * 10 + str[i] - '0';
			if (tmp < 0)
			{
				if (sign < 0)
					return (0);
				return (-1);
			}
			i++;
		}
		else
			return (-1);
	}
	return (tmp);
}

uint64_t		ft_atoi(const char *s)
{
	int	sign;

	sign = 1;
	s = ft_rewind(s);
	if (*s == '-')
		sign = -1;
	if ((*s == '-') || (*s == '+'))
		s++;
	return (sign * ft_get_num(s, sign));
}

int		error(int errn)
{
	write(STDERR_FILENO, g_err[errn - 1].desc,
	ft_strlen(g_err[errn - 1].desc));
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	*error_ptr(int errn)
{
	error(errn);
	return (00);
}
