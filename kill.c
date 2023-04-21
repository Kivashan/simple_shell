#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void end_of_file(int sig);
int check_file(char *str);

int main(void)
{
	pid_t pid;
	int num;
	int status;
	int is_file = check_file("/bin/ls");

	if (is_file == 0)
		printf("file exists\n");
	pid = fork();
	if (pid == -1)
		return -1;
	else if (pid == 0)
	{
		signal(SIGKILL, &end_of_file);
		printf("Child PID = %d\n", pid);
		scanf("%d", &num);
	}
	else
	{
		wait(&status);
		printf("Parent PID = %d\n", pid);
	}
	return 0;
}

void end_of_file(int sig)
{
	pid_t pid = getpid();
	printf("Pid = %d\n", pid);
	kill(pid, SIGKILL);
}

int check_file(char *str)
{
	int num = access(str, F_OK);

	return num;
}
