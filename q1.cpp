#include<iostream>
using namespace std;

class Node{
	public:
	//Data
	int data;
	//Pointer to next and previous Node
	Node* next;
	Node* prev;
	//Constructor that makes ptr to NULL
	Node(){
		next = NULL;
		prev = NULL;
	}
	
};

class DLL{
	public:
	//Head + Nodes inside linked with each other
	
	//Head -> Node type pointer
	Node* head;
	Node* tail;
	
	//Construct
	DLL(){
		head = NULL;
		tail = NULL;
	}
	//Nodes inside linked with each other
	//Rules how circles will be connected or linked
	
	//insert
	void insert(int value){
		//If 1st node is added
		Node* temp = new Node;
		// Insert value in the node
		temp->data = value;
		// 1st Node only
		if(head==NULL){
			head = temp;
		}
		
		// Any other Node
		else{
			tail->next = temp;
			temp->prev = tail;
		}
		tail = temp;
		
	}
	
	void insertAt(int pos, int value){
		// Reach the place before the pos
		Node* current = head;
		int i =1;
		while(i<pos-1){
			i++;
			current = current->next;
			if(current==NULL){
				cout << "This position has not yet been created." << endl;
				cout << "Insert function might help you in this case." << endl;
				return;
			}
		}
		
		//Create a node
		Node* temp = new Node;

		//Storing the data
		temp-> data = value;

		if(pos!=1){
		//moving pointers like magic!
		temp->next = current->next;	
		current->next = temp;
		temp->next->prev = temp;
		temp->prev = current;
		}
		// Update the code for 1st pos.
		else{temp->next = head;
		head->prev = temp;
		head = temp;}
	}

	//Delete at any position
	void deleteAt(int pos){
	
		// Reach the place before the pos
		Node* current = head;
		int i =1;
		while(i<pos-1){
			i++;
			current = current->next;
			
		}

		// Reach the place at the pos
		Node* temp = head;
		int j =1;
		while(j<pos){
			j++;
			temp = temp->next;
			if(temp==NULL){
				cout << "This position has not yet been created." << endl;
				cout << "Delete function might help you in this case." << endl;
				return;
			}
		}
		//Moving pointers like magic!
		current->next = temp->next;
		current->next->prev = current;
		delete temp;

	}

	//Deletion of last element
	void del(){
		//store tail in temp
		Node* temp = tail;
		//Node before tail has to point to NULL
		Node* current = tail->prev;
		
		current->next = NULL;

		//update tail
		tail = current;

		//delete temp
		delete temp;
	}

	//Count the number of items in the list
	void countItems(){
		// Writing a loop to count
		int count = 0;
		Node* curr=head; 
		while(curr != NULL){
			count++;
			curr = curr->next;
			}
		cout << "Number of items in list = " << count << endl;
	}
	
	//Display
	void display(){
		Node* current = head;
		cout << "NULL" << "<->";
		while(current != NULL){
			cout << current->data << "<->";
			current = current->next;
		}
		cout << "NULL" << endl;
	}

	//Reverse Display (Recursion)
	//Creating a function to use head if it was private!
	void Revdisp(){
		cout << "NULL";
		Revdisp2(tail);
		cout << "<->" << "NULL" << endl;
	}

	//Creating the actual function
	void Revdisp2(Node* current){
		//Start from last and go back
		while(current != NULL){
			cout << "<->" << current->data;
			current = current->prev;
		}
	}

	//Making the reverse of linked list
	void revDLL(){
		revDLL2(head);
		//Updating head with a loop
		while(head->prev!=NULL)
		head = head->prev;
		//Updating tail with a loop
		while(tail->next!=NULL)
		tail = tail->next;
				
	}
	
	void revDLL2(Node* current){
		//Termination condition
		if(current==NULL){return;}
		//Recursion
		revDLL2(current->next);
		Node* temp = current->next;
		current->next = current->prev;
		current->prev = temp;
	}

};

int main(){
	DLL l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	l1.insert(8);
	l1.insert(9);
	l1.display();
	l1.Revdisp();
	l1.revDLL();
	l1.display();
	l1.deleteAt(2);
	l1.display();
	l1.countItems();
	l1.insertAt(5,11);
	l1.display();
	l1.del();
	l1.display();
	
return 0;
}
