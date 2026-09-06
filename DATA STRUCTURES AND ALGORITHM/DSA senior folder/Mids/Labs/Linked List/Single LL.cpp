#include <iostream>
#include <cstdlib>


using namespace std;
void createLL();
void display();
int Length();
void insertAtHead();
void insertAtTail();
void insertAfterPosition();
void insertBeforePosition();
void delHead();
void delTail();
void delAfterPosition();
void delByValue();
void sortLL();
void sortLLL();
void tailtohead();
void headtotail();
void swapnode();
void reserve();
void deleteDuplicates();

struct node
{
	int value;
	node* next;
};
int main(int argc, char** argv) {
	int x , y ;

	do
	{
		cout << "1: Create Link List " << endl;
		cout << "2: Insert New Head " << endl;
		cout << "3: Insert New Tail " << endl;
		cout << "4: Insert After Position " << endl;
		cout << "5: Insert Before Position " << endl;
		cout << "6: Delete Head Node " << endl;
		cout << "7: Delete Tail Node " << endl;
		cout << "8: Delete At position " << endl;
		cout << "9: Delete by Value " << endl;
		cout << "10: Sorting LL in Ascending order" << endl;
		cout << "11: Sorting LL in Descending order" << endl;
		cout << "12: Convert Tail into head " << endl;
		cout << "13: Convert head into tail " << endl;
		cout << "14: Swap 2 nodes " << endl;
		cout << "15: Reverse a Link List " << endl;
		cout << "16: Get length of Link List " << endl;
		cout << "17: Display Link List " << endl;
		cout << "18: Delete Duplicates " << endl;
		
		cout << "\n------------------------Press any option Given Above------------------------: " ;
		cin >> x ;
		switch(x)
	{
		case 1:
		{
		createLL();
		break;
		}
	
		case 2:
		{
		insertAtHead();
		break;
		}

		case 3:
		{
		insertAtTail();
		break;
		}

		case 4:

		{
		insertAfterPosition();
		break;
		}

		case 5: 

		{
		insertBeforePosition();
		break;
		}

		case 6:
		{
		delHead();
		break;
		}

		case 7:
		{
		delTail();
		break;
		}

		case 8:
		{
		delAfterPosition();
		break;
		}

		case 9:
		{
		delByValue();
		break;
		}

		case 10: 
		{
		sortLL();
		break;
		}

		case 11:
		{
		sortLLL();
		break;
		}

		case 12:
		{
		tailtohead();
		break;
		}

		case 13:
		{
		headtotail();
		break;
		}

		case 14:
		{
		swapnode();
		break;
		}

		case 15: 
		{
		reserve();
		break;
		}

		case 16:
		{
		cout<<"Length of current LL : "<< Length() << endl;
		break;
		}

		case 17:
		{
		cout<<"Link List: ";
		display();
		break;
		}
		case 18:
		{
		cout<<"Link List: ";
		deleteDuplicates();
		display();
		break;
		}
		

		default:
		{
		cout << "Invalid choice " << endl;
		}
	}

	cout << "\nPress 0 for exit and any other key for Main Menu : ";
	cin >> y ;

//system ("cls");
	}while(y!=0);
	return 0;
}

	node* head = NULL;
	void createLL()
	{
	int x ;
	do
	{
		node* newnode = (struct node*) malloc (sizeof ( struct node ));
		cout << "Enter the newNode value: ";
		cin >> newnode->value;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = newnode;
		}
		else
		{
			node* temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			} 
			temp->next = newnode;
		}
		cout << "Press 0 for exit and any other key for make a another newNode : ";
		cin >> x ;
	}while(x != 0); 
	}

	void display()
	{
		node* temp = head ;
		if(head==NULL)
	{
		cout<<"List is empty "<<endl;
		return;
	}
	while (temp != NULL )
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
	}

	int Length()
	{
		node* temp = head ;
		int size = 0; 
		while (temp != NULL )
		{
			size++;
			temp = temp->next;
		}
		cout << endl;
		return size;
	}


	void insertAtHead()
	{
		node* newnode = new node;
		cout << "Enter the new head Node value: ";
		cin >> newnode->value;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}


	void insertAtTail() 
	{
		node* newnode = (struct node*) malloc (sizeof ( struct node ));
		cout << "Enter the new tail Node value: ";
		cin >> newnode->value;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = newnode;
			return;
		}
		node* temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}

	void insertAfterPosition()
	{
		int pos;
		int i = 1;
		int l = Length();
		node* temp = head;
		cout<<"Enter the position you wanna insert (After): ";
		cin>>pos; 
		if(pos<1 || pos>l)
		{
			cout<<"Invalid Position "<<endl;
			return;
		}
		while(i < pos)
		{
			temp = temp->next;
			i++;
		}	
		if(temp->next == NULL)
		{
			insertAtTail();
			return;
		}
		node* newnode = (struct node*) malloc (sizeof ( struct node ));
		cout << "Enter the new Node value: ";
		cin >> newnode->value;
		newnode->next=temp->next;
		temp->next = newnode; 
	}

	void insertBeforePosition()
	{
		int pos;
		int i = 1;
		int l = Length();
		node* temp = head;
		cout<<"Enter the position you wanna insert (Before): ";
		cin>>pos;
		if(pos<1 || pos>l)
		{
			cout<<"Invalid Position "<<endl;
			return;
		}
		if(pos == 1)
		{
			insertAtHead();
			return;
		}
		while(i < pos - 1)
		{
			temp = temp->next;
			i++;
		}
		node* newnode = (struct node*) malloc (sizeof ( struct node ));
		cout << "Enter the new Node value: ";
		cin >> newnode->value;
		newnode->next=temp->next;
		temp->next = newnode;  
	}

	void delHead()
	{
		node* temp = head;
		head = head->next;
		delete temp;
	}

	void delTail()
	{
		node* temp = head;
		node* prev ;
		while(temp->next!=NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next=NULL;
		delete temp;
	}

	void delAfterPosition()
	{
		int i = 1;
		node* temp = head;
		int pos;
		cout << "Enter position of node you wanna delete: "; 
		cin >> pos;
		int l = Length();
		if(pos < 1 || pos > l)
		{
			cout << "Invalid Position " << endl;
			return;
		}
		if(pos == 1)
		{
			delHead();
			return;
		}
		
		while(i < pos - 1 )
		{
			temp = temp->next;
			i++;
		}
		
		if(temp->next == NULL)
		{
			delTail();
			return;
		}
		node*nextnode = temp->next;
		temp->next=nextnode->next;
		delete nextnode;
	}

	void delByValue()
	{
		int x;
		cout << "Enter value you wanna Delete: ";
		cin >> x;
		node* temp = head;
		node* prev = temp;
		while(temp != NULL)
		{
			if(temp->value == x)
			{
				if(head==temp)
				{
					delHead();
					return;
				}
				else
				{
					prev->next = temp->next;
					delete temp;
					return;
				}
			} 
			else
			{
				prev=temp;
				temp=temp->next;
			}
		}

		cout<<"Value not Found "<<endl;
	}

	void sortLL()
	{
		node* temp = head ;
		node* nextnode ;
		int swap;
		while(temp!=NULL)
		{
			nextnode=temp->next;
			while(nextnode != NULL)
			{
				if(temp->value > nextnode->value)
				{
					swap=temp->value;
					temp->value=nextnode->value;
					nextnode->value=swap;
				}
				nextnode=nextnode->next; 
			}
			temp=temp->next;
		}
	}

	void sortLLL()
	{
		node* temp = head ;
		node* nextnode ;
		int swap;
		while(temp!=NULL)
		{
			nextnode=temp->next;
			while(nextnode != NULL)
			{
				if(temp->value < nextnode->value)
				{
					swap=temp->value;
					temp->value=nextnode->value;
					nextnode->value=swap;
				}
				nextnode=nextnode->next;
			}
		temp=temp->next;
		}
	}

	void tailtohead()
	{
		node* temp = head;
		node* prev = NULL;
		while(temp->next!=NULL)
		{
			prev = temp;
			temp=temp->next;
		}
		temp->next=head;
		head=temp;
		prev->next=NULL;
	}

	void headtotail()
	{
		node*temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=head;
		head=head->next;
		temp->next->next=NULL;
	}

	void swapnode() 
	{
		int x ;
		int y ;
		cout<<"Enter the value of first node: ";
		cin>>x;
		cout<<"Enter the value of second node: ";
		cin>>y;
		if(x==y)
		{
			return;
		}
		node* currentx = head;
		node* prevx = NULL;
		while(currentx->next !=NULL && currentx->value != x)
		{
			prevx=currentx;
			currentx = currentx->next;
		}
		node* currenty = head;
		node* prevy = NULL;
		while(currenty->next!=NULL && currenty->value!=y)
		{
			prevy=currenty;
			currenty=currenty->next;
		} 
		if(currentx==NULL || currenty==NULL)
		{
			cout<<"Value not found "<<endl;
			return;
		}
		if(prevx==NULL)
		{
			head=currenty;
		}
		else
		{
			prevx->next=currenty;
		}
		if(prevy==NULL)
		{
			head=currentx;
		}
		else
		{
			prevy->next=currentx;
		}
		node *temp = currenty->next;
		currenty->next=currentx->next;
		currentx->next=temp;
	}

	void reserve()
	{
		node* prev = NULL;
		node* current = head;
		node* nextnode = head;
		while(nextnode!=NULL)
		{
			nextnode=nextnode->next;
			current->next=prev;
			prev=current;
			current=nextnode;
		}
		head=prev;
	}
	
	void deleteDuplicates()
	
	{
		node* temp=head;
		node* prev=head;
		while(temp!=NULL)
		{
			node * checkedNode= temp->next;
			while(checkedNode!=NULL)
			{
			if(temp->value==checkedNode->value)
				{
				node* duplicateNode = checkedNode;
				prev->next= checkedNode->next;
				checkedNode= checkedNode->next;
				delete duplicateNode;
				}
			else 
				{
				prev= checkedNode;
				checkedNode =checkedNode->next;	
				}	
			}
			temp=temp->next;
		}

		}	


