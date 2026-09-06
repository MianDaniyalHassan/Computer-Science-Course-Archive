#include<iostream>
using namespace std;
struct node
{
char value;
node*next;
node*pre;
};
node* head ;
node* tail ;
void createDLL()
{
	node*newNode ;
	newNode = new node;
	cout<<"Enter Value You Wanna insert in node: ";
	cin>>newNode->value;
	newNode->next=NULL;
	newNode->pre=NULL;
	if(head==NULL)
	{
	head= newNode;
	tail= newNode;
	}
	else
	{
	newNode->next=NULL;
	newNode->pre=tail;
	tail->next=newNode;
	tail=newNode;
	}
}
void insertAtHead()
{
	node* newNode = new node;
	cout<<"Enter Value You Wanna insert in new head node: ";
	cin>>newNode->value;
	newNode->next=NULL;
	newNode->pre=NULL;
	newNode->next = head;
	head->pre=newNode;
	head=newNode;
}
void insertAtEnd()
{
	node* newNode = new node;
	cout<<"Enter Value You Wanna insert in new end node: ";
	cin>>newNode->value;
	newNode->next=NULL;
	newNode->pre=NULL;
	newNode->pre=tail;
	tail->next=newNode;
	tail=newNode;
}
void insertAfterPosition()
{
	int pos;
	int i = 1;
	node*temp;
	temp= head;
	cout<<"Enter position you wanna insert new Node: ";
	cin>>pos;
	node* newNode = new node;
	cout<<"Enter Value You Wanna insert in new end node: ";
	cin>>newNode->value;
	if(pos<1)
	{
	cout<<"Invalid position";
	return;
	}
	while(i<pos)
	{
	temp=temp->next;
	i++;
	}
	newNode->pre=temp;
	newNode->next=temp->next;
	temp->next=newNode;
	newNode->next->pre=newNode;
}
void insertAtPosition()
{
	int pos;
	int i = 1;
	node*temp;
	temp= head;
	cout<<"Enter position you wanna insert new Node: ";
	cin>>pos;
	if(pos<1)
	{
	cout<<"Invalid position";
	return;
	}
	if(pos==1)
	{
	insertAtHead();
	return;
	}
	while(i<pos-1)
	{
	temp=temp->next;
	i++;
	}
	if(temp->next==NULL)
	{
	insertAtEnd();
	return;
	}
	node* newNode = new node;
	cout<<"Enter Value You Wanna insert in new end node: ";
	cin>>newNode->value;
	newNode->pre=temp;
	newNode->next=temp->next;
	temp->next=newNode;
	newNode->next->pre=newNode;
}
void printForward(node* head)
{
	node* treverse ;
	treverse = head;
	while(treverse!=NULL)
	{
	cout<<treverse->value<<" ";
	treverse=treverse->next;
	}
	cout<<endl;
}
void printReverse(node* tail)
{
	node* treverse ;
	treverse = tail;
	while(treverse!=NULL)
	{
	cout<<treverse->value<<" ";
	treverse=treverse->pre;
	}
	cout<<endl;
}
void delHead()
{
	node*temp;
	temp=head;
	head=head->next;
	head->pre=NULL;
	delete temp;
}
void delTail()
{
	node* temp;
	temp = tail;
	tail=tail->pre;
	tail->next=NULL;
	delete temp;
}
void delAtPosition()
{  
	int pos ;
	int i = 1 ;
	cout<<"Enter Position of node you wanna Delete: ";
	cin>>pos;
	node*temp ;
	temp = head ;
	if(pos<1)
	{
	cout<<"Invalid Position ";
	return;
	}
	if(pos==1)
	{
	delHead();
	}
	while(i<pos)
	{
	temp=temp->next;
	i++;
	}
	if(temp->next==NULL)
	{
	delTail();
	return;
	}
	temp->pre->next=temp->next;
	temp->next->pre=temp->pre;
	delete temp;
}
int lengthLL()
{
	int size = 0;
	node* treverse ;
	treverse = head;
	while(treverse!=NULL)
	{
	size++;
	treverse=treverse->next;
	}
	return size;
}
int main()
{
	createDLL();
	createDLL();
	createDLL();
	createDLL();
	createDLL();
	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	printForward(head);
	insertAtHead();
	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	printForward(head);
	insertAfterPosition();
	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	printForward(head);
	delAtPosition();
	cout<<"\nLength of Doubly LL is: "<<lengthLL()<<endl;
	printForward(head);
	cout<<"\nReverse of Doubly LL is: "<<lengthLL()<<endl;
	printReverse(tail);
}
