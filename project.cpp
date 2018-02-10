#include<conio.h>
#include<stdio.h>
#include<math.h>


void RM(int n,float burst[],float dead[])
{

int i,j,k,temp;  //loop variables
int turn[n],wt[n]; // turn and wright for every process
int bur=0;
float exp=0; //initial exp = 0;
int pro[n]; //to save process numbers

for(i=1;i<=n;i++) //loop till n i.e no of processes
{
pro[i]=i; //intialize all processes to their process numbers
}

  for(i=0;i<n;i++)
  {
  	for(j=i;j<n;j++)
  	{
			if(burst[j+1]<burst[j])  //if execution time of next process is less than current one
			{
			    //basic sorting technique is used here

				temp = dead[j+1]; //transfer deadline to temp
				dead[j+1]=dead[j]; //switch form previous
				dead[j]=temp; // and switching is done

				temp = burst[j+1];
				burst[j+1]=burst[j];
				burst[j]=temp;

				temp = pro[j+1];
				pro[j+1]=pro[j];
				pro[j]=temp;
                    //same goes for all Project num, burst time and deadline time

			}
		}
  }

turn[1] = burst[1]; //let put turn to burst[0] i.e first value of array

for(i=2;i<=n;i++)
{
	turn[i] = burst[i]+turn[i-1]; //turn for new process will be including burst of that process and previous process burst that is turn
	wt[i] = turn[i]-burst[i]; //here we set new wait that is how much time it have to wait to initialize process.
}
wt[1] ==0;
printf("\nRate Monotoric Scheduling Algorithm\n");

for(j=1;j<=n;j++)
{
	if(dead[j]==1000)
	dead[j]=0;  //if deadline is unlimited make is zero that means same

	if(wt[j]==0) //as new process or first process will start from zero
	printf("\n Start 0");

	else
	{
		if(wt[j]>0 && j>=2) //if wait is greater than zero that is not the new process
		{
		printf("\n End %d",wt[j]); // end time of process
		printf("\n===================");
		printf("\n Start %d",wt[j]); //start time for new process
		}
		else
		printf("\n Start 0"); //start time only

	}
		printf("\n Process %d",pro[j]); //process number

}

for(i=1;i<=n;i++)
{
	bur += burst[i];  //bur is the sum of all burst times
}
printf("\n End  %d",bur); //end time of last process will be the bur time
printf("\n===================");

getch();
}

void EDF(int n,float burst[],float dead[])
{

int i,j,k,temp;  //loop variables
int turn[n],wt[n]; // turn and wright for every process
int bur=0;
float exp=0; //initial exp = 0;
int pro[n]; //to save process numbers

for(i=1;i<=n;i++) //loop till n i.e no of processes
{
pro[i]=i; //initialize all processes to their process numbers
}

  for(i=0;i<n;i++)
  {
  	for(j=i;j<n;j++)
  	{
			if(dead[j+1]<dead[j])  //if execution time of next process is less than current one
			{
			    //basic sorting technique is used here

				temp = dead[j+1]; //transfer deadline to temp
				dead[j+1]=dead[j]; //switch form previous
				dead[j]=temp; // and switching is done

				temp = burst[j+1];
				burst[j+1]=burst[j];
				burst[j]=temp;

				temp = pro[j+1];
				pro[j+1]=pro[j];
				pro[j]=temp;
                    //same goes for all Project num, burst time and deadline time

			}
		}
  }

turn[1] = burst[1]; //let put turn to burst[0] i.e first value of array

for(i=2;i<=n;i++)
{
	turn[i] = burst[i]+turn[i-1]; //turn for new process will be including burst of that process and previous process burst that is turn
	wt[i] = turn[i]-burst[i]; //here we set new wait that is how much time it have to wait to initialize process.
}
wt[1] ==0;
printf("\nEarliest Deadline First Scheduling Algorithm\n");

for(j=1;j<=n;j++)
{
	if(dead[j]==1000)
	dead[j]=0;  //if deadline is unlimited make is zero that means same

	if(wt[j]==0) //as new process or first process will start from zero
	printf("\n Start 0");

	else
	{
		if(wt[j]>0 && j>=2) //if wait is greater than zero that is not the new process
		{
		printf("\n End %d",wt[j]); // end time of process
		printf("\n===================");
		printf("\n Start %d",wt[j]); //start time for new process
		}
		else
		printf("\n Start 0"); //start time only

	}
		printf("\n Process %d",pro[j]); //process number

}

for(i=1;i<=n;i++)
{
	bur += burst[i];  //bur is the sum of all burst times
}
printf("\n End  %d",bur); //end time of last process will be the bur time
printf("\n===================");


getch();



}



int main()
{
	int a,n,i,j,k,temp;
	float exp=0,y;
	float dead[100];  // process deadline time array
	float burst[100];  // process total execution time array


	printf("\nEnter Number of Processes\n");  //number of processors entered by user.
	scanf("%d",&n);

if(n!=0)   //if processors are not equal to zero then
{
	for(i=1;i<=n;i++)  //loop till n
  {

   printf("\n Enter Burst for P%d ::",(i)); //get burst(execution) time for each processor
   scanf("%f",&burst[i]);
   printf("\n Enter DEADLINE for P%d ::",(i));  //get final deadline time for each processor
   scanf("%f",&dead[i]);

   if(dead[i] == 0)
   {
   	dead[i] = 10000;   //if deadline is zero or not defined we make it 10000 which is large enough
   }

  }


  for(k=1;k<=n;k++)
{
	exp += (burst[k]/dead[k]);  //this saves the values of all the division of burst and dead for all processor to apply formula
}

//user will click accordingly RM OR EDF Scheduling
printf("\n\nEnter 1 for RM Scheduling\n");
printf("\nEnter 2 for EDF Scheduling\n");
scanf("%d",&a);
switch(a)
{
	case 1:
		{
//if RM is selected
		  y=(float)n;  //convert number of processor to float
		  y=y*((pow(2.0,1/y))-1); // as we need to calculate y = y (2^y -1) for RM Calculations


		  if(exp<y)  // condition to check if its applicable i.e exp should be less than y
		  {
		  	printf("\n\n AS %f < %f \n So the Processes are Schedulable \n",exp,y);
		  	RM(n,burst,dead); //function call
		  }

		  else
		  { //condition fails these processes can not be scheduled using RM scheduling
		  printf("\n\n AS %f > %f \n So the Processes are not Schedulable \n",exp,y);
		  }
		break;
		}

	case 2:
		{

		 if(exp<1) // condition to check if its applicable i.e exp should be less than 1
		 {
		 printf("\n\n AS %f < 1 \n So the Processes are Schedulable \n",exp);
		 EDF(n,burst,dead); //function call
		 }

		 else
		 {//condition fails these processes can not be scheduled using RM scheduling
		 printf("\n\n AS %f > 1 \n So the Processes are not Schedulable \n",exp);
		 }
		 break;
		}


	default:  //input is invalid
	printf("\nEnter valid case\n");

}




}
else   //if n =0 there will be no process to schedule
	printf("\nAs no processes are there to schedule\n\n");

	return 0;
}
