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
	void add(int idx, int value)  // 어렵
	{
		if (arr[idx] == 0)   // idx의 원소가 없는 경우
		{
			for (int i = 0; i <= idx; i++)
			{
				if (arr[i] == 0)    // 마지막 원소를 찾고
				{
					arr[i] = value;  // 그다음의 비어있는 곳에 value 집어넣음
					break;
				}
			}
		}
		else            // idx에 원소가 있다면
		{
			for (int i = arrSize - 2; i >= idx; i--) // arr[i+1]=arr[i] 이므로 끝에서 부터 연산해야함
			{                                        // arr[i+1]의 가장 끝은 i가 arrSize-2인 -> arr[i-1] / i는 idx까지 복사해야 하므로 >=
				arr[i + 1] = arr[i];                     
			}
			arr[idx] = value;   // 마지막에 원하는 index에 원하는 value add
		}		
	}
	int remove(int idx)  // 어렵
	{
		if (arr[idx] == 0)   // 원소가 비어있다면 return 0
			return 0;
		else
		{
			int num = arr[idx];                 // 삭제할 원소 저장
			for (int i = idx; i < arrSize-1; i++)     // arr[i]=arr[i+1]이므로 앞에서 부터 연산이고 i는 arrSize-2까지
			{				
				arr[i] = arr[i + 1];
				if (i == arrSize-2) {
					arr[i + 1] = 0;   // 마지막 data 비워주기
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