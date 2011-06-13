/* Algorithm 
	
         for i <- 1 to length[A]-1 do
                value <- A[i] 
                j <- i-1
                while j >= 0 and A[j] > value do 
                         A[j + 1] = A[j];
                         j <- j-1
                A[j+1] <- value
*/

/* Notes
		1> In-place
		2> Online algorithm		
	
*/


#include<iostream>
using namespace std;

class InsertionSort
{
	public:
		static void Sort(int *a, int num)
		{
			int value,j;
			for(int i=1;i<num;i++)
			{
				value = *(a+i);		// value = a[i]
				j = i-1;
				while(j>=0 && *(a+j) > value)		// a[j] > value
				{
					*(a+j+1) = *(a+j);
					j--;
				}
				*(a+j+1) = value;
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

	InsertionSort::Sort(a,num);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<a[i]<< ", ";
		i++;	
	}
}
