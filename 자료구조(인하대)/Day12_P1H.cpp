#include <iostream>
#include <vector>
#define MAX 353333
#define NOITEM 0
#define ISITEM 1
using namespace std;
class cell {
public:
    int value;
    int flag;
    int key;
    cell() {
        value = -1;
        key = -1;
        flag = NOITEM;
    }
    ~cell() {
    }
};
int hashFunc1(int idx) {
    return idx % MAX; // arr�� ũ��
}
void tableInsertLinear(int key, int value, vector<cell>& arr)
{
    int idx = hashFunc1(key);
    if (arr[idx].flag == NOITEM)
    {
        arr[idx].value = value;
        arr[idx].key = idx;
        arr[idx].flag = ISITEM;       
    }
    else // collision �߻��� ���
    {
        while (arr[idx].flag != NOITEM)
        {
            idx++;
        }
        arr[idx].value = value;
        arr[idx].key = idx;
        arr[idx].flag = ISITEM;
    }
}
void table_Delete(int key, int value, vector<cell>&arr)
{
    int idx = hashFunc1(key);
    int search = 1;
    while (search / MAX != 1)
    {
        if (arr[idx].flag == NOITEM)
        {
            cout << 0 << " " << search << endl;
            break;
        }
        else if (arr[idx].value == value)
        {
            arr[idx].value = -1;
            cout << 1 << " " << search << endl;
            break;
        }
        idx++;
        search++;
    }
}
int main()
{
    int testCase, delNum, size, num;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        vector<cell>arr(MAX);      
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            cin >> num;
            tableInsertLinear(num, num, arr);
        }       
        cin >> delNum;
        for (int j = 0; j < delNum; j++)
        {
            cin >> num;
            table_Delete(num, num, arr);
        }
    }
    return 0;
}