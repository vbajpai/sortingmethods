// Merge Sort Algorithm Implementation//

/* Algorithm

   function mergesort(m)
	var list left, right, result
	if length(m) ≤ 1
		return m
	else
		var middle = length(m) / 2
		for each x in m up to middle
		add x to left
		for each x in m after middle
		add x to right
		left = mergesort(left)
		right = mergesort(right)
		result = merge(left, right)
		return result


   function merge(left,right)
	var list result
	while length(left) > 0 and length(right) > 0
		if first(left) ≤ first(right)
		append first(left) to result
		left = rest(left)
		else
		append first(right) to result
		right = rest(right)
	if length(left) > 0 
		append rest(left) to result
	if length(right) > 0 
		append rest(right) to result
	return result

*/

/* Notes

1> divide and conquer algorithmic paradigm

2> Complexity : O(n log n)

3> It is stable, meaning that it preserves the input order of equal elements in the sorted      output.

4> Merge sort is more efficient than quicksort for some types of lists if the data to be sorted can only be efficiently accessed sequentially as in Linked List 

*/

#include<iostream>
using namespace std;

class MergeSort
{
	public:
	
	static void Merge(int *a,int *b,int *c,int num1, int num2)
	{
		int apoint = 0;
		int bpoint = 0;
		int cpoint = 0;
		int UB1 = num1-1;
		int UB2 = num2-1;
		
		
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

	static void Sort(int *a,int num)
	{
		int left[num], right[num], result[num];
		if(num>1)
		{
			int middle = num / 2;
			int k;

			for(int i=0;i<middle;i++)
			 	left[i] = a[i];
	
			for(int i=middle,k=0;i<num;i++,k++)
		 		right[k] = a[i];

			Sort(left,middle);
			Sort(right,num-middle);
			Merge(left, right, result, middle, num-middle);

			for(int i=0;i<num;i++)
				a[i] = result[i];			
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

	MergeSort::Sort(a,num);

	cout<<"\n\nSorted Array:";
	i=0;

	while(i<num)
	{
		cout<<a[i]<< ", ";
		i++;	
	}
}
