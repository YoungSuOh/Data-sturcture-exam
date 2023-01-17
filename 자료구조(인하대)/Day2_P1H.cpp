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
	void add(int idx, int value)  // ���
	{
		if (arr[idx] == 0)   // idx�� ���Ұ� ���� ���
		{
			for (int i = 0; i <= idx; i++)
			{
				if (arr[i] == 0)    // ������ ���Ҹ� ã��
				{
					arr[i] = value;  // �״����� ����ִ� ���� value �������
					break;
				}
			}
		}
		else            // idx�� ���Ұ� �ִٸ�
		{
			for (int i = arrSize - 2; i >= idx; i--) // arr[i+1]=arr[i] �̹Ƿ� ������ ���� �����ؾ���
			{                                        // arr[i+1]�� ���� ���� i�� arrSize-2�� -> arr[i-1] / i�� idx���� �����ؾ� �ϹǷ� >=
				arr[i + 1] = arr[i];                     
			}
			arr[idx] = value;   // �������� ���ϴ� index�� ���ϴ� value add
		}		
	}
	int remove(int idx)  // ���
	{
		if (arr[idx] == 0)   // ���Ұ� ����ִٸ� return 0
			return 0;
		else
		{
			int num = arr[idx];                 // ������ ���� ����
			for (int i = idx; i < arrSize-1; i++)     // arr[i]=arr[i+1]�̹Ƿ� �տ��� ���� �����̰� i�� arrSize-2����
			{				
				arr[i] = arr[i + 1];
				if (i == arrSize-2) {
					arr[i + 1] = 0;   // ������ data ����ֱ�
				}
			}
			return num;
		}
	}
	void printArray()
	{
		if (arr[0] == 0) {   
			cout << 0 << endl;
		}
		else {
			int num = 0;
			while(arr[num]!=0)
			{
				cout << arr[num] << " ";
				num++;
			}
			cout << "\n";
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
		if (str == "at")
		{
			cin >> num1;
			cout << arr.at(num1) << "\n";
		}
		else if (str == "set")
		{
			cin >> num1 >> num2;
			arr.set(num1, num2);
		}
		else if (str == "add")
		{
			cin >> num1 >> num2;
			arr.add(num1, num2);
		}
		else if (str == "remove")
		{
			cin >> num1;
			cout<<arr.remove(num1)<<"\n";
		}
		else if (str == "printArray")
		{			
			arr.printArray();			
		}
	}
	return 0;
}