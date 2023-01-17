#include<iostream>
#include<string>

using namespace std;

class arrQueue
{
public:
	int* Q;
	int capacity;
	int f;
	int r;
	arrQueue(int size)
	{
		this->Q = new int[size];
		this->capacity = size;
		this->f = 0;
		this->r = -1;
	}
	int size()
	{
		return r + 1;
	}
	bool empty()
	{
		return (r == -1);
	}
	void front()
	{
		if (empty())
			cout << "Empty" << endl;
		else
		{
			cout << Q[0] << endl;
		}
	}
	void rear()
	{
		if (empty())
			cout << "Empty" << endl;
		else
		{
			cout << Q[r] << endl;
		}
	}
	void enqueue(int data)
	{
		if (r == capacity - 1)
			cout << "Full" << endl;
		else
		{
			r++;
			Q[r] = data;
		}
	}
	void dequeue()
	{
		if (empty())
			cout << "Empty" << endl;
		else
		{
			int num = Q[f];
			for (int i = 0; i < r; i++)
			{
				Q[i] = Q[i + 1];
			}
			r--;
			cout << num << endl;
		}
	}
};
int main()
{
	int size, testCase;
	cin >> size >> testCase;
	arrQueue arr(size);
	for (int i = 0; i < testCase; i++)
	{
		int num;
		string str;
		cin >> str;
		if (str == "enqueue")
		{
			cin >> num;
			arr.enqueue(num);
		}
		else if (str == "dequeue")
		{
			arr.dequeue();
		}
		else if (str == "size")
		{
			cout << arr.size() << endl;
		}
		else if (str == "isEmpty")
		{
			cout << arr.empty() << endl;
		}
		else if (str == "front")
		{
			arr.front();
		}
		else if (str == "rear")
		{
			arr.rear();
		}
	}
	return 0;
}