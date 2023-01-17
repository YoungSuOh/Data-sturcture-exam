#include<iostream>

using namespace std;

class Node
{
public:
	int elem;
	Node* next;		
};
class C_LinkedList
{
public:
	C_LinkedList();
	bool Empty();
	void Print();
	void Append(int elem);
	void Delete(int idx);	
private:
	Node* head;
	Node* tail;
	Node* before;
	Node* cur;
	int numofData;
};
C_LinkedList::C_LinkedList()
{
	head = NULL;
	tail = NULL;
	before = NULL;
	cur = NULL;
	numofData = 0;	
}
bool C_LinkedList::Empty()
{
	return(head == NULL && tail == NULL);
}
void C_LinkedList::Print()
{
	if (Empty()) { cout << "empty" << endl; }
	else {
		cur = head;
		for (int i = 0; i < numofData; i++)
		{
			cout << cur->elem << " ";
			cur = cur->next;
		}	
		cout << endl;			
	}	
}
void C_LinkedList::Append(int elem) {	
	Node* new_node = new Node;
	new_node->elem = elem;	
	if (head==NULL) {		
		head = tail = new_node;
		new_node->next = new_node;
	}
	else {				
		new_node->next = tail->next; // tail->next는 항상 head가 됨. 지려따..
		tail->next = new_node;
		tail = new_node;
	}
	numofData++;
}
void C_LinkedList::Delete(int idx) //삭제된 데이터를 반환해주는 함수
{	
	if (head != NULL)
	{
		cur = head; //소멸 대상의 주소 값 저장
		before = tail;			
		for (int i = 0; i < idx; i++)
		{	
			before = cur;
			cur = cur->next;
		}
		if (head == cur)
		{
			before->next = head->next;
			head = head->next;
		}
		else
		{
			before->next = cur->next;
			cur = before;
		}		
		numofData--;		
	}		
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		C_LinkedList list;
		for (int j = 0; j < 10; j++)
		{
			int num1;
			cin >> num1;
			list.Append(num1);
		}		
		for (int j = 0; j < 3; j++)
		{
			string str;
			cin >> str;
			if (str == "Delete")
			{
				int num;
				cin >> num;
				list.Delete(num);
			}					
		}	
		list.Print();
	}	
		return 0;
}
