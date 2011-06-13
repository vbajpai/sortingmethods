//Insertion Sort Algorithm Implementation//

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 50 
void Insertion(int *,int);
main(void)
{
          int a[SIZE],i=0,num;
          system("cls");
          printf("\n\nInsertion Sort Algorithm Implementation");
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
          Insertion(a,num);
          printf("\n\nSorted Array:\n\n");
          i=0;
          while(i<num)
          {
                    printf("%d,",a[i]);                             
                    i++;            
          }
          getch();
}

void Insertion(int *a,int num)
{
          int k=1,temp;
          while(k<num)                  
          {
                int p = k-1;
                temp = *(a+k);
                while(temp<*(a+p))
                {
                      *(a+p+1)=*(a+p);
                      p = p - 1;
                      if(p<0)
                             break;                                  
                }                  
                      *(a+p+1) = temp;                      // when p=-1, a[0] = a[k]
                k++;                                                      
          }
}
