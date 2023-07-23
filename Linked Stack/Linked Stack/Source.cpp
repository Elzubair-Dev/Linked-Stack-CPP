using namespace std;
#include <iostream>
#include <string>
template <class t>
class LStack
{
public:
	struct node
	{
		t item;
		node* next;
	};
	node* top, *cur;
	LStack()
	{
		top = NULL;
	}
	void push(t newitem)
	{
		node* nodee = new node;
		nodee->item = newitem;
		nodee->next = top;
		top = nodee;
	}
	bool isEmpty()
	{
		return top == NULL;
	}
	void pop()
	{
		if (isEmpty())cout << "Stack is Empty in pop\n";
		else
		{
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void pop(t &topitem)
	{
		if (isEmpty())cout << "Stack is Empty in pop\n";
		else
		{
			topitem = top->item;
			node* temp = top;
			top = top->next;
			temp = temp->next = NULL;
			delete temp;
		}
	}
	void display()
	{
		cur = top;
		if (top->next == NULL) cout << "Stack is empty in display\n";
		else
		{
			while (cur != NULL)
			{
				cout << "| " << cur->item << " |\n";
				cur = cur->next;
			} 
		}
	}

};
int main()
{
	LStack<char>s;
	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');
	s.pop();
	char x;
	s.push('E');
	s.display();
	cout << "--------------------------------------------\n";
	s.pop(x);
	s.display();
	cout << "Last poped element is: " << x << "\n";
	return 0;
}