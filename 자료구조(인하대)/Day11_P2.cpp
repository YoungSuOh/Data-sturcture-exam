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
            Node* cur = root;
            Node* parent = NULL;
            while (cur != NULL)
            {
                parent = cur;    
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
    void Tree_Delete(int data)
    {
        Node* delNode = findNode(data);
        if (delNode == NULL)  // 해당 데이터 노드가 없는경우
            return;
        else if (delNode->left == NULL)  // 왼쪽자식이 없는 경우
        {
            transplant(delNode, delNode->right);
        }
        else if (delNode->right == NULL) // 오른쪽 자식이 없는경우
        {
            transplant(delNode, delNode->left);
        }
        else // 둘다 있는경우 => case 2
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
    void transplant(Node* u,Node* v)
    {
        if (u->parent == NULL)
            root = v;          // u가 root인 경우 v가 됨
        else if (u == u->parent->left)       // u가 왼쪽 자식이면 u를 없애고 그 자리에 오른쪽 자식을 집어 넣음
            u->parent->left = v;
        else                    // u가 오른쪽 자식이면
            u->parent->right = v;
        if (v != NULL)
            v->parent = u->parent;       
    }
    Node* Tree_Minimum(Node* node)
    {       
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }
    void preorder(Node* cur)
    {
        if (root == NULL)
        {
            cout << 0 << endl;
            return;
        }
        if (cur!= NULL)
        {
            visit(cur);
            preorder(cur->left);
            preorder(cur->right);
        }         
        return;
    }
    void visit(Node* cur)
    {
        cout << cur->data << " ";
    }
    Node* getRoot() { return root; }
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