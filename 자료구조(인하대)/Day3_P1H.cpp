#include<iostream>
#include<string>
using namespace std;

class Node // Node�� public����
{
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
class SLinkedList
{
public:
	Node* head;
	Node* tail;

	SLinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	bool empty()
	{
		if (head == NULL) return true;
		else
			return false;
	}
	int front()
	{
		if (empty()) return -1;
		else
		{
			return head->data;
		}
	}
	void addFront(int x)
	{
		Node* new_node = new Node(x);
		if (empty())
		{
			head = tail = new_node;
		}
		else
		{
			new_node->next = head;  // ���� �տ� ���� ���
			head = new_node;        // head�� new_node�� �ٲ�(���� �տ� ������..)
		}
	}
	int removeFront()
	{
		if (empty()) return -1;
		else
		{
			Node* delete_node = head;
			int num = delete_node->data;
			head = delete_node->next;
			if (head == NULL)
				tail == NULL;
			delete delete_node;
			return num;
		}
	}
	void showList()
	{
		if (empty()) cout << -1 << endl;
		else
		{
			Node* cur = head;
			while (cur != NULL)
			{
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << endl;
			delete cur;
		}
	}
	void addBack(int x)
	{
		Node* new_node = new Node(x);

		if (empty())           // if(head==NULL) ���
		{
			head = tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
	}           // ���⼭ new_node�� delete�ϸ� �ȵ�
};
int main()
{
	SLinkedList list;
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int num;
		string str;
		cin >> str;
		if (str == "addFront")
		{
			cin >> num;
			list.addFront(num);
		}
		else if (str == "removeFront")
		{
			cout << list.removeFront() << endl;
		}
		else if (str == "front")
		{
			cout << list.front() << endl;
		}
		else if (str == "empty")
		{
			cout << list.empty() << endl;
		}
		else if (str == "showList")
		{
			list.showList();
		}
		else if (str == "addBack")
		{
			cin >> num;
			list.addBack(num);
		}
	}
}