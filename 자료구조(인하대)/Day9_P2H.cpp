#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum direction {
    MIN = 1, MAX = -1
};

class Heap {
public:
    vector<int> v;
    long long heap_size;
    int root_index;
    int direction;       // Min-Heap or Max-Heap  
    Heap(int direction) {
        v.push_back(-1);
        this->heap_size = 0;
        this->root_index = 1;
        this->direction = direction;
    }
    void swap(int idx1, int idx2) {
        int tmp = v[idx1];
        v[idx1] = v[idx2];
        v[idx2] = tmp;
    }
    void upHeap(int idx) {    // insertion
        if (idx == 1) {
            return;
        }
        else if (v[idx] * direction < v[idx / 2] * direction)
        {
            swap(idx, idx / 2);
            idx = idx / 2;
            upHeap(idx);
        }
    }

    void insert(int data) {
        v.push_back(data);
        heap_size++;
        upHeap(heap_size);
    }

    int size() {
        return heap_size;
    }

    bool isEmpty() {
        if (heap_size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    void print() {
        if (isEmpty()) {
            cout << -1;
        }
        else {
            for (int i = 1; i < v.size(); i++) {
                cout << v[i] << " ";
            }
        }
        cout << "\n";
    }
    int sort_Upper() {
        if (isEmpty())
            return 0;
        int min = v[1];
        v[1] = v.back();
        v.pop_back();
        heap_size--;
        int now = 1; //현재 노드
        int left = now * 2;//왼쪽 자식
        int right = now * 2 + 1; //오른쪽 자식
        while (left <= heap_size) //자식이 있는 경우
        {
            //자식이 2명인 경우(오른쪽 자식이 있는 경우)
            if (right <= heap_size)
            {
                if (v[left] > v[right])//오른쪽 자식이 더 크면
                {
                    if (v[right] > v[now]) 
                        break;
                    swap(now, right);
                    now = right;
                    left = now * 2;
                    right = now * 2 + 1;
                }
                else//왼쪽자식이 더 큰 경우
                {
                    if (v[left] > v[now]) 
                        break;
                    swap(now, left);
                    now = left;
                    left = now * 2;
                    right = now * 2 + 1;
                }
            }
            else//자식이 1명인 경우(왼쪽 자식만 있는 경우)
            {
                if (v[left] > v[now]) 
                    break;
                swap(now, left);
                now = left;
                left = now * 2;
                right = now * 2 + 1;
            }
        }
        return min;
    }
    int sort_Lower() {
        if (isEmpty())
            return 0;
        int max = v[1];
        v[1] = v.back();
        v.pop_back();
        heap_size--;
        int now = 1; //현재 노드
        int left = now * 2;//왼쪽 자식
        int right = now * 2 + 1; //오른쪽 자식
        while (left <= heap_size) //자식이 있는 경우
        {
            //자식이 2명인 경우(오른쪽 자식이 있는 경우)
            if (right <= heap_size)
            {
                if (v[left] < v[right])//오른쪽 자식이 더 크면
                {
                    if (v[right] < v[now])
                        break;
                    swap(now, right);
                    now = right;
                    left = now * 2;
                    right = now * 2 + 1;
                }
                else//왼쪽자식이 더 큰 경우
                {
                    if (v[left] < v[now])
                        break;
                    swap(now, left);
                    now = left;
                    left = now * 2;
                    right = now * 2 + 1;
                }
            }
            else//자식이 1명인 경우(왼쪽 자식만 있는 경우)
            {
                if (v[left] < v[now])
                    break;
                swap(now, left);
                now = left;
                left = now * 2;
                right = now * 2 + 1;
            }
        }
        return max;
    }
};


int main() {
    int testCase;
    Heap min(MIN);  
    Heap max(MAX);
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        int input;
        int inputsize, PthN;
        vector<int>arr1;
        vector<int>arr2;
        cin >> inputsize >> PthN;

        for (int j = 0; j < inputsize; j++)
        {
            cin >> input;
            min.insert(input); 
            max.insert(input);
        }       
        cout << min.v[PthN]<<endl;        
        while (!min.isEmpty())
        {
            arr1.push_back(min.sort_Upper());            
        }
        cout << arr1[PthN-1] << endl;
        cout << max.v[PthN] << endl;
        while (!max.isEmpty())
        {
            arr2.push_back(max.sort_Lower());
        }
        cout << arr2[PthN - 1] << endl;
    }
    return 0;
}