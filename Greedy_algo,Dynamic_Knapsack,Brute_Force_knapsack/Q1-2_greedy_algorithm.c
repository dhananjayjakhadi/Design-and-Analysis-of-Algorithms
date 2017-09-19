#include<stdio.h>
void greedy1(int[][3],int,int);
void greedy2(int[][3],int,int);
void greedy3(int[][3],int,int);
void greedy4(int[][3],int,int);
void main()
{
  int n;
  printf("Enter Number Of Items:");
  scanf("%d",&n);
  int i,j,w;
  int input[n][3];
  for(i=0;i<n;i++)
  {
    printf("\nEnter %d Item with Weight and Profit:",i+1);
    input[i][0]=i+1;
    scanf("%d %d",&input[i][1],&input[i][2]);
  }
  printf("\nEnter Max Weight Allowed:");
  scanf("%d",&w);
  greedy1(input,n,w);
  greedy2(input,n,w);
  greedy3(input,n,w);
  greedy4(input,n,w);

}
//Function for Greedy1
void greedy1(int input[][3],int n,int w)
{
  int i,j;
  printf("\n\n========Greedy 1=========\n");
  for (i = 0 ; i < ( n - 1 ); i++)
   {
     for (j = 0 ; j < n - i - 1; j++)
     {
       if (input[j][2] < input[j+1][2])     //Max Benefit First Condition
       {
         int swap1 = input[j][0];
         int swap2 = input[j][1];
         int swap3 = input[j][2];
         input[j][0] = input[j+1][0];
         input[j][1] = input[j+1][1];
         input[j][2] = input[j+1][2];
         input[j+1][0] = swap1;
         input[j+1][1] = swap2;
         input[j+1][2] = swap3;
       }
     }
   }
   int count=0,w_c=0,p_c=0;
   printf("\nItems Selected:");
   for(i=0;i<n;i++)
   {
     count=count+input[i][1];
     if(count<=w)
     {
       printf("\nItem%d  %d  %d",input[i][0],input[i][1],input[i][2]);
       w_c=w_c+ input[i][1];
       p_c=p_c+ input[i][2];
     }
   }
         printf("\n\nTotal Profit: %d",p_c);
         printf("\nTotal Weight: %d\n",w_c);
}
//Function for Greedy2
void greedy2(int input[][3],int n,int w)
{
  int i,j;
  printf("\n\n========Greedy 2========\n");
  for (i = 0 ; i < ( n - 1 ); i++)
   {
     for (j = 0 ; j < n - i - 1; j++)
     {
       if (input[j][1] > input[j+1][1])   //Minimum Weight First Condition
       {
         int swap1 = input[j][0];
         int swap2 = input[j][1];
         int swap3 = input[j][2];
         input[j][0] = input[j+1][0];
         input[j][1] = input[j+1][1];
         input[j][2] = input[j+1][2];
         input[j+1][0] = swap1;
         input[j+1][1] = swap2;
         input[j+1][2] = swap3;
       }
     }
   }
   int count=0,w_c=0,p_c=0;
   printf("\nItems Selected:");
   for(i=0;i<n;i++)
   {
     count=count+input[i][1];
     if(count<=w)
     {
       printf("\nItem%d  %d  %d",input[i][0],input[i][1],input[i][2]);
       w_c=w_c+ input[i][1];
       p_c=p_c+ input[i][2];
     }
   }
         printf("\n\nTotal Profit: %d",p_c);
         printf("\nTotal Weight: %d\n",w_c);
}
//Function for Greedy3
void greedy3(int input[][3],int n,int w)
{
  int i,j;
  printf("\n\n========Greedy 3========\n");
  for (i = 0 ; i < ( n - 1 ); i++)
   {
     for (j = 0 ; j < n - i - 1; j++)
     {
       if (input[j][1] < input[j+1][1]) //Maximum Weight First Condition
       {
         int swap1 = input[j][0];
         int swap2 = input[j][1];
         int swap3 = input[j][2];
         input[j][0] = input[j+1][0];
         input[j][1] = input[j+1][1];
         input[j][2] = input[j+1][2];
         input[j+1][0] = swap1;
         input[j+1][1] = swap2;
         input[j+1][2] = swap3;
       }
     }
   }
   int count=0,w_c=0,p_c=0;
   printf("\nItems Selected:");
   for(i=0;i<n;i++)
   {
     count=count+input[i][1];
     if(count<=w)
     {
       printf("\nItem%d  %d  %d",input[i][0],input[i][1],input[i][2]);
       w_c=w_c+ input[i][1];
       p_c=p_c+ input[i][2];
     }
   }
         printf("\n\nTotal Profit: %d",p_c);
         printf("\nTotal Weight: %d\n",w_c);
}
//Function for Greedy4
void greedy4(int input[][3],int n,int w)
{
  int i,j;
  printf("\n\n========Greedy 4========\n");
  for (i = 0 ; i < ( n - 1 ); i++)
   {
     for (j = 0 ; j < n - i - 1; j++)
     {
       if (input[j][2]/input[j][1] < input[j+1][2]/input[j+1][1]) //Maximum Benefit per Unit item
       {
         int swap1 = input[j][0];
         int swap2 = input[j][1];
         int swap3 = input[j][2];
         input[j][0] = input[j+1][0];
         input[j][1] = input[j+1][1];
         input[j][2] = input[j+1][2];
         input[j+1][0] = swap1;
         input[j+1][1] = swap2;
         input[j+1][2] = swap3;
       }
     }
   }
   int count=0,w_c=0,p_c=0;
   printf("\nItems Selected:");
   for(i=0;i<n;i++)
   {
     count=count+input[i][1];
     if(count<=w)
     {
       printf("\nItem%d  %d  %d",input[i][0],input[i][1],input[i][2]);
       w_c=w_c+ input[i][1];
       p_c=p_c+ input[i][2];
     }
   }
         printf("\n\nTotal Profit: %d",p_c);
         printf("\nTotal Weight: %d\n",w_c);
}
