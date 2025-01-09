#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

int ft_strlen(char *);
char *ft_strcpy(char *dst, char *src);
int ft_strcmp(char *, char *);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);
int	ft_atoi_base(char *str, char *base);
void ft_list_push_front(t_list **begin, void *data);
int ft_list_size(t_list *begin_list);

void _hello();

void test_strlen()
{
	char *strings[] = {NULL, "", "a", "1230", "A long string, longer than 4 characters, so long that in doesn't fit on a 64 bits register (Not like it matters, is a pointer)"};
	int ft_strlen_len;
	int strlen_len;

	for (int i = 0; i < sizeof(strings) / sizeof(*strings); i++)
	{
		ft_strlen_len = ft_strlen(strings[i]);
		if (strings[i])
			strlen_len = strlen(strings[i]);
		else 
			strlen_len = 0;
		printf("ft_strlen: %d strlen: %d\n", ft_strlen_len, strlen_len); 	
	}
}

void print_list(t_list *list)
{
	printf("Printing: \n");
	while (list)
	{
		printf("%p, %p, %p, %s\n", list, list->data, list->next, (char *) list->data);
		list = list->next;
	}
}
int main()
{
	t_list **begin;

	begin = malloc(sizeof(t_list *));
	*begin = NULL;
	char *str1 = strdup("hola");
	char *str2 = strdup("chau");
	char *str3 = strdup("Hello, list");

	print_list(*begin);
	printf("len %d\n", ft_list_size(*begin));
	ft_list_push_front(NULL, NULL);
	printf("len %d\n", ft_list_size(*begin));
	ft_list_push_front(begin, str1);
	printf("len %d\n", ft_list_size(*begin));
	printf(" \n ---- ----- \n");
	print_list(*begin);
	printf(" \n ---- --- \n");
	ft_list_push_front(begin, str2);
	printf("len %d\n", ft_list_size(*begin));
	printf(" \n ---- --- \n");
	print_list(*begin);
	printf(" \n ---- --- \n");
	ft_list_push_front(begin, str3);
	printf("len %d\n", ft_list_size(*begin));
	print_list(*begin);

	return 0;
}
