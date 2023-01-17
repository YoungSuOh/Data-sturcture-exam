#include <iostream>
#include <vector>
#define MAX 353333
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2
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
    return idx % MAX; // arr의 크기
}
int hashFunc2(int idx) {
    return (17-(idx%17)); 
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
    else // collision 발생한 경우
    {      
        while (arr[idx].flag != NOITEM)
        {
            idx = hashFunc1(idx + hashFunc2(key));
        }
        arr[idx].value = value;
        arr[idx].key = idx;
        arr[idx].flag = ISITEM;
    }
}
void tableSearchLinear(int key, int value, vector<cell>& arr)
{
    int idx = hashFunc1(key);
    int search = 1;
    while (arr[idx].flag != NOITEM)
    {      
        if (arr[idx].value == value)
        {
            cout << 1 << " " << search << endl;
            break;
        }
        idx = hashFunc1(idx+hashFunc2(key));        
        search++;
    }
    if (arr[idx].flag == NOITEM)
    {
        cout << 0 << " " << search << endl;       
    }
}
int main()
{
    int testCase, searchNum, size, num;
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
        cin >> searchNum;
        for (int j = 0; j < searchNum; j++)
        {
            cin >> num;
            tableSearchLinear(num, num, arr);
        }
    }
    return 0;
}