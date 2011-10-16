/* Algorithm

It works by first finding the smallest element using a linear scan and swapping it into the first position in the list, then finding the second smallest element by scanning the remaining elements, and so on

*/

/* Notes

1> in-place comparison sort.

2> Θ(n2) complexity

3> Selection sort can also be used on list structures that make add and    remove efficient,    such as a linked list. In this case it's more common to remove the minimum element from      the remainder of the list, and then insert it at the end of the values sorted so far

4> (n - 1) + (n - 2) + ... + 2 + 1 = n(n - 1) / 2 = Θ(n2) comparisons

5> selection sort always outperforms bubble sort and gnome sort, but is generally outperformed by insertion sort. Insertion sort is very similar in that after the kth iteration, the first k elements in the array are in sorted order. Insertion sort's advantage is that it only scans as many elements as it needs to in order to place the k + 1st element, while selection sort must scan all remaining elements to find the k + 1st element.

6> Finally, selection sort is greatly outperformed on larger arrays by Θ(nlog n) divide-and-conquer algorithms such as quicksort and mergesort. However, insertion sort or selection sort are both typically faster for small arrays (ie less than 10-20 elements).
*/

#include<iostream>
using namespace std;

class SelectionSort
{
	public:
		static void Sort(int *a, int num)
		{
			int i = 0;			
			while(i<num-1)
			{
				int j = i+1, min = i;
				while(j<num)
				{
					if(*(a+j) < *(a+min))
						min = j;
					j++;
				}
				swap(&a[i], &a[min]);				
				i++;
			}			
		}

		static void swap(int *a, int *b)
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

	SelectionSort::Sort(a,num);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<a[i]<< ", ";
		i++;	
	}
	
	
}
