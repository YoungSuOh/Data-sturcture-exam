#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool findVertex(vector<int>& v, int num1, int num2)
{
    int num = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == num1)
            num++;
        else if (v[i] == num2)
            num++;
    }
    if (num == 2)
        return true;
    else
        return false;
}
int main()
{
    int vertexSize, edge, edgeSize, adjacentQ;
    cin >> vertexSize >> edge>>adjacentQ;
    edgeSize = edge;
    vector<int>vertex_list(vertexSize);
    vector<vector<bool>>matrix(2001, vector<bool>(2001));
    for (int i = 0; i < vertexSize; i++)
    {
        int num;
        cin >> num;
        vertex_list[i] = num;
    }
    for (int i = 0; i < edge; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;
        if (matrix[num1][num2] == true || matrix[num2][num1] == true)
        {
            cout << -1 << endl;
            edgeSize--;
            continue;
        }
        else if (findVertex(vertex_list, num1, num2) == false)
        {
            cout << -1 << endl;
            edgeSize--;
            continue;
        }
        matrix[num1][num2] = true;
        matrix[num2][num1] = true;
    }
    cout << vertexSize << " " << edgeSize << endl;
    for (int i = 0; i < adjacentQ; i++)
    {
        int num1, num2;
        cin >> num1 >> num2;        
        if (findVertex(vertex_list, num1, num2) == false)
        {
            cout << -1 << endl;                      
        }
        else if (matrix[num1][num2] == true || matrix[num2][num1] == true)
        {
            cout << 1 << endl;            
        }
        else if (matrix[num1][num2] == false && matrix[num2][num1] == false)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}