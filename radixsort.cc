/* Algorithm 
	
   1. Take the least significant digit (or group of bits, both being examples of radices) of each key.
   2. Group the keys based on that digit, but otherwise keep the original order of keys. 
   3. Repeat the grouping process with each more significant digit.

   The sort in step 2 is usually done using bucket sort or counting sort

*/

/* Notes
	
	* radix sort is not limited to integers.
	
	* Two classifications of radix sorts are least significant digit (LSD) radix sorts and most significant digit (MSD)
	  radix sorts. LSD radix sorts process the integer representations starting from the least significant
	  digit and move towards the most significant digit.
	  
	* A least significant digit (LSD) radix sort operates in O(nk) time, where n is the number of keys, 
	  and k is the average key length.
	  
	* One disadvantage of an LSD radix sort is that it does not run in place
	
	* When an LSD radix sort processes keys which all have the same fixed length,
	  then the upper bound of the execution time is O(n).
	
*/

/* Example
  
   1. Original, unsorted list:

      170, 45, 75, 90, 2, 24, 802, 66
   2. Sorting by least significant digit (1s place) gives:

      170, 90, 2, 802, 24, 45, 75, 66

      Notice that we keep 2 before 802, because 2 occurred before 802 in the original list, and similarly for 170 and 90.
   3. Sorting by next digit (10s place) gives:

      2, 802, 24, 45, 66, 170, 75, 90
   4. Sorting by most significant digit (100s place) gives:

      2, 24, 45, 66, 75, 90, 170, 802
  
*/

#include<iostream>
using namespace std;

class LinkedList
{
	public:
	
		int val;
		LinkedList *next;
	
		LinkedList()
		{
			next = NULL;	
		}
		
		LinkedList(int x)
		{
			val = x;
			next = NULL;	
		}
};

class Queue: public LinkedList
{
	public:
	
		LinkedList *front;
		LinkedList *rear;
	
		Queue()
		{
			front = rear = NULL;	
		}				
		
		void Add(int x)
		{
			LinkedList *node = new LinkedList(x);
			
			if(front == NULL)
				front = rear = node;
			else
			{
				rear->next = node;
				rear = node;	
			}				
			
		}
};

class RadixSort
{	
	public:
		static void Sort(int *a, int num, int k)
		{
			if(k==0)
				return;
			else
			{
				for(int m = 1; m<=k;m++)
				{
					Queue q[10];
				
					for(int i=0;i<num;i++)
					{
						int n;
						int temp = a[i];
						for(int x=1;x<=m;x++)
						{
							n = temp % 10;
							temp = temp/10;							
						}							
						q[n].Add(a[i]);				
					}
					
					for(int i=0,j=0;i<10;i++)
					{
						if(q[i].front !=NULL)
						{
							while(q[i].front !=NULL)
							{
								a[j++] = (q[i].front)->val;							
								q[i].front = (q[i].front)->next;
							}	
						}
					}
				}				
			}
		}
};

int main()
{
	int num,i=0;
	cout<<"No. of elements:";
	cin>>num;
	
	int a[num];
	cout<<"\nEnter Non-Negative Values!\n"<<endl;
	while(i<num)
	{
		cout<<"Value for a["<<i<<"]:";
		cin>>a[i++];		
	}	
	
	/* Radix Sort Specific*/
	/*-------------------------*/
	int max = 0;
	for(int i=0;i<num;i++)
	{
			if(a[i] > max)
				max = a[i];
	}
	int k = 0;
	while(max > 0)
	{
		max = max/10;
		k++;
	}
	
	/*-------------------------*/
	
	RadixSort::Sort(a,num,k);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<a[i]<< ", ";			
		i++;	
	}
}
