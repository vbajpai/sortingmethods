/* Algorithm 
	
  

*/

/* Notes
	

	
*/

/* Example
  

  
*/

#include<iostream>
#include<cmath>				// for floor function
using namespace std;

int num=0; 					// Globally Declared !

class BucketSort;

class Queue
{
	public:
	
		float *q;						
		int rear, front;
		int size;
		
		Queue()
		{
			q = new float[num];
			this->size = num;
			rear = front = size-1;			
		}
		
		void Add(float x)
		{
			if(rear == size-1)
				rear = 0;
			else
				rear++;
			
			if(rear == front)
			{
				cout<<"Queue Overflow!";
				exit(1);
			}
			
			q[rear] = x;			
		}
		
		bool Empty()
		{
			if(rear==front)
				return true;
			else
				return false;	
		}
		
		int Place(float *a, int j)
		{
			while(front != rear)
			{
				if(front == size-1)
					front = 0;
				else
					front++;
				
				a[j++] = q[front];	
			}
			return j;			
		}
		
		int Size()
		{
			int temp = front,count=0;
			while(temp != rear)
			{
				if(temp == size -1)
					temp = 0;
				else
					temp++;
										
				count++;					
			}	
			return count;
		}	
		
};

class InsertionSort
{
	public:
		static void Sort(Queue *q, int num)
		{
			float value;
			int j;
			
			for(int i=1;i<num;i++)
			{
				value = q->q[i];		
				j = i-1;
				while(j>=0 && q->q[j] > value)		
				{
					q->q[j+1] = q->q[j];
					j--;
				}
				q->q[j+1] = value;
			}
		}

};

class BucketSort
{	
	public:	
	
		static void Sort(float *a, int num)
		{
			Queue q[num];					 
			
			for(int i=0; i<num;i++)
				q[(int)floor(num*a[i])].Add(a[i]);
			
					
			for(int i=0;i<num;i++)
			{
				int size = q[i].Size();
				InsertionSort::Sort(&q[i],size);
			}
								
			for(int i=0,j=0;i<num;i++)
			{
						if(!q[i].Empty())
						{
							j = q[i].Place(a,j);	
						}
			}		
		}
};

int main()
{
	int i=0;
	cout<<"No. of elements:";
	cin>>num;
	
	float a[num];
	cout<<"\nEnter Values between [0,1)!\n"<<endl;
	while(i<num)
	{
		cout<<"Value for a["<<i<<"]:";
		cin>>a[i++];		
	}	
	
	BucketSort::Sort(a,num);

	cout<<"\n\nSorted Array:";
	i=0;
	while(i<num)
	{
		cout<<a[i]<< ", ";			
		i++;	
	}
}
