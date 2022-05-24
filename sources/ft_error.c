#include "so_long.h"

int	ft_error(const char *error)
{
	ft_putstr_fd("Error\nso_long: ", 2);
	ft_putstr_fd(error, 2);
	return (-1);
}
