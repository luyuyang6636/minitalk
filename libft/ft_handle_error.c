#include "libft.h"

void    ft_handle_error(char *error_msg)
{
    write(STDERR_FILENO, "Error: ", 7);
    write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
    write(STDERR_FILENO, "\n", 1);
    exit(EXIT_FAILURE);
}