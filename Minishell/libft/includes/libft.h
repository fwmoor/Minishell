/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:49:55 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/20 10:41:32 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <sys/stat.h>
# include <ctype.h>
# include <fcntl.h>

# define BUFF_SIZE 32
# define DEFAULT "\x1b[0m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\f')

/*
** libft struct
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** printf struct
*/

typedef struct		s_format
{
	char			t_form;
	va_list			*ap;
	unsigned char	flags;
	unsigned char	p_len;
	long			prec;
	long			len;
	int				neg;
}					t_format;

/*
** Int functions
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_tdlen(char **arr);
int					ft_atoi(const char *str);
int					ft_start(char *s1, char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);

/*
** Char functions
*/

char				*ft_itoa(long long n);
char				*ft_strnew(size_t size);
char				*ft_str_upper(char *str);
char				*ft_strdup(const char *s);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(char *str, char *to_find);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strcpy(char *dest, const char *srcs);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnstr(char *str, char *to_find, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** Void functions
*/

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				free_her(char **dirs);
void				*ft_memalloc(size_t n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *str1, const void *str2, size_t n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				*ft_memccpy(void *str1, const void *str2, int c, size_t n);

/*
** Size_t functions
*/

size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);

/*
** T_list functions
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** Bonus functions
*/

int					ft_sqrt(int nb);
int					ft_factorial(int nb);
int					ft_power(int nb, int pwr);
char				*ft_strrev(char *str);
void				ft_foreach(int *tab, int len, void(*f)(int));

/*
** Get_next_line function
*/

int					get_next_line(const int fd, char **line);

/*
** Printf functions
*/

int					ft_width(char **str);
int					ft_correct_form(char c);
int					ft_middle_n(t_format *tf);
int					ft_middle_u(t_format *tf);
int					ft_middle_x(t_format *tf);
int					ft_middle_p(t_format *tf);
int					ft_getstr_all(t_format *tf);
int					ft_num_len(intmax_t n, int base);
int					ft_format(char **str, va_list ap);
int					ft_printf(const char *format, ...);
int					ft_num_len_u(uintmax_t n, int base);
int					ft_print_sc(t_format *tf, char *str);
int					ft_print_sn(t_format *tf, char *str);
int					ft_print_un(t_format *tf, char *str);
int					ft_print_ux(t_format *tf, char *str);
int					ft_print_up(t_format *tf, char *str);
int					ft_after(t_format *tf, long len, char *str);
int					ft_format_all(const char *format, va_list ap);
char				*ft_getstr_d(t_format *tf);
char				*ft_getstr_p(t_format *tf);
char				*ft_middle_c(t_format *tf);
char				*ft_middle_s(t_format *tf);
char				*ft_itoa_base(intmax_t n, int base);
char				*ft_getstr_u(t_format *tf, int base);
char				*ft_itoa_base_u(uintmax_t n, int base);
char				*ft_appendwchar(wchar_t wc, char *str);
unsigned char		ft_flags(char **str);
unsigned char		ft_p_len(char **str);

#endif
