#include<iostream>
using namespace std;

class QuickSort
{
	public:
		static void Sort(int *a, int p, int r)
		{
			if(p<r)
			{
				int q = Partition(a, p, r);
				Sort(a,p,q-1);
				Sort(a,q+1,r);
			}			
		}
		
		static int Partition(int *a, int p, int r)
		{
			int x = a[r];
			int i = p - 1;	
			
			for(int j=p;j<=r-1;j++)
			{
				if(a[j] <= x)
				{
					i++;
					Swap(&a[i], &a[j]);
				}															
			}
			
			Swap(&a[i+1],&a[r]);
			return(i+1);
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

	QuickSort::Sort(a,0,num-1);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<a[i]<< ", ";
		i++;	
	}	
	
}
