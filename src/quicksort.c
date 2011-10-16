//Quick Sort Algorithm Implementation//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50
#define NUL -1
void Quick(int *,int);
int SubQuick(int *,int ,int ,int);
void swapv(int *,int *);
main(void)
{
          int a[SIZE],i=0,num;
          system("cls");
          printf("\n\nQuick Sort Algorithm Implementation");
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
          Quick(a,num);
          printf("\n\nSorted Array:\n\n");
          i=0;
          while(i<num)
          {
                    printf("%d,",a[i]);                             
                    i++;            
          }
          getch();
}

void Quick(int *a,int num)
{
          int top = NUL;     
          int upper[SIZE], lower[SIZE];                 // upper and lower are STACKS
          int beg,end,loc;
          
          top = top+1;            
          lower[top] = 0;
          upper[top] = num-1;
          while(top!=NUL)
          {               
               beg = lower[top];
               end = upper[top];
               top = top-1;
               loc = SubQuick(a,num,beg,end);
               if(loc-1>beg)
               {
                            top=top+1;
                            upper[top]=loc-1;
                            lower[top]=beg;             
               }                           
               if(loc+1<end)
               {
                            top = top+1;
                            upper[top] = end;
                            lower[top] = loc+1;             
               }
          }
}

int SubQuick(int *a,int num,int beg,int end)
{
          int left = beg;
          int right = end;
          int loc = beg;
          
   while(1)
   {
          while(*(a+loc) <= *(a+right) && loc!=right)
                        right = right - 1;          
          
          if(loc == right)
                        return (loc);
          else
                        swapv(a+loc,a+right);
          loc = right;
          
          while(*(a+loc)>= *(a+left) && loc !=left)
                        left = left + 1;
                        
          if(loc==left)
                       return (loc);
          else
                       swapv(a+loc,a+left);
          loc = left;                       
   }
                     
}

void swapv(int *i,int *j)
{
     int temp;
     temp = *i;
     *i = *j;
     *j = temp;          
}
