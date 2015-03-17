/* Roll No:  12/CS/39, 12/CS/40
 * Name:     Soumyadip Mitra, Saikat Kumar Dey
 * Group No: 19 
 */

#include   <sys/types.h>
#include   <signal.h>
#include   <stdio.h>
#include   <unistd.h>
#include   <stdlib.h>

void childAlarm(int x)
{
	printf("signal received :%d \n",x);
	printf("child received signal\n");
	exit(0);
}

void parentrecv(int x)
{
	printf("signal received :%d \n",x);
	printf("parent received signal\n");
	exit(0);
}

int main()
{
 	pid_t pid;
 
 	if((pid = fork())==0)
 	{
		       /* child */
		       (void) signal(SIGALRM, childAlarm);
		       while(1)
		       	    printf("child waiting...\n");
		       		
		       
	}
	else
	{
          /* parent process */
          (void) signal(SIGCHLD, parentrecv);
         sleep(1);
          kill(pid,SIGALRM);
          
          while(1)
		 printf("parent waiting...\n");
      }
}

