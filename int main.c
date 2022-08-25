int main (void)
{
	int     fd;
	char    *z;

	fd = open("file.txt", O_RDWR);
	
	while (z)
	{
		z = get_next_line(fd);
		printf("%s\n%zu\n\n", z, ft_strlen(z));
	}
	
}

int main (void)
{
	int     fd;
	char    *z;
	int     fd2;
	char    *i;

	fd = open("file.txt", O_RDWR);
	fd2 = open("text2.txt", O_RDWR);
	if (fd2)
		printf("%d\n%d\n", fd2, fd );
		z = get_next_line(fd);
	while (z)
	{
		printf("%s\n%zu\n\n", z, ft_strlen(z));
		z = get_next_line(fd);
	}
		i = get_next_line(fd2);
	while (i)
	{
		printf("%s\n%zu\n\n", i, ft_strlen(i));
		i = get_next_line(fd2);
	}
}