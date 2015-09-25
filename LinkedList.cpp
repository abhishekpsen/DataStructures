#include <iostream>
#include <set>
#include <stack>

using namespace std;

class Node{
	
	public:
		int data;
		Node *next;
		Node(){
			data = 0;
			next = NULL;
		}
		Node(int data){
			this->data = data ;
			next = NULL;
		}
};	

int Length(Node *head){

	int length = 0;
	while(head!=NULL){
		length++;
		head = head->next;
	}
	return length;
}

void Push(Node* &head,int data){
	Node *newhead = new Node(data);
	newhead->next = head;
	head = newhead;
}

void Append(Node* &head,int data){
	Node *newnode = new Node(data);
	if(head == NULL){
		head = newnode;
		return;
	}
	Node *current;
	for(current = head;current->next!=NULL;current=current->next);
	current->next = newnode;
}

void Print(Node *head){
	for(Node *i = head;i!=NULL;i=i->next){
		cout<<i->data<<'\t';
	}
	cout<<endl;
}

void RemoveDup(Node *head){
	set<int> s;
	Node *current = head;
	s.insert(current->data);
	while(current->next!=NULL){
		if(s.find(current->next->data) != s.end()){
			current->next = current->next->next;
		}
		else{
			s.insert(current->next->data);
		}
		current = current->next;
	}
}

void RemoveDupInSortedList(Node *head){
	Node *current = head;
	Node *i;
	while(current->next != NULL){
		i = current;
		while(i->data == current->data){
			i = i->next;
		}
		current->next = i;
		current = current->next;
	}
}

void RemoveDupInSortedListBetter(Node *head){
	Node *current = head;
	Node *temp;
	while(current->next != NULL){
		if(current->next->data == current->data){
			temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		else{
			current = current->next;	
		}
		
	}
}

void RemoveDup1(Node *head){
	Node *current1,*current2;
	current1 = head;
	current2 = head;
	while(current1 != NULL){
		current2 = current1;					//This is easy to overlook, always start current2 from current1
		while(current2->next != NULL){
			if(current2->next->data == current1->data){
				current2->next = current2->next->next;
			}
			else{
				current2 = current2->next;
			}
		}
		current1 = current1->next;
	}
}

int kthtolast(Node *head, int k){
	Node *current1 = head;
	Node *current2 = head;

	/* Give current1 a headstart of k positions,
	Then advance current1 and current2 until current1 reaches the last node*/
	for(int i=1;i<k;i++){
		if(current1->next !=NULL)
			current1 = current1->next;
		else{
			cout<<"List length insufficient"<<endl;
			return -9999;
		}
	}
	while(current1->next!=NULL){
		current2 = current2->next;
		current1 = current1->next;
	}
	return current2->data;

}
void RemoveNode(Node *node){
	if(node->next == NULL){
		cout<<"Cannot remove last node"<<endl;
		return;
	}
	Node *temp = node->next;
	node->data = node->next->data;
	node->next = node->next->next;
	delete temp;
}

bool Palindrome(Node *head){
	Node *fast = head;
	Node *slow = head;
	stack<int> s;
	while(fast != NULL && fast->next != NULL){
		s.push(slow->data);
		fast = fast->next->next;
		slow = slow->next;
	}
	//If the list is even length, dont advance slow, its already where its supposed to be
	//If the list is odd length, advance slow by 1, to get rid of the single element at the middle
	if(fast != NULL){	//Odd length
		slow = slow->next;	
	}
	
	while(slow != NULL){
		if(slow->data != s.top()){
			//Not a palindrome
			return false;
		}
		slow = slow->next;
		s.pop();
	}
	if(!s.empty()){
		cout<<"Stack is not empty"<<endl;
		return false;
	}
	return true;
}

Node* SumLists(Node *head1,Node *head2){
	stack<int> s;
	Node *current1 = head1;
	Node *current2 = head2;
	Node *sumhead = NULL;
	int sum,carry;
	carry = 0;
	while(current1 != NULL && current2 != NULL){
		sum = current1->data + current2->data + carry;
		carry = sum/10;
		sum %= 10;
		Push(sumhead,sum);
		current1 = current1->next;
		current2 = current2->next;
	}
	while(current1 != NULL){
		sum = current1->data + carry;
		carry = sum/10;
		sum %= 10;
		Push(sumhead,sum);
		current1 = current1->next;
	}

	while(current2 != NULL){
		sum = current2->data + carry;
		carry = sum/10;
		sum %= 10;
		Push(sumhead,sum);
		current2 = current2->next;
	}

	if(carry!=0){
		Push(sumhead,carry);	
	}
	return sumhead;
}

void InsertAtMid(Node *head,int data){
	Node *slow = head;
	Node *fast = head;
	while(fast->next != NULL && fast->next->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	Node *newnode = new Node(data);
	newnode->next = slow->next;
	slow->next = newnode;
}

Node* Intersection(Node *list1,Node *list2){
	Node *current1 = list1;
	Node *current2 = list2;

	set<Node*> s;
	while(current1 != NULL){
		s.insert(current1);
		current1 = current1->next;
	}
	while(current2 != NULL){
		if(s.find(current2) != s.end()){
			break;
		}
	}
	return current2;
	//NULL if no intersection
}

Node* DetectLoop(Node *head){
	Node *slow = head;
	Node *fast = head;

	while(slow != NULL && fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow){
			//Init slow to head and move slow and fast one place each
			slow = head;
			while(slow != fast){
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return NULL;
}


int main(){

	/*Node *head = NULL;
	Append(head,1);
	//Node *head = new Node();
	//head->data = 1;
	Append(head,2);
	Append(head,3);
	Append(head,4);
	//Append(head,5);
	Append(head,4);
	Append(head,3);
	Append(head,2);
	Append(head,1);

	cout<<endl<<"Length is "<<Length(head)<<endl;
	//Push(head,4);
	//Append(head,4);
	//Append(head,5);
	//Append(head,6);
	//cout<<"After appending "<<endl;
	Print(head);

	//RemoveNode(head->next->next->next);
	//cout<<"After removing duplicates"<<endl;
	//Print(head);
	//cout<<endl<<kthtolast(head,5)<<endl;
	if(Palindrome(head)){
		cout<<"Palindrome!"<<endl;
	}
	else{
		cout<<"Not a Palindrome!"<<endl;
	}

	//Test InsertAtMid
	InsertAtMid(head,-1);
	cout<<"Trying to insert -1 at mid"<<endl;
	Print(head);

	Node *list1 = NULL;
	Node *list2 = NULL;
	Append(list1,9);
	Append(list1,7);
	Append(list1,8);
	Append(list2,6);
	Append(list2,8);
	Append(list2,5);
	//Append(list2,9);
	//Append(list2,1);
	cout<<"List 1 "<<endl;
	Print(list1);
	cout<<"List 2 "<<endl;
	Print(list2);
	Print(SumLists(list1,list2));*/

	Node *sortedlist = NULL;
	Append(sortedlist,1);
	Append(sortedlist,1);
	Append(sortedlist,1);
	Append(sortedlist,2);
	Append(sortedlist,2);
	Append(sortedlist,3);
	Append(sortedlist,4);
	Append(sortedlist,4);
	Append(sortedlist,5);

	cout<<"Before removing dups"<<endl;
	Print(sortedlist);

	//RemoveDupInSortedListBetter(sortedlist);
	//cout<<"After removing dups"<<endl;

	Print(sortedlist);

	Node *head = new Node(1);
	Node *second = new Node(2);
	Node *third = new Node(3);
	Node *fourth = new Node(4);
	Node *fifth = new Node(5);
	Node *sixth = new Node(6);
	head->next = second;
	second->next  =third;
	third->next = fourth;
	fourth->next = fifth;
	fifth->next = sixth;
	sixth->next = second;
	
	if(DetectLoop(head) != NULL){
		cout<<"Loop found at "<<DetectLoop(head)->data<<endl;
	}
	else{
		cout<<"No loop"<<endl;
	}

	return 0;
}