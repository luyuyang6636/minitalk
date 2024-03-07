/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:34:57 by luyang            #+#    #+#             */
/*   Updated: 2023/11/04 18:12:31 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int nb);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_full(char *remain, int fd);
char	*ft_get_line(char *remain);
char	*ft_left(char *remain);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);

typedef struct s_flags
{
	int		left;
	int		zero;
	int		space;
	int		plus;
	int		hash;
	int		precision;
	int		width;
	int		dot;
	int		error;
	char	type;
}				t_flags;

int		ft_put_char(int c);
int		ft_printchar(t_flags flags, int c);
int		ft_printstr(t_flags flags, char *str);
int		ft_putstr(char *str);
int		ft_printstr_left(t_flags flags, char *str);
int		ft_printstr_no_left(t_flags flags, char *str);
int		ft_formats(va_list args, const char *format);
int		ft_printf(const char *format, ...);
int		ft_print_ptr(t_flags flags, unsigned long int ptr);
void	ft_put_ptr_left(t_flags flags, unsigned long int ptr, int length);
void	ft_put_ptr_no_left(t_flags flags, unsigned long int ptr, int length);
void	ft_put_ptr(unsigned long int ptr);
int		ft_print_int(t_flags flags, long n);
int		ft_print_int_body(t_flags flags, long n);
void	ft_put_hex(unsigned int num, const char format);
int		ft_print_hex(t_flags flags, unsigned int num, const char format);
int		ft_print_hex_body(t_flags flags, unsigned int n, const char format);
int		ft_ptrlen(unsigned long int ptr);
int		ft_nbrlen(long n);
void	ft_putnbr(long n);
t_flags	ft_reset_flags(void);
t_flags	ft_set_flags(t_flags flags, const char *format);
t_flags	ft_set_format(t_flags flags, const char *format);
int		ft_print_all(t_flags flags, va_list args);
int		ft_padding(t_flags flags, long n, int (*f)());
int		ft_padding_count(t_flags flags, long n, int (*f)());
int		ft_print_unsigned(t_flags flags, unsigned int n);
t_flags	ft_set_flags_wp(t_flags flags, const char *format);
t_flags	ft_flags_check_error(t_flags flags);
int		ft_printstr_null(t_flags flags, char *str);
int		ft_printstr_null_pointer(t_flags flags);
int		ft_hexlen(unsigned long int n);
char	*ft_strchr_printf(const char *s, const char *str);

void	ft_handle_error(char *error_msg);

#endif
