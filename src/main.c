#include <stdio.h>
#include <string.h>

int ft_strlen(char *);
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
	test_strlen();

	printf("Returned %d\n", ft_strlen("a"));
	_hello();
	printf("Should'n be here!");
	return 0;
}
