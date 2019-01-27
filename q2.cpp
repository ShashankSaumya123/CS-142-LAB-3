#include<iostream>
using namespace std;

class Node{
	public:
	//Data
	int data;
	//Pointer to next Node
	Node* next;
	//Constructor that makes ptr to NULL
	Node(){
		next = NULL;
	}	
};

//The class of circular linked list
class CLL{
	public:
	//Making head and tail
	Node* head;
	//Time for constructor
	CLL(){
		head = NULL;
	}
	
	//Insert
	void insert(int value){
		//Create a node
		Node* temp = new Node;

		//Storing the data
		temp-> data = value;
		//First Node
		if(head==NULL){
			head = temp;
		}
		//Only one node
		else{	if(head->next==NULL){
				head->next = temp;
			}
			//Any other node
			else{Node* current = head;
				while(current->next != head){
					current=current->next;
				}
				current->next = temp;
			}
		}
				temp->next = head;
		
	}

	//Insert at given position
	void insertAt(int pos,int value){
		// Reach the place before the pos
		Node* current = head;
		int i =1;
		while(i<pos-1){
			i++;
			current = current->next;
			if(current==head){
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
		}
		// Update the code for 1st pos.
		else{temp->next = head;
			Node* curr = head;
			while(curr->next != head){
				curr=curr->next;
			}
			curr->next = temp;
			head = temp;

		}

	}

	//Delete at any position
	void deleteAt(int pos){
	
		// Reach the place before the pos
		Node* current = head;
		int i =1;
		while(i<pos-1){
			i++;
			current = current->next;
			if(current==head){
				cout << "This position has not yet been created." << endl;
				cout << "Delete function might help you in this case." << endl;
				return;
			}
			
		}

		// Reach the place at the pos
		Node* temp = head;
		int j =1;
		while(j<pos){
			j++;
			temp = temp->next;
			
		}
		//Moving pointers like magic!
		current->next = temp->next;
		delete temp;

	}

	//Delete last element
	void del(){
		//if only 1 element
		if(head->next==head){
			Node* temp = head;
			head = NULL;
			delete temp;
		}

		else{
			//Reach just before last element
			Node* curr = head;
			while(curr->next->next != head){
				curr=curr->next;
			}
			//Mark the last element as temp
			Node* temp = curr->next;
			curr->next = head;
			delete temp;
		}
	}

	//Count the number of items in the list
	int countItems(){
		// Writing a loop to count
		int count = 1;
		Node* curr=head->next; 
		while(curr != head){
			count++;
			curr = curr->next;
		}
	return count;
	}

	//Display
	void display(){
		Node* current = head;
		cout << "*";
		int i=0;
		while(i<countItems()){
			i++;
			cout << current->data << "->";
			current = current->next;
		}
		cout << "\b\b" << "* " << endl;
	}

	//Reverse Display (Recursion)
	void Revdisp(){
		cout << "*";
		revdisp2(head);
		cout << "\b\b" << "* " << endl;
	}

	void revdisp2(Node* curr){
		if(curr->next == head){
			cout << curr->data << "->";
			return;}
		revdisp2(curr->next);
		cout << curr->data << "->";
	}
		
	//Reverse the linked list
	void Revcll(){
		Node* temp = head->next;
		revc2(head);
		temp->next = head;
		head = head->next;
	}
	
	void revc2(Node* curr){
		if(curr->next == head){
			curr->next->next = curr;
			return;}
		revc2(curr->next);
		if(curr == head){return;}
		curr->next->next = curr;

	}

};

int main(){
	CLL l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(5);
	l1.insert(6);
	l1.insert(7);
	l1.insert(8);
	l1.insert(9);
	l1.insert(10);
	l1.display();
	l1.deleteAt(2);
	l1.display();
	l1.insertAt(2,2);
	l1.display();
	l1.del();
	l1.display();
	cout << "Number of items in list = " << l1.countItems() << endl;
	l1.Revdisp();
	l1.Revcll();
	l1.display();
return 0;
}
