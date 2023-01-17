#include<iostream>

using namespace std;

class arrayStack
{
public:
	int* S;
	int capacity;
	int t;  //top

	arrayStack(int capacity) {
		this->capacity = capacity;
		this->S = new int[capacity];
		this->t = -1;
	}
	bool empty()
	{
		if (t == -1)
			return true;
		else
			return false;
	}
	int top()
	{
		if (t == -1) {
			return -1;
		}
		else {
			return S[t];
		}
	}
	void push(int e) {
		t++;
		S[t] = e;
	}
};
int main()
{
	int testCase;
	cin >> testCase;
	arrayStack stack(10);
	for (int i = 0; i < testCase; i++)
	{
		string order;
		cin >> order;
		if (order == "empty")
		{
			cout << stack.empty() << "\n";
		}
		else if (order == "top")
		{
			cout << stack.top() << "\n";
		}
		else if (order == "push")
		{
			int num;
			cin >> num;
			stack.push(num);
		}
	}
}