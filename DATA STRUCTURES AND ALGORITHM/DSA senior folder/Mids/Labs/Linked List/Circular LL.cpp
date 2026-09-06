#include<iostream>
using namespace std;
struct node
{
int value;
node*next;
};
node*tail=NULL;
void createCircularLL()
{
node*newNode=new node;
cout<<"Enter the value for new node: ";
cin>>newNode->value;
newNode->next=NULL;
if(tail==NULL)
{
tail=newNode;
tail->next=tail;
}
else
{
newNode->next=tail->next;
tail->next=newNode;
tail=newNode;
}
}
int length()
{
int size = 0;
node*temp = tail->next;
do
{
size++;
temp=temp->next;
}while(temp!=tail->next);
return size;
}
void print()
{
node*temp = tail->next;
do
{
cout<<temp->value<<" ";
temp=temp->next;
}while(temp!=tail->next);
cout<<endl;
}
void insertAtHead()
{
node* newNode=new node;
cout<<"Enter the value for new Head node: ";
cin>>newNode->value;
newNode->next=NULL;
if(tail==NULL)
{
tail=newNode;
tail->next=newNode;
}
else
{
newNode->next=tail->next;
tail->next=newNode;
}
}
void insertAtTail()
{
node* newNode=new node;
cout<<"Enter the value for new Tail node: ";
cin>>newNode->value;
newNode->next=NULL;
if(tail==NULL)
{
tail=newNode;
tail->next=newNode;
}
else
{
newNode->next=tail->next;
tail->next=newNode;
tail=newNode;
}
}
void insertAtPosition()
{
int pos;
int l = length();
int i = 1 ;
node*temp=tail->next;
cout<<"Enter the position you wanna insert: ";
cin>>pos;
if(pos< 1||pos>l)
{
cout<<"invalid Positon"<<endl;
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
node* newNode=new node;
cout<<"Enter the value for new node: ";
cin>>newNode->value;
newNode->next=NULL;
newNode->next=temp->next;
temp->next=newNode;
}
int main()
{
createCircularLL();
print();
createCircularLL();
print();
createCircularLL();
print();
insertAtHead();
print();
insertAtTail();
print();
insertAtPosition();
print();
cout<<"Length of LL is "<<length()<<endl;
return 0;
}
