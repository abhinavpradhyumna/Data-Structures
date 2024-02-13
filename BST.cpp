#include<iostream>
using namespace std;
struct node{
	int data ;
	node *left,*right;
};
node *root = NULL;
node* largest_tree(node *s){
	node *temp=s;
	while(temp->right!=NULL)
	temp=temp->right;
	return temp;
}
void inorder(node *x){
	if(x==NULL)
	return;
	inorder(x->left);
	cout<<x->data<<"\t";
	inorder(x->right);
}
void insertTree(int a){
	node *newnode=new node;
	newnode->data=a;
	newnode->left=newnode->right=NULL;
	if(root==NULL)
	root=newnode;
	else{
		node *t=root;
		node *p=NULL;
		while(t!=NULL){
		if(a>root->data){
			p=t;
			t=t->right;
		}
		else{
			p=t;
			t=t->left;
		}	
		}
		if(p->data>a)
	p->left=newnode;
	else
	p->right=newnode;
	}
	
}
void DisplayGreaterSal(int x){
	node *temp=root;
	if(x>temp->data)
	temp=temp->right;
	else
	temp=temp->left;
	while(temp!=NULL and temp->data <x)
	temp=temp->right;
inorder(temp);
}
void deleteBst(int dataOut){
	if(root==NULL){
		cout<<"Empty Tree"<<endl;
		return;	}
	node * t=root;
	node *p=NULL;
	while(t!=NULL and t->data != dataOut){
		if(dataOut>t->data){
		p=t;
		t=t->right;}
		else{
		p=t;
		t=t->left;}
	}
	if(t==NULL){
		cout<<"element not available in TREE"<<endl;
		return;
	}
	else{
		if(t->left==NULL){
			if(p->data>t->data)
				p->left=t->right;
			else
				p->right=t->right;
		}
		else if(t->right==NULL){
			if(p->data>t->data)
				p->left=t->left;
			else
				p->right=t->left;
		}
		else{
			node *t = root;
			node *p=NULL;
			while(t->data!=dataOut){
				if(dataOut>t->data)
					t=t->right;
				else
					t=t->left;	
			}
			p=t;
			node *ll = largest_tree(t);
			p->data=ll->data;
		}
		delete t;
		}
	}
int main(){
	insertTree(10);
	insertTree(13);insertTree(14);insertTree(2);insertTree(15);insertTree(9);insertTree(7);insertTree(20);insertTree(45);insertTree(23);insertTree(25);insertTree(78);insertTree(17);
	 //deleteBst(20);
	 inorder(root);
}
