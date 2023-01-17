#include<iostream>
#include<string>

using namespace std;

class arrQueue
{
public:
    int* Q;
    int capacity;
    int f;
    int r;
    int score;
    arrQueue(int size)
    {
        this->Q = new int[size];
        this->capacity = size;
        this->f = 0;
        this->r = -1;
        this->score = 0;
    }
    ~arrQueue()
    {
        delete[] Q;
    }
    bool empty()
    {
        return (r == -1);
    }
    int front()
    {
        if (empty())
            return 0;
        else
        {
            return Q[f];
        }
    }
    void enqueue(int data)
    {
        if (r == capacity - 1)
            cout << "Full" << endl;
        else
        {
            r++;
            Q[r] = data;
        }
    }
    void dequeue()
    {
        if (empty())
            cout << "Empty" << endl;
        else
        {
            for (int i = 0; i < r; i++)
            {
                Q[i] = Q[i + 1];
            }
            r--;
        }
    }
    void add(int left)
    {
        Q[f + 1] += left;
        score++;
    }
};
void makeCard(arrQueue& arr, int size)
{
    int num;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        arr.enqueue(num);
    }
}
void playGame(arrQueue& arr1, arrQueue& arr2, int compete)
{
    int num;
    for (int i = 0; i < compete; i++)
    {
        if (arr1.front() > arr2.front())
        {
            num = arr1.front() - arr2.front();
            arr1.add(num - 1);
        }
        else if (arr1.front() < arr2.front())
        {
            num = arr2.front() - arr1.front();
            arr2.add(num - 1);
        }
        arr1.dequeue();
        arr2.dequeue();
    }
}
int result(arrQueue& arr1, arrQueue& arr2)
{
    if (arr1.score > arr2.score) { return 1; }
    else if (arr1.score < arr2.score) { return 2; }
    else
        return 0;
}
int main()
{
    int  testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int size;
        cin >> size;
        arrQueue arr1(size);
        arrQueue arr2(size);
        makeCard(arr1, size);
        makeCard(arr2, size);
        playGame(arr1, arr2, size);
        cout << result(arr1, arr2) << endl;
    }
    return 0;
}