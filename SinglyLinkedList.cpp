#include<iostream>
using namespace std;
struct node{
	int data;
	node *link;
};
struct header{
	int count;
	node *head;
}*slink;

void create(){
	slink = new header();
	slink->count=0;
	slink->head=NULL;
}

void insert_at_top(int datain)
{
	node * newnode = new node;
	newnode->data=datain;
	newnode->link=slink->head;
	slink->head=newnode;
}
void insert_end(int datain)
{
	node *temp = slink->head;
	node *newnode=new node();
	newnode->data=datain;
	newnode->link=NULL;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=newnode;
	
}

void print()
{
	node*temp = slink->head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->link;
	}
}

void search(int element)
{
	
}
int main()
{
	create();
	insert_at_top(10);
	insert_end(20);
	insert_at_top(30);
	print();
}
