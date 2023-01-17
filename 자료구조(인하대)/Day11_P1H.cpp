#include<iostream>
#include<string>

using namespace std;
class Node
{
public:
    int data;
    Node* parent;
    Node* right;
    Node* left;
    int Depth = 0;
    Node()
    {
        this->data = NULL;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
    }
    ~Node() {}
};
class BST
{
public:
    Node* root;
    int height;
    BST()
    {
        root = NULL;
        height = 0;
    }
    ~BST()
    {
        this->treeDestructor(this->root);
    }
    void insertNode(int data)
    {
        Node* new_node = new Node(data);
        if (root == NULL)
        {
            root = new_node;
        }
        else
        {
            int Depth = 0;
            Node* cur = root;
            Node* parent = NULL;
            while (cur != NULL)
            {
                parent = cur;
                Depth++;
                if (data < cur->data)
                {
                    cur = cur->left;
                }
                else
                {
                    cur = cur->right;
                }
            }
            new_node->parent = parent;
            new_node->Depth = Depth;
            if (Depth > height)
                height = Depth;
            if (data < parent->data)
            {
                parent->left = new_node;
            }
            else
            {
                parent->right = new_node;
            }
            cur = nullptr;
            parent = nullptr;
            delete cur;
            delete parent;
        }
    }
    Node* findNode(int data)
    {
        Node* cur = root;
        while (cur != NULL)
        {
            if (cur->data == data)
                return cur;
            else
            {
                if (cur->data < data)
                    cur = cur->right;
                else
                    cur = cur->left;
            }
        }
        return NULL;
    }
    void treeDestructor(Node* root)
    {
        if (root == NULL)
            return;
        if (root->left != NULL)
            this->treeDestructor(root->left);
        if (root->right != NULL)
            this->treeDestructor(root->right);
        delete root;
    }

};
int main()
{
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int treeSize;
        cin >> treeSize;
        BST tree;
        for (int j = 0; j < treeSize; j++)
        {
            int num;
            cin >> num;
            tree.insertNode(num);
        }
        cout << tree.height << endl;
    }
    return 0;
}