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
    int treeSize;
    vector<Node*>node_list;
public:
    Tree(int size)
    {
        this->treeSize = size;
        root = new Node(1);
        node_list.push_back(root);
    }
    ~Tree() {}; 
    Node* getRoot() { return root; }
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
    void visit(Node* cur)
    {
        cout << cur->data << " ";
    }
    void preorder(Node* cur)
    {
        if (cur->child.size() != 0)
        {
            visit(cur);
            for (int i = 0; i < cur->child.size(); i++)
            {
                preorder(cur->child[i]);
            }
        }
        else
        {
            visit(cur);
            return;
        }
    }
    void postorder(Node* cur)
    {
        if (cur->child.size() != 0)
        {            
            for (int i = 0; i < cur->child.size(); i++)
            {
                postorder(cur->child[i]);
            }
            visit(cur);
        }
        else
        {
            visit(cur);
            return;
        }
    }
};

int main()
{
    int testCase;
    cin >> testCase;
    int num1,num2,num3;
    for (int i = 0; i < testCase; i++)
    {
        cin >> num1;
        Tree tree(num1);
        for (int j = 0; j < num1; j++)
        {
            cin >> num2>>num3;
            tree.insertNode(num2, num3);
        }
        tree.preorder(tree.getRoot());
        cout << endl;
        tree.postorder(tree.getRoot());
        cout << endl;
    }
    return 0;
}