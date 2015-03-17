/* Roll No:  12/CS/39, 12/CS/40
 * Name:     Soumyadip Mitra, Saikat Kumar Dey
 * Group No: 19 
 */


#include <stdio.h>
#include <sys/ipc.h>


int main()
{

	int n;
	
	printf("Enter number of elements: ");
	scanf("%d",&n);
		
	int arr[n], sumEven=0, sumOdd=0;
	
	int i;
		
	printf("Enter numbers: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	

	int pid1, pid2, status ;
	
	if ((pid1 = fork()) == 0) 
	{
	/* First child process */
		for (i=0 ; i < n; i++) 
		{	
			if((arr[i] & 01) == 0)
				sumEven+=arr[i];
		}
		printf("Even Sum= %d\n",sumEven);
	}
	else 
	{
	/* Create another child process */
		if ((pid2 = fork()) == 0) 
		{
		/* Second child process */
			for (i=0 ; i < n; i++) 
			{
				if((arr[i] & 01) == 1)
					sumOdd+=arr[i];
			}
			printf("Odd Sum = %d\n",sumOdd);
		}
	}
}
