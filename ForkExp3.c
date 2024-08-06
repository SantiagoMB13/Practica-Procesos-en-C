#include <unistd.h>
#include <stdio.h>

int var = 2;

int main(void)
{
	pid_t pidC;
	printf("**proc. PID = %d comienza  **\n", getpid());
	pidC = fork();

	
	printf("proc. PID = %d, pidC = %d ejecutándose  **\n", getpid(), pidC);
		
	if(pidC > 0)
	{
		var = var + 4;
	}
	else if(pidC == 0)
	{
		var = var + 3;
	}
	else /** error **/
	{
	}
	
	
	while(1)
	{
		sleep(2);
		printf("proc. PID = %d, var = %d ejecutándose  **\n", getpid(), var);
	}

	return 0;
}