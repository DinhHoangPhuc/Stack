#include<stdio.h>
#include<string.h>

struct Node
{
	char info;
	Node* next;
};

struct Stack
{
	Node* top;
};

Node* createNode(char x);
void pushS(Stack& s, Node* p);
bool isEmpty(Stack s);
void popS(Stack& s, char& x);
bool bieuThucCanBang(Stack& s, char bieuThuc[]);

void main()
{
	char str[20];
	rewind(stdin);
	printf("Nhap: ");
	gets_s(str);
	Stack s;
	s.top = NULL;
	if (bieuThucCanBang(s, str))
		printf("Bieu thuc can bang\n");
	else
		printf("Bieu thuc khong can bang\n");
}

Node* createNode(char x)
{
	Node* p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nhu de cap phat\n");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void pushS(Stack& s, Node* p)
{
	if (p != NULL)
		if (s.top == NULL)
			s.top = p;
		else
		{
			p->next = s.top;
			s.top = p;
		}
}

bool isEmpty(Stack s)
{
	if (s.top != NULL)
		return false;
	return true;
}

void popS(Stack& s, char& x)
{
	if (isEmpty(s))
		return;
	Node* p = s.top;
	x = s.top->info;
	s.top = s.top->next;
	delete p;
}

bool bieuThucCanBang(Stack& s, char bieuThuc[])
{
	for (int i = 0; i < strlen(bieuThuc); i++)
	{
		if (bieuThuc[i] == '(' || bieuThuc[i] == '{' || bieuThuc[i] == '[')
		{
			Node* p = createNode(bieuThuc[i]);
			pushS(s, p);
		}
		if (isEmpty(s))
			return false;
		char x;
		if (bieuThuc[i] == ')')
		{
			popS(s, x);
			if (x == '{' || x == '[')
				return false;
		}
		else
			if (bieuThuc[i] == '}')
			{
				popS(s, x);
				if (x == '(' || x == '[')
					return false;
			}
			else
				if (bieuThuc[i] == ']')
				{
					popS(s, x);
					if (x == '(' || x == '{')
						return false;
				}
	}
	return isEmpty(s);
}