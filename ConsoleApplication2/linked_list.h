#pragma once



class node {
protected:
	static int count(char c);
	
public:
	int data =NULL;
	node* next=NULL;
	
	static void print(node* head);
	static int reach(node* head, unsigned int index);
	static node* reach_adress(node* head, unsigned int index);
	static unsigned int len(node* head);
	static void append(node* head, int data);
	static void appfront(node** head, int data);
	static void addindex(node* head, int data,int index);
	static void deleteindex(node** head, int index);
	static void swap(node* head, unsigned int index, unsigned int index2);

	~node();
};



