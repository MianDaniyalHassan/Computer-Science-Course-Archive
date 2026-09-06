#include <iostream>
#define n 5

using namespace std; 
int stack[n];
int top = -1;
void push();
void pop();
void Top();
void display();

int main() 
{
	int x;
	do
	{
		cout<<"\n1: Push(): "<<endl;
		cout<<"2: Pop(): "<<endl;
		cout<<"3: Top(): "<<endl;
		cout<<"4: Display(): "<<endl;
		cout<<"0: Exit(): "<<endl;
		cin>>x;
		switch(x)
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
	}while(x!=0);
	return 0;
}

void push()
{
	int value;
	cout<<"Enter the value you wanna Push (Insert): ";
	cin>>value; 
	if(top==n-1)
	{
		cout<<"Stack is FULL / Stack is overFlow "<<endl;
	}
	else
	{
		top++;
		stack[top]=value;
	}
}

void pop()
{
	int value;
	if(top==-1)
	{
		cout<<"Stack is Empty"<<endl;
	}
	else
	{
		value=stack[top];
		top--;
		cout<<"POP OUT value from stack is "<<value<<endl;
	}
}

void Top() 
{
	if(top==-1)
	{
		cout<<"Stack is empty there is no top "<<endl;
	}
	else
	{
		cout<<"TOP value in Stack is: "<<stack[top]<<endl;
	}
}

void display()
{
	if(top==-1)
	{
		cout<<"Stack is empty there is no top "<<endl;
	}
	else
	{
		for(int i = top ; i >=0 ; i--)
		{
			cout<<stack[i]<<" ";
		}
	}
}

