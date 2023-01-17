#include<iostream>
#include<string>
using namespace std;

class Array
{
private:
	int* arr;
	int arrSize;
	int korea=0, japan=0, china=0;
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
	void set(int idx, int value)
	{			
		arr[idx] = value;
		if (idx % 3 == 0)
		{
			korea += value;
		}
		else if (idx % 3 == 1)
		{
			japan += value;
		}
		else if (idx % 3 == 2)
		{
			china += value;
		}
	}
	void print_total()
	{
		cout << korea << " " << japan << " " << china << "\n";
	}
};
int main()
{
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		Array arr(num);
		for (int j = 0; j < num; j++)
		{
			int num1;
			cin >> num1;
			arr.set(j, num1);
		}
		arr.print_total();
	}
	return 0;
}