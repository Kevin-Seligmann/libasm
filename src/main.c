#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int ft_strlen(char *);
char *ft_strcpy(char *dst, char *src);
int ft_strcmp(char *, char *);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);
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

int main()
{
	printf("%p %s\n", ft_strdup("Hello"), ft_strdup("Hello"));
	// _hello();
	// printf("Should'n be here!");
	return 0;
}
