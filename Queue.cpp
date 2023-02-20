#include<iostream>
using namespace std;
class Queue
{
	int maxSize, currSize, front, rear;
	int* arr;
public:
	void createQueue(int size)
	{
		maxSize = size;
		arr = new int[maxSize];
		currSize = 0;
		rear = -1;
		front=0;
	}
	bool isEmpty()
	{
		if (currSize == 0)
			return 1;
		return 0;
	}
	bool isFull()
	{
		if (currSize == maxSize)
			return 1;
		return 0;
	}
	bool enqueue(int val)
	{
		if (isFull())
		{
			cout << "Queue is Full\n";
			return 0;
		}
		else
		{
			rear=(rear+1)%maxSize;
			arr[rear] = val;
			currSize++;
			return 1;
		}
	}
	
	//remove value from top
	int dequeue()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty\n";
			return -1000;
		}
		else
		{
			int val = arr[front];
			front=(front+1)%maxSize;
			currSize--;
			return val;
		}
	}
	
	//display value at top
	int getRear()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty\n";
			return -1000;
		}
		else
		{
			return arr[rear];
		}
	}
	
	//int getFront()
	void displayAll()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            Queue s;
            s.createQueue(maxSize);
            while (currSize != 0)
            {
                int val = dequeue();
                cout << val << endl;
                s.enqueue(val);
            }
            while (s.currSize != 0)
            {
                enqueue(s.dequeue());
            }
        
        }
    }
    
    
		//delete a queue
		
};
int main()
{
	Queue s1;
	int n;
	cout << "Enter Queue size: ";
	cin >> n;
	
	//creating a stack
	cout<<"\nCreating a queue\n";
	s1.createQueue(n);
	
	//enqueuing/putting values in the created stack
	cout<<"\nEnqueuing/putting values in the created queue\n";
	s1.enqueue(7);
	s1.enqueue(8);
	s1.enqueue(9);
	s1.enqueue(10);
	s1.enqueue(11);
	
	
	//displaying all values in the queue
	cout<<"\nSisplaying all values in the queue\n";
	s1.displayAll();
	
	//displaying the value at top in the stack
	cout<<"\ndisplaying the value at rear in the queue\n";
	cout << "\nRear of the Queue is: " << s1.getRear() << endl;

	//dequeuing/removing a value from front
	cout<<"\ndequeue/removing a value from front\n";
	s1.dequeue();
	
	//displaying all values in the queue
	cout<<"\nDisplaying all values in the queue\n";
	s1.displayAll();
	
	
	
	system("pause");
}
