/* Algorithm


*/

/* Notes



*/

#include<iostream>
#include<time.h>
using namespace std;

class RandomizedQuickSort
{
	public:
		static void Sort(int *a, int p, int r)
		{
			if(p<r)
			{
				int q = RandomizedPartition(a, p, r);
				Sort(a,p,q-1);
				Sort(a,q+1,r);
			}			
		}
		
		static int RandomizedPartition(int *a, int p, int r)
		{
			int i = Random(p,r);
			Swap(&a[r], &a[i]);
			return Partition(a,p,r);
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

		static int Random(int a, int b)
		{
			srand((unsigned int)time(NULL));
			return (rand() % (b - a + 1) + a);			
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

	RandomizedQuickSort::Sort(a,0,num-1);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<a[i]<< ", ";
		i++;	
	}	
	
}
