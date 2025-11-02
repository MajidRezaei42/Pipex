#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int	main(void)
{
	int		pipefd[2];
	char	buf[100];
	ssize_t	n;
	pid_t	PID;
	pipe(pipefd);
	PID = fork();
	printf("%d\n",PID);
	if (PID == 0)
	{
		close(pipefd[1]);
		n = read(pipefd[0], buf, sizeof(buf) - 1);
		buf [n] = '\0';
		close(pipefd[0]);
		printf("%s\n",buf);
	}
	else if (PID > 0)
	{
		close(pipefd[0]);
		write(pipefd[1], "Hello World from me!", 20);
		close(pipefd[1]);
		wait(NULL);
	}
	return(0);
}