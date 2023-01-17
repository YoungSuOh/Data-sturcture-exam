#include<vector>
#include<iostream>

using namespace std;

class Node
{
private:
    int data;    
    Node* parent;
    vector<Node*>child;
    friend class Tree;
public:
    Node(int data)
    {
        this->data = data;
        this->parent = NULL;       
    }
    ~Node()  {};
    void insertChild(Node* child)
    {
        this->child.push_back(child);
       
        return;
    }
    void delChild(Node* child)
    {
        for (int i = 0; i < this->child.size(); i++)
        {
            if (this->child[i] == child)
            {
                this->child.erase(this->child.begin() + i);
                break;
            }
        }       
        return;
    }

};
class Tree
{
private:
    Node* root;
    vector<Node*>node_list; 
public:
    Tree()
    {
        root = NULL;   
    }
    Tree(int data)
    {
        root = new Node(data);
        node_list.push_back(root);       
    }
    ~Tree() {};
    void insertNode(int parent_data, int data)
    {    
        for (unsigned int i = 0; i < node_list.size(); i++)
        {
            if (node_list[i]->data == parent_data)
            {
                Node* new_node = new Node(data);
                node_list[i]->child.push_back(new_node);
                new_node->parent = node_list[i];
                node_list.push_back(new_node);
                return;
            }       
        }
    }
    Node* findNode(int data)
    {
        for (unsigned int i = 0; i < node_list.size(); i++)
        {
            if (node_list[i]->data == data)
                return node_list[i];
        }
        return NULL;
    }
    void printchild(int data)
    {
        Node* printNode = findNode(data);
        for (unsigned int i = 0; i < printNode->child.size(); i++)
        {
            cout << printNode->child[i]->data << " ";
        }
        cout << endl;
        printNode = nullptr;
        delete printNode;
    }
};

int main()
{
    int testCase;
    cin >> testCase;
    Tree tree(1);              // 문제의 조건
    for (int i = 0; i < testCase; i++)
    {
        string str;
        cin >> str;
        if (str == "insert")
        {
            int num1, num2;
            cin >> num1 >> num2;
            tree.insertNode(num1, num2);
        }
        else if (str == "printChild")
        {
            int num1;
            cin >> num1;
            tree.printchild(num1);
        }
    }
    return 0;
}