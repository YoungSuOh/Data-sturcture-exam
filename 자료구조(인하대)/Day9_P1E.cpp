#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Heap
{
private:
    vector<int>v;
    int heapSize;
    int root_index;

public:
    Heap()
    {
        v.push_back(-1);
        this->heapSize = 0;
        this->root_index = 1;
    }
    void uphead(int idx)
    {
        if (idx <= 1)
            return;
        else if (v[idx] < v[idx / 2])
        {
            int num = v[idx];
            v[idx] = v[idx / 2];
            v[idx / 2] = num;
            uphead(idx / 2);
        }
    }
    void insert(int data)
    {
        heapSize++;
        v.push_back(data);
        uphead(v.size() - 1);
    }
    int size()
    {
        return heapSize;
    }
    bool isEmpty()
    {
        return heapSize == 0;
    }
    int top()
    {
        if (isEmpty())
            return -1;
        else
            return v[1];
    }
    void print()
    {
        if (isEmpty())
            cout << -1 << endl;
        else
        {
            for (unsigned int i = 1; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int testCase;
    cin >> testCase;
    string str;
    Heap vec;
    for (int i = 0; i < testCase; i++)
    {
        cin >> str;
        if (str == "isEmpty")
        {
            cout << vec.isEmpty() << endl;
        }
        else if (str == "size")
        {
            cout << vec.size() << endl;
        }
        else if (str == "insert")
        {
            int num;
            cin >> num;
            vec.insert(num);
        }
        else if (str == "top")
        {
            cout << vec.top() << endl;
        }
        else if (str == "print")
        {
            vec.print();
        }
    }
}