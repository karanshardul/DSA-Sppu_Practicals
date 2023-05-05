#include <iostream>
using namespace std;

template <typename T> class Stack{
	T arr[30];
	int top;

public:
	Stack(){
		top = -1;
	}

	bool isEmpty(){
		if(top == -1){
			return true;
		}else{
			return false;
		}
	}

	bool isFull(){
		if(top == sizeof(arr)/sizeof(arr[0])){
			return true;
		}else{
			return false;
		}
	}

	void push(T data){
		if(this->isFull()){
			cout<<"Stack is full"<<endl;
		}else{
			top++;
			arr[top] = data;
		}
	}

	T pop(){
		if(this->isEmpty()){
			cout<<"Stack is empty"<<endl;
			return NULL;
		}else{
			T data = arr[top];
			top--;
			return data;
		}
	}
};

class Node{
	Node *left, *right;

public:
	int data;
	friend class Tree;
	Node(){
		this->left = NULL;
		this->right = NULL;
	}

	Node(int info){
		this->data = info;
		this->left = NULL;
		this->right = NULL;
	}
};

class Tree{
	Node *root;

public:

	Tree(){
		this->root = NULL;
	}

	Node * createTree(){
		int data;
		Node *p;
		cout<<"Enter data or -1 for no data "<<endl;
		cin>>data;
		
		if(data == -1){
			return NULL;
		}
		else{
			p = new Node(data);
			cout<<"Enter left child data of"<<p->data<<endl;
			p->left = createTree();
			cout<<"Enter right child data of"<<p->data<<endl;
			p->right = createTree();
		}
	}
	
	void *setRoot(Node *t){
		this->root = t;
		cout<<root->data;
	}
	
	void inorder(){
		Stack<Node *>s;
		Node * temp = root;
		
		while(!s.isEmpty() || temp != NULL){
			if(temp != NULL){
				s.push(temp);
				temp = temp->left;
			}
			else{
				temp = s.pop();
				cout<<temp->data;
				temp = temp->right;
			}
		}
	}
	
	Node* copyTree(Node *t){
		Node *n = NULL;
		Node *cp;
		if(t == NULL){
			return NULL;
		}
		else{
			cp = new Node(t->data);
			cp->left = copyTree(t->left);
			cp->right = copyTree(t->right);
			return cp;
		}
	}
	
	void swap(Node *t){
		Node *temp = NULL;
		if(t == NULL){
			cout<<"Tree is NULL "<<endl;
		}
		else{
			if(t->left!=NULL)
				swap(t->left);
			if(t->right!=NULL)
				swap(t->right);
			temp = t->left;
			t->left = t->right;
			t->right = temp;
		}
	}
	
	int height(Node *t){
		int l, r = 0;
		if(t == NULL){
			return -1;
		}
		else{
			l = height(t->right);
			r = height(t->left);
			return (1 + max(l , r));
		}
	}

};

int main() {
	Stack<int> obj1;
	
	Tree t1;
	Node *root = t1.createTree();
	t1.setRoot(root);
	t1.inorder();
	Node *cp = t1.copyTree(root);
	cout<<cp->data;

	return 0;
}
