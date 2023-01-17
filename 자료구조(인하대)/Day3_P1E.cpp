#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	
	Node(int e)
	{
		this->data = e;
		this->next = NULL;
	}
};
class S_LinkedList
{
public:
	Node* head;
	Node* tail;
	S_LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void addFront(int X)
	{
		if (empty())
		{
			Node* currentNode = new Node(X);
		}
		else
		{
			Node* current = new Node(X);
			current->next = head;
		}		
	}
	int removeFront()
	{
		if (empty())
			return-1;
		else
		{
			Node* currentNode = head;
			int num = currentNode->data; // data ÀúÀå
			head->next = head;
			delete currentNode;
			return num;
		}
	}
	int front()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			Node* currentNode = head;
			int num= currentNode->data;			
			delete currentNode;
			cout << num << endl;
		}
	}
	int empty()
	{
		if (head == NULL && tail == NULL)
		{
			return 1;
		}
		else
			return 0;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	cin >> num;
	S_LinkedList node;
	for (int i = 0; i < num; i++)
	{
		string str;
		cin >> str;
		if (str == "empty")
		{
			cout<<node.empty()<<"\n";
		}
		else if (str == "front")
		{
			cout<<node.front()<<endl;
		}
		else if (str == "removeFront")
		{			
			cout << node.removeFront() << endl;
		}
		else if (str == "addFront")
		{
			int num1;
			cin >> num1;
			node.addFront(num1);
		}
	}
	return 0;
}
