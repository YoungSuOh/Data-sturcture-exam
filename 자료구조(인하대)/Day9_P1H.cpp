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
    void downhead(int idx)
    {
        int num, max;
        if (2 * idx + 1 <= heapSize)
        {
            if (v[2 * idx] > v[2 * idx + 1])
                max = 2 * idx + 1;
            else
                max = 2 * idx;
            if (v[idx] > v[max])
            {
                num = v[idx];
                v[idx] = v[max];
                v[max] = num;
                downhead(max);
            }
            return;
        }
        else if (2 * idx == heapSize)
        {
            if (v[idx] > v[2 * idx])
            {
                num = v[idx];
                v[idx] = v[2 * idx];
                v[2 * idx] = num;
            }
            return;
        }
    }
    void insert(int data)
    {
        heapSize++;
        v.push_back(data);
        uphead(heapSize);
    }
    int size()
    {
        return heapSize;
    }
    bool isEmpty()
    {
        return heapSize == 0;
    }
    int pop()
    {
        if (isEmpty())
            return -1;
        else
        {
            int num = v[1];
            v[1] = v[heapSize];
            v.pop_back();
            heapSize--;
            downhead(1);
            return num;
        }
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
        else if (str == "pop")
        {
            cout << vec.pop() << endl;
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