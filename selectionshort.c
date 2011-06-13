//Selection Sort Algorithm Implementation//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50
void swapv(int *,int *); 
void Selection(int *,int);
int Min(int *,int ,int );
main(void)
{
          int a[SIZE],i=0,num;
          system("cls");
          printf("\n\nSelection Sort Algorithm Implementation");
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
          Selection(a,num);
          printf("\n\nSorted Array:\n\n");
          i=0;
          while(i<num)
          {
                    printf("%d,",a[i]);                             
                    i++;            
          }
          getch();
}

void Selection(int *a,int num)
{
          int pass=0;
          int loc;
          while(pass<num-1)                                      // N-1 passes in Selection Sort
          {
               loc = Min(a,num,pass);               
               swapv((a+pass),(a+loc));                                 
               pass++;                                                                                                     
          }     
}

int Min(int *a,int num,int pass)
{
          int loc = pass;  
          int min = *(a+loc);  
          
          while(pass<num)
          {             
             if(*(a+pass)<min)
             {
                          min = *(a+pass);     
                          loc = pass;           
             }
             pass++;                           
          }         
          return(loc);
}

void swapv(int *i,int*j)
{
         int temp;
         temp = *i;
         *i = *j;
         *j = temp;           
}
