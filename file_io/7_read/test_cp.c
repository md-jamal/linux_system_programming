#include <stdio.h>
#include <fcntl.h>

#define BUFFSIZE 4096
int main(void)
{
	int n;
	char buf[BUFFSIZE];
	int fd1, fd2;

	fd1 = open("hello.txt", O_RDONLY);
	perror("open hello.txt");
	fd2 = open("newhello.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	perror("open newhello.txt");
	while ((n = read(fd1, buf, BUFFSIZE)) > 0)
		if (write(fd2, buf, n) != n)
			perror("write error");
	if (n < 0)
		perror("read error");
	exit(0);
}
