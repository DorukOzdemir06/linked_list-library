#include <iostream>
#include <string>
#include "linked_list.h"
using namespace std;


void node:: print(node* head) {
		cout << head->data << " -> ";
		if (head->next != NULL) print(head->next);
		else cout << "NULL";
}

int node::reach(node* head, unsigned int index) {
		for (unsigned int i = 0; i < index; i++)	head = head->next;
		return head->data;
}

node* node::reach_adress(node* head, unsigned int index) {

		for (unsigned int i = 0; i < index; i++)	head = head->next;
		return head;
}

unsigned int node::len(node* head) {
		unsigned int i = 0;
		while (true) {
			i++;
			if (head->next == NULL) break;
			head =  head->next;
		}
		return i;
}
void node::append(node* head, int data) {
		node* last = new node;
		
		count('+');
		last->data = data;
		reach_adress(head, len(head) - 1)->next = last;
		
}

void node::appfront(node** head, int data) {
	node* first = new node;
	
	count('+');
	first->data = data;
	first->next = *head;
	*head = first;

}

void node::addindex(node* head, int data, int index) {
	if (index == 0) head->data = data;
	else {
		node* new_node = new node;
		count('+');
		new_node->data = data;
		new_node->next = reach_adress(head, index);
		reach_adress(head, index - 1)->next = new_node;
	}

}

void node::deleteindex(node** head, int index) {
	if (index == 0) *head = reach_adress(*head, 1);

	else reach_adress(*head, index-1)->next = reach_adress(*head, index)->next;

}

node::~node() {
	cout << "desc called\n";
}


int node::count(char c) {
	static int count = 0;
	
	if (c == '+') count++;
	else if (c == 'g') return count;
}

void node::swap(node* head, unsigned int index1, unsigned int index2) {
	int temp = NULL;
	
	temp = reach(head, index1);
	reach_adress(head, index1)->data = reach(head, index2);	
	reach_adress(head, index2)->data = temp;
}