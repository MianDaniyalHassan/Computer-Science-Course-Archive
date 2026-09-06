#include<iostream>
#include<cstdlib>

using namespace std;
struct node
{
	int value;
	node*next;
};

node* top = NULL;

void push()
{
	node*newNode= new node();
	cout<<"Enter the Value you wanna push in stack: ";
	cin>>newNode->value;
	newNode->next=top;
	top=newNode;
}

void pop()
{
	node* temp= top;
	if(top==NULL)
	{
		cout<<"Stack is Empty"<<endl;
	} 
	else
	{
		cout<<"Deleted value is "<<temp->value<<endl;
		top=top->next;
		delete temp;
	}
}

void Top()
{
	if(top==NULL)
	{
		cout<<"Stack is Empty"<<endl;
		return;
	}
	cout<<"Top: "<<top->value<<endl;
}

void display()
{

node* temp = top;

if(top==NULL)
{
	cout<<"Stack is empty"<<endl;
	return;
}

while(temp!=NULL) 
{
	cout<<temp->value<<" ";
	temp = temp->next;
}

cout<<endl;
}

int main() {
int choice;
do 
{
	cout<<"\n1: Push(): "<<endl;
	cout<<"2: Pop(): "<<endl;
	cout<<"3: Top(): "<<endl;
	cout<<"4: Display(): "<<endl;
	cout<<"0: Exit(): "<<endl;
	cin>>choice;

	switch(choice)
	{
		case 1:
		{
			push();
			break;
		}
		case 2: 
		{
			pop();
			break;
		}
		case 3:
		{
			Top();
			break;
		}
		case 4:
		{
			display();
			break;
		}
	}
}while(choice!=0);

return 0;
}
