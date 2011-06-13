#include<iostream>
using namespace std;

class BubbleSort
{
	public:
		static void Sort(int *a, int num)
		{
			bool swap;
			do
			{
				swap = false;
				int i = 0;
				while(i<num-1)
				{
					if(a[i] > a[i+1])
					{
						Swap(&a[i], &a[i+1]);
						swap = true;
					}
					i++;
						
				}
			}while(swap);
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

	BubbleSort::Sort(a,num);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<a[i]<< ", ";
		i++;	
	}
	
	
}
