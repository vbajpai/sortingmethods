// Merge Sort Algorithm Implementation//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50

void MergeSort(int *,int);
void MergePass(int *,int,int);
void MERGE(int *,int *,int *, int,int, int, int, int);

main(void)
{
          int a[SIZE],i=0,num;
          system("cls");
          printf("\n\nMerge Sort Algorithm Implementation");
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
          MergeSort(a,num);
          printf("\n\nSorted Array:\n\n");
          i=0;
          while(i<num)
          {
                    printf("%d,",a[i]);                             
                    i++;            
          }
          getch();
}

void MergeSort(int *a,int num)
{
    int size = 1;
    while(size<num)
    {             
          MergePass(a,size,num);         
          size *= 2;        
    }                 
     
}

void MergePass(int *a,int size, int num)
{
    int LB1=0,LB2,UB1,UB2;
    int temp[SIZE];
    int i=0;
    while(LB1+size < num)              // second array possible
    {
          LB2 = LB1+size;
          UB1 = LB2-1;
          UB2 = ( (LB2+size-1<num) ? (LB2+size-1): num-1 );                              
          
          MERGE(a,a,temp, LB1,LB2,UB1,UB2,size);       
          LB1 = UB2+1;   
    }  
    while(LB1<num)
    {
          temp[LB1] = a[LB1];  
          LB1++;                   
    }
    
    while(i<num)
    {
          a[i] = temp[i];
          i++;      
    } 
}

void MERGE(int *a,int *b,int *c, int LB1,int LB2, int UB1, int UB2, int size)
{
    int apoint = LB1;
    int bpoint = LB2;
    int cpoint = LB1;
    
    while(apoint<=UB1 && bpoint<=UB2)
    {
               if(*(a+apoint) < *(b+bpoint))
               {
                        *(c+cpoint) = *(a+apoint);
                        apoint++;
               }
               else
               {
                        *(c+cpoint) = *(b+bpoint);                                                     
                        bpoint++;
               }
               cpoint++;         
    }     
    
    while(apoint<=UB1)
    {
            *(c+cpoint) = *(a+apoint);    
            cpoint++;
            apoint++;
    }
    while(bpoint<=UB2)
    {
            *(c+cpoint) = *(b+bpoint);
            cpoint++;
            bpoint++;                      
    }
}
