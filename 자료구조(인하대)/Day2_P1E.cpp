#include<iostream>
#include<string>
using namespace std;

class Array
{
private:
	int* arr;
	int arrSize;
public:
	Array(int sz)
	{
		this->arrSize = sz;
		this->arr = new int[arrSize];
		for (int i = 0; i < sz; i++)   
		{
			arr[i] = 0;
		}
	}
	int at(int idx)
	{
		if (arr[idx] == 0) {
			return 0;
		}
		else
			return arr[idx];
	}
	void set(int idx, int value)
	{
		if (arr[idx] == 0)
			cout << arr[idx] << "\n";
		else
		{
			arr[idx] = value;
		}
	}
	void add(int idx, int value)
	{
		if (arr[idx] == 0)
		{
			for (int i = 0; i <= idx; i++)
			{
				if (arr[i] == 0)
				{
					arr[i] = value;
					break;
				}
			}
		}
		else
		{
			for (int i = arrSize - 2; i >= idx; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[idx] = value;
		}
	}
};
int main()
{
	int M;
	cin >> M;
	Array arr(10000);
	for (int i = 0; i < M; i++)
	{
		int num1, num2;
		string str;
		cin >> str;
		if (str == "add")
		{
			cin >> num1 >> num2;
			arr.add(num1, num2);
		}
		else if (str == "at")
		{
			cin >> num1;
			cout<<arr.at(num1)<<"\n";
		}
		else if (str == "set")
		{
			cin >> num1 >> num2;
			arr.set(num1, num2);
		}
	}
	return 0;
}