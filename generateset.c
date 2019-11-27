#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void generateset(long long int n)     //function to generate the set of possibilities
{
	long long int x,i,j,flag=1,redcheck=0,endcheck=0;
	char tic[10];                     //using linear array as it would be easier.array stores the moves done sequentially
	tic[9]='\0';                      //the last character is always \0
	for(i=0;i<n;i++)
	{
reset:
		for(j=0;j<9;j++)                  //loop to reset the values of the array to 0
		{
			tic[j]=0;
		}
		for(j=0;j<9;j++)
		{
			x=rand()%9;
			if(flag==1)                  //flag checks whose move it is and assigns the respective value to it
			{                            //flag==1 means it is player 1's move 
				tic[j]=x;
				flag=2;                  //setting flag to other player
			}
			else
			{
				tic[j]=x;                //player 2's move
				flag=1;
			}
			redcheck=check(tic);              //check for redundancies in the current state of the game
			if(redcheck==1)
			{
				goto reset;                   //if redundancy is detected reset to start again
			}
			endcheck=end(tic);                //check if the game has ended
			if(endcheck==1)
			{
				store(tic);                   //if game has ended then store it and break out of the loop
				break;
			}
		}
	}
}

int main()
{
	long long int n;
	srand(time(0));
	printf("how many times do u want to generate it?");
	scanf("%lld",&n);
	generateset(n);
	return 0;
}
