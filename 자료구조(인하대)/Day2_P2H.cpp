#include<iostream>
#include<string>
using namespace std;

class Array
{
private:
	int* arr;
	int arrSize;
	int korea = 0, japan = 0, china = 0;      // 바로 선언 ㄱㄱ
	int korean = 0, japanese = 0, chinese = 0;  // 바로 선언 ㄱㄱ
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
	void set(int idx, int value)        // 이전 문제에서의 set함수를 살려라
	{
		arr[idx] = value;
		if (idx % 3 == 0)
		{
			korea += value;
			if (value != 0)
				korean++;
		}
		else if (idx % 3 == 1)
		{
			japan += value;
			if (value != 0)
				japanese++;
		}
		else if (idx % 3 == 2)
		{
			china += value;
			if (value != 0)
				chinese++;
		}
	}
	void print_total()
	{
		cout << korea << " " << japan << " " << china << "\n";
	}
	void print_Average()
	{
		if (korean == 0)        // 예외처리-> 분자가 0이 될경우를 항상 주의해라
		{
			cout << 0 << " ";
		}
		else
			cout << korea / korean << " ";
		if (japanese == 0)
		{
			cout << 0 << " ";
		}
		else
			cout << japan / japanese << " ";
		if (chinese == 0)
		{
			cout << 0 << "\n";
		}
		else
			cout<<china / chinese << "\n";		
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
		Array arr(num);                 // Array 변수를 첫 for문 안에 만들어라
		for (int j = 0; j < num; j++)
		{
			int num1;
			cin >> num1;
			arr.set(j, num1);
		}
		arr.print_total();
		arr.print_Average();
	}
	return 0;
}