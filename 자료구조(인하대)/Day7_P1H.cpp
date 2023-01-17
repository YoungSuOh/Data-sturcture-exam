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
    ~Node() {};
    void insertChild(Node* child)
    {
        this->child.push_back(child);

        return;
    }
};
class Tree
{
private:
    Node* root;
    vector<Node*>node_list;
public:
   
    Tree(int data)
    {
        root = new Node(data);
        node_list.push_back(root);
    }
    ~Tree() {};
    Node* findNode(int data)
    {
        for (unsigned int i = 0; i < node_list.size(); i++)
        {
            if (node_list[i]->data == data)
                return node_list[i];
        }
        return NULL;
    }
    void insertNode(int parent_data, int data)
    {
        if (findNode(parent_data)==NULL) cout << -1 << endl;
        else
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
    }  
    void printchild(int data)
    {
        if (findNode(data) == NULL) cout << -1 << endl;
        else
        {
            Node* printNode = findNode(data);
            if (printNode->child.size() == 0)
            {
                cout << 0 << endl;              
            }
            else
            {
                for (unsigned int i = 0; i < printNode->child.size(); i++)
                {
                    cout << printNode->child[i]->data << " ";
                }
                cout << endl;               
            }
            printNode = nullptr;
            delete printNode;
        }      
    }
    int countDepth(Node* current)
    {
        if (current == NULL)
            return -1;
        else if (current->parent == NULL)  // root case
            return 0;
        else
            return countDepth(current->parent) + 1;  // 재귀적으로 들어가면서 +1씩
    }  
};
int main()
{
    int testCase;
    cin >> testCase;  
    Tree tree(1);
    for (int i = 0; i < testCase; i++)
    {        
        int num1, num2;
        string str;
        cin >> str;
        if (str == "insert")
        {       
            cin >> num1 >> num2;
            tree.insertNode(num1, num2);
        }
        else if (str == "printChild")
        {       
            cin >> num1;
            tree.printchild(num1);
        }
        else if (str == "printDepth")
        {        
            cin >> num1;
            cout << tree.countDepth(tree.findNode(num1))<<endl;
        }
    }   
    return 0;
}