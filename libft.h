/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:22:25 by cchameyr          #+#    #+#             */
/*   Updated: 2016/10/17 16:53:15 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# ifndef RETURN_STAT
#  define RETURN_STAT

#  define _FAULT_		0x00
#  define _ERROR_		0x00
#  define _SUCCESS_		0x01

# endif

typedef enum		e_bool
{
	false,
	true
}					t_bool;

typedef struct		s_pt
{
	int				x;
	int				y;
}					t_pt;

typedef struct		s_ptd
{
	double			x;
	double			y;
}					t_ptd;

typedef struct		s_ptd3d
{
	double			x;
	double			y;
	double			z;
}					t_ptd3d;

typedef struct		s_ptll
{
	long long		x;
	long long		y;
}					t_ptll;

typedef struct		s_pt3d
{
	int				x;
	int				y;
	int				z;
}					t_pt3d;

typedef struct		s_pt3df
{
	float			x;
	float			y;
	float			z;
}					t_pt3df;

typedef struct		s_lstline
{
	struct s_lstline	*next;
	char				*line;
}					t_lstline;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t m);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *s1, char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strstr(const char *s1, char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_atoi(const char *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_strclr(char *s);
char				*ft_itoa(int n);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** private functions
*/

int					ft_printf(const char *format, ...);

int					ft_putwchar(int c);
int					ft_putwstr(int *str);
int					ft_putnwchar(int c, int len);
int					ft_putnwstr(int *str, int len);

int					ft_putnstr(char const *s, size_t len);
void				ft_putnbr_l(long n);
void				ft_putnbr_ll(long long n);
int					ft_nblen(int n);
int					ft_nblen_l(long n);
int					ft_nblen_ll(long long n);
int					ft_binlen(unsigned int n);
int					ft_charwlen(int c);
int					ft_strwlen(int *str);
int					ft_strnwlen(int *str, int len);

int					ft_power(int nb, int pow);
unsigned int		ft_abs(int a);
double				ft_absd(double a);
unsigned long long	ft_absll(long long a);

double				ft_atoid(char *str);
unsigned int		ft_atoi_base(const char *str, int base);
unsigned int		ft_atoi_nbase(const char *str, int base, int len);
char				*ft_itoa_base(unsigned int n, int base);
char				*ft_itoa_base_l(unsigned long int n, int base);
char				*ft_itoa_base_ll(unsigned long long int n, int base);

int					ft_ishexa(int c);
int					ft_strishexa(char *str);
int					ft_strisdigit(char *str);
int					ft_strisdouble(char *str);
void				ft_upperstr(char *str);
void				ft_lowerstr(char *str);

void				ft_swap(int *a, int *b);
int					ft_memlen(void **tab);
void				ft_memdel2(void ***ap);

int					*ft_intdup(const int *i1, int len);

t_pt				ft_make_pt(int x, int y);
t_ptd				ft_make_ptd(double x, double y);
t_ptd3d				ft_make_ptd3d(double x, double y, double z);
t_ptll				ft_make_ptll(long long x, long long y);
t_pt3d				ft_make_pt3d(int x, int y, int z);
t_pt3df				ft_make_pt3df(float x, float y, float z);

t_pt				ft_add_pt(t_pt pt1, t_pt pt2);
t_ptd				ft_add_ptd(t_ptd pt1, t_ptd pt2);
t_ptd3d				ft_add_ptd3d(t_ptd3d pt1, t_ptd3d pt2);
t_ptll				ft_add_ptll(t_ptll pt1, t_ptll pt2);
t_pt3d				ft_add_pt3d(t_pt3d pt1, t_pt3d pt2);
t_pt3df				ft_add_pt3df(t_pt3df pt1, t_pt3df pt2);

t_pt				**ft_pt_alloc(t_pt size);
t_pt				**ft_free_pt(t_pt **tab_pts, int size);
t_pt3d				**ft_pt3d_alloc(t_pt size);
t_pt3d				**ft_free_pt3d(t_pt3d **tab_pts, int size);

t_lstline			*ft_lstline_del(t_lstline *begin);
t_lstline			*ft_new_lstline(void);
t_lstline			*ft_add_lstline(t_lstline *begin, char *line);

#endif
