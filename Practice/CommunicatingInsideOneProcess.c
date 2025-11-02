#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	int		pipefd[2];
	char	buf[100];
	ssize_t	n;
	pipe(pipefd);
	write(pipefd[1], "Hello World from me!", 20);
	n = read(pipefd[0], buf, sizeof(buf) - 1);
	buf [n] = '\0';
	printf("%s\n",buf);
	close(pipefd[0]);
	close(pipefd[1]);
	return(0);
}