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
		else if (str == "size")
		{
			cout << arr.size() << endl;
		}
		else if (str == "isEmpty")
		{
			cout << arr.empty() << endl;
		}
	}
	return 0;
}