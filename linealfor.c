#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	pid_t childpid = 0; 
	int i, n;
	
    n = atoi(argv[1]); 
	for(i=0; i < n; i++)
		if(fork() != 0)  /* Si cambia por == *, qué sucede?*/
			break;
		
	printf("i:%d  process ID:%ld  parent ID:%ld  child ID:%ld\n",
           i, (long)getpid(), (long)getppid(), (long)childpid);
	while(1);
	return 0;

}