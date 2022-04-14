#include <iostream>
#include <string>
#include "linked_list.h"
using namespace std;



void bubbleSort(node* list)
{
	int i, j,n=node::len(list);
	for (i = 0; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
			if (node::reach(list,j) > node::reach(list, j+1))
				node::swap(list,j, j + 1);
}

int giveOdd() {
	
	int n;
	while (true) {
		n = rand();
		if (n % 2 != 0) return n;




	}

}


void main()
{
	srand(time(NULL));
	node* head = new node;
	head->data = 3;

	node::append(head, 7);
	node::append(head, 11);
	node::append(head, 9);
	node::append(head, 1);
	node::append(head, 2);
	node::append(head, 3);
	node::append(head, 7);
	node::append(head, 45);
	node::append(head, 46);
	
	cout << "All list: ";
	node::print(head);
	
	node* odd = new node;
	odd->data = node::reach(head, 0);

	for (unsigned int i = 1; i < node::len(head); i++) if (node::reach(head, i) % 2 != 0) node::append(odd, node::reach(head, i));
	
	cout << endl << "\nOdd: ";
	node::print(odd);

	
	node::append(odd, giveOdd());
	cout << endl<<"Odd(append): ";
	node::print(odd);

	node::appfront(&odd, giveOdd());
	cout << endl << "Odd(appfront): ";
	node::print(odd);

	cout << "\n\nAll list(sorted): ";
	bubbleSort(head);
	node::print(head);

	cout << "\nAll list(swaped 0 & 1 index): ";
	node::swap(head,0,1);
	node::print(head);

	system("pause>0");
}