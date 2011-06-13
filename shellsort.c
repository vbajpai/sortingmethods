//Shell Sort Algorithm Implementation//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50
#define TRUE 1
#define FALSE 0
void swapv(int *,int *); 
void Shell(int *,int);
main(void)
{
          int a[SIZE],i=0,num;
          system("cls");
          printf("\n\nShell Sort Algorithm Implementation");
          printf("\n------------------------------------\n\n");
          printf("Number of Values to be Entered [<50] :");
          scanf("%d",&num);
          printf("\nEnter Values of Array\n\n");
          while(i<num)
          {
                    printf("Values for a[%d]:",i); 
                    scanf("%d",&a[i]);         
                    i++;            
          }
          Shell(a,num);
          printf("\n\nSorted Array:\n\n");
          i=0;
          while(i<num)
          {
                    printf("%d,",a[i]);                             
                    i++;            
          }
          getch();
}
void Shell(int *a,int num)
{
     int span = num;
     int swap = TRUE;
     int i = 0;
     
          while(span=span/2)
          {
                while(swap==TRUE)
                {
                     swap = FALSE;            
                     while(i<(num-span))            
                     {
                         if(*(a+i)>*(a+span+i))
                         {
                               swapv(a+i,a+span+i);                           
                               swap = TRUE;
                         }
                         i++;                                                                             
                     }
                     i=0;
                }
                swap = TRUE;
          }
         
}

void swapv(int *i,int*j)
{
         int temp;
         temp = *i;
         *i = *j;
         *j = temp;           
}
