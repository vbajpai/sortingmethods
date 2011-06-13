//Bubble Sort Algorithm Implementation//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50
void swapv(int *,int *); 
void Bubble(int *,int);
main(void)
{
          int a[SIZE],i=0,num;
          system("cls");
          printf("\n\nBubble Sort Algorithm Implementation");
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
          Bubble(a,num);
          printf("\n\nSorted Array:\n\n");
          i=0;
          while(i<num)
          {
                    printf("%d,",a[i]);                             
                    i++;            
          }
          getch();
}

void Bubble(int *a,int num)
{
          int pass=0,i=0;
          while(pass<num-1)                                      // N-1 passes in Bubble Sort
          {
               while(i<num-pass-1)
               {
                   if(*(a+i)>*(a+i+1))             
                            swapv(a+i,a+i+1);                                          
                   i++;              
               }                 
               i=0;                                 
               pass++;                                                                                                     
          }     
}

void swapv(int *i,int*j)
{
         int temp;
         temp = *i;
         *i = *j;
         *j = temp;           
}
