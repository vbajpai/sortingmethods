// Heap Sort using Max-Heap DataStructure //

/* Algorithm 
	
       
*/

/* Notes

1> Complexity: Worst-case O(n log n) runtime.

2> Heapsort is an in-place algorithm, but is not a stable sort.

3> An interesting alternative to Heapsort is Introsort which combines quicksort and heapsort to retain 
   advantages of both: worst case speed of heapsort and average speed of quicksort.
	
*/


#include<iostream>
#include<cmath>			// for floor function 
using namespace std;

class HeapSort
{
	public:
	
		static void Sort(int *a, int num)
		{
			BuildHeap(a,num);
			for(int i=num-1;i>0;i--)
			{
				Swap(&a[0],&a[i]);
				num--;
				Heapify(a,0,num);
			}				
		}
		
		static void BuildHeap(int *a,int num)
		{
			for(int i=(int)(floor(num/2));i>=0;i--)
				Heapify(a,i,num);
		}
		
		static void Heapify(int *a,int i,int num)
		{
			int l = Left(i);
			int r = Right(i);
			int largest;
			
			if(l<num && a[l] > a[i])
				largest = l;
			else
				largest = i;
			
			if(r<num && a[r] > a[largest])
				largest = r;
				
			if (largest != i)
			{
				Swap(&a[i],&a[largest]);
				Heapify(a,largest,num);		
			}							
		}
		
		static int Left(int i)
		{
			return(2*i+1);
		}
		
		static int Right(int i)
		{
			return(2*i+2);
		}
		
		static void Swap(int *a, int *b)
		{
			if(*a!=*b)
			{
				*a ^= *b;
				*b ^= *a;
				*a ^= *b;	
			}
		}

};

int main()
{
	int num,i=0;
	cout<<"No. of elements:";
	cin>>num;
	
	int a[num];

	while(i<num)
	{
		cout<<"Value for a["<<i<<"]:";
		cin>>a[i++];		
	}		

	HeapSort::Sort(a,num);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<a[i]<< ", ";
		i++;	
	}
}

