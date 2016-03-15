// Hoa P Nguyen
//Inventory control


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


class node{ char data; node * next; 
public:
	void setnext(node*g){ next = g; }
	node *getnext(){ return next; }
	char getdata(){ return data; }
	void setdata(char n){ data = n; }
	
	

	node(){
	next = nullptr;
	}

	~node(){
	}
};


class linkedList{
	node * head;
	int counter = 0;
	public:

		node * gethead(){
			return head;
		}
		void sethead(node* a){ head = a; }
		// SHOW DATA
		void showInfo(){
			
			node *current = head;
			cout << "data: " << head->getdata() << endl;
			if (head->getnext()!= nullptr){
				head = head->getnext();
				showInfo();
			}
			head = current;
		}
		
		
		
		// ADD CHARACTER TO LINK LIST

	void appendNode(char n){
		node * newnode;
		newnode = new node;
		newnode->setdata(n);
		newnode->setnext(nullptr);

		if (!head)
		{
			head = newnode;
		}
		else{
			node * current = head;
			while (current ->getnext()){
				current = current->getnext();
			}

			current->setnext(newnode);

		}

	}
	///			SORT ///////////
	node* sort(node * head){
		node* current = head;
		node* check = head;
		char temp;
		if (!head){
			return nullptr;
		}
		while (check!=nullptr){

			while (current!=nullptr){
				if (check->getdata() < current->getdata())
				{
					temp = current->getdata();
					current->setdata(check->getdata());
					check->setdata(temp);
						

				}
				current = current->getnext();
			}
		
			check = check->getnext();
			current = head;
		}
		return head;
	}
	// MERGELINKLIST
	node * mergeLinkedLists(node* A, node * B){
		node * headA = A;
		node * headB = B;
		node * headC = new node;
		headC->setnext(NULL);
		if (!A){
			return B;
		}
		while (headA->getnext() != nullptr)
		{

			headA = headA->getnext();
		}
		headA->setnext(headB);
		node * re = A;

		return re;
	};

	// Merge LinkedList NoAssumption
	node * mergeLinkedListNoAssumption(node* A, node * B){
		node * C;
		C = mergeLinkedLists(A, B);
		sort(C);

		return C;

	}
	// COUNT NODES
	
	void count(node *n){
		node *current = head;
		if (!n){
			cout << "There is no node." << endl;
		}
		counter++;
		
		if (head->getnext() == nullptr){
			cout << "Number of Nodes: " << counter << endl;
			head = current;
			return;
		}
		head = head->getnext();
		count(n);
		

	}
	linkedList(){
		head = nullptr;
	}

};


int main()
{
	// task 1/
	linkedList * A = new linkedList();
	A->appendNode('a');
	A->appendNode('d');
	A->appendNode('f');
	cout << "Added" << endl;
	A->showInfo();
	
	linkedList * B = new linkedList();
	B->appendNode('h');
	B->appendNode('m');
	B->appendNode('q');
	cout << "Added" << endl;
	B->showInfo();

	cout << "MERGELINKLISTS: " << endl;
	linkedList * C = new linkedList();
	
	C->sethead(C->mergeLinkedLists(A->gethead(), B->gethead()));
	C->showInfo();
	// TASK 2
	cout << "MERGE no assumetion: " << endl;
	cout << "Before MERGE SORT" << endl;
	linkedList * E = new linkedList();
	E->appendNode('f');
	E->appendNode('b');
	E->appendNode('d');
	cout << "Added" << endl;
	E->showInfo();

	linkedList * F = new linkedList();
	F->appendNode('a');
	F->appendNode('t');
	F->appendNode('d');
	cout << "Added" << endl;
	F->showInfo();
	linkedList * D = new linkedList();
	D->sethead(D->mergeLinkedListNoAssumption(E->gethead(), F->gethead()));
	cout << "AFTER: " << endl;
	D->showInfo();

	cout << "SORT " << endl;
	//TASK 3: This code shows the use of “sort()”
	linkedList * list = new linkedList();
	list->appendNode('g');
	list->appendNode('c');
	list->appendNode('b');
	list->appendNode('a');
	cout << "Before " << endl;
	list->showInfo();
	list->sort(list->gethead());
	cout << "After " << endl;
	list->showInfo();
	//Task 5 count
	cout << "List: " << endl; C->showInfo();
	C->count(C->gethead());

	return 0;
}


