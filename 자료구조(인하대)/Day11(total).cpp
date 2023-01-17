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
    void printDegree()  // P1E
    {
        int child = 0;
        if (right != NULL)
        {
            child++;
        }
        if (left != NULL)
            child++;
        cout << child << " ";
    }
    void printDepth()  // P1E
    {
        cout << Depth << endl;
    }
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
    void insertNode(int data)
    {
        Node* new_node = new Node(data);
        if (root == NULL)
        {
            root = new_node;
        }
        else
        {
            int Depth = 0; // P1E
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
            new_node->Depth = Depth;  // P1E
            if (Depth > height)   // P1H
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
    void transplant(Node* u, Node* v) // P2
    {
        if (u->parent == NULL)
            root = v;          // u�� root�� ��� v�� ��
        else if (u == u->parent->left)       // u�� ���� �ڽ��̸� u�� ���ְ� �� �ڸ��� ������ �ڽ��� ���� ����
            u->parent->left = v;
        else                    // u�� ������ �ڽ��̸�
            u->parent->right = v;
        if (v != NULL)
            v->parent = u->parent;
    }
    Node* Tree_Minimum(Node* node)  // P2
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }
    void Tree_Delete(int data)
    {
        Node* delNode = findNode(data);
        if (delNode == NULL)  // �ش� ������ ��尡 ���°��
            return;
        else if (delNode->left == NULL)  // �����ڽ��� ���� ���
        {
            transplant(delNode, delNode->right);
        }
        else if (delNode->right == NULL) // ������ �ڽ��� ���°��
        {
            transplant(delNode, delNode->left);
        }
        else // �Ѵ� �ִ°�� => case 2
        {
            Node* y = Tree_Minimum(delNode->right);
            if (y->parent != delNode)
            {
                transplant(y, y->right);
                y->right = delNode->right;
                y->right->parent = y;
            }
            transplant(delNode, y);
            y->left = delNode->left;
            y->left->parent = y;
            y = nullptr;
            delete y;
        }
        delete delNode;
    }
    void preorder(Node* cur)  // P2
    {
        if (root == NULL)
        {
            cout << 0 << endl;
            return;
        }
        if (cur != NULL)
        {
            visit(cur);
            preorder(cur->left);
            preorder(cur->right);
        }
        return;
    }
    void visit(Node*& cur)  // P2
    {
        cout << cur->data << " ";
    }
    Node* getRoot() { return root; }  // P2
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
        int delNum;
        cin >> delNum;
        for (int j = 0; j < delNum; j++)
        {
            int num;
            cin >> num;
            tree.Tree_Delete(num);
        }
        tree.preorder(tree.getRoot());
        cout << "\n";
    }
    return 0;
}