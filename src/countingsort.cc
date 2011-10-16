/* Algorithm 
	
       
*/

/* Notes
				
	
*/

#include<iostream>
using namespace std;

class CountingSort
{
	
	public:
		static void Sort(int *a, int *b, int num, int k)
		{
			int c[k+1];
			
			for(int i=0;i<=k;i++)
				c[i] = 0;
				
			for(int j=0;j<num;j++)
				c[a[j]] += 1;
			
			for(int i=1;i<=k;i++)
				c[i] += c[i-1];
				
			for(int j=num-1;j>=0;j--)
			{
				b[c[a[j]]-1] = a[j];
				c[a[j]] = c[a[j]] - 1;	
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
	
	/* Counting Sort Specific*/
	/*-------------------------*/
	int max = 0;
	for(i=0;i<num;i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	
	int b[num];
	/*-------------------------*/
	
	CountingSort::Sort(a,b,num,max);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<b[i]<< ", ";			//Counting Sort Specific
		i++;	
	}
}
