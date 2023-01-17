#include<iostream>
#include<string>
using namespace std;

class Array
{
private:
	int* arr;
	int arrSize;
	int korea = 0, japan = 0, china = 0;      // �ٷ� ���� ����
	int korean = 0, japanese = 0, chinese = 0;  // �ٷ� ���� ����
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
	void set(int idx, int value)        // ���� ���������� set�Լ��� �����
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
		if (korean == 0)        // ����ó��-> ���ڰ� 0�� �ɰ�츦 �׻� �����ض�
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
		Array arr(num);                 // Array ������ ù for�� �ȿ� ������
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