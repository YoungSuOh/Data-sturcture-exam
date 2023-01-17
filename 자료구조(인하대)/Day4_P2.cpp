#include<iostream>
#include<string>
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
	int size() {
		return t + 1;
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
	int pop() {
		if (t == -1)
			return -1;
		else
		{
			int num = S[t];
			t--;
			return num;
		}
	}
};
int calculate(string str) {
    arrayStack Stack(10000);    
    int n = str.size(); 
    char cal;    

    for (int i = 0; i < n; i++) {    
		cal = str.at(i);
        if (cal-'0' >= 0 && cal-'0' <= 9) {
			Stack.push(cal-'0');
        }
        else
		{ //연산자
            int num1 = Stack.pop();
            int num2 = Stack.pop();

            if (cal == '+') {
                Stack.push(num1 + num2);

            }
            else if (cal == '-') {
                Stack.push(num2 - num1); // 이것만 주의하자
            }
            else if (cal == '*') {
                Stack.push(num1 * num2);
            }
            else if (cal =='/') {
                Stack.push(num2 / num1); // 이것만 주의하자
            }
        }
    }
    return Stack.top();
}
int main() {
    int testCase;   
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
		string str;
		cin >> str;
        cout << calculate(str) << endl;
    }
}