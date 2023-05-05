#include <iostream>
using namespace std;

class Node{
	int data;
	Node *left, *right;

public:
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

	Node* getRoot(){
		return root;
	}

	void insert(int info){
		Node *curr = root;
		Node *parent = NULL;

		search(info, curr, parent);

		if(this->root == NULL){
			root = new Node(info);
			cout<<"Insertion successful "<<info<<endl;
		}
		else{
			if(curr == NULL){
				if(parent->data > info){
					parent->left = new Node(info);
					cout<<"Insertion successful "<<info<<endl;

				}else{
					parent->right = new Node(info);
					cout<<"Insertion successful "<<info<<endl;
				}
			}
		}
	}

	void deletefun(int info){
		Node *curr = root;
		Node *parent = NULL;
		Node *child = NULL;

		search(info, curr, parent);

		if(curr->left == NULL && curr->right == NULL){
			child = NULL;
		}else if(curr->left != NULL){
			child = curr->left;
		}else{
			child = curr->right;
		}

		if(parent != NULL){
			if(curr == (parent->left)){
				parent->left = child;
			}
			else{
				parent->right = child;
			}
		}else{
			root = child;
		}
	}

	void deletetwochild(int info){
		Node *curr = root;
		Node *parent = NULL;

		search(info, curr, parent);
		Node *ptr1 = curr;
		Node *ptr2 = curr->right;

		while(ptr2->left != NULL){
			ptr1 = ptr2;
			ptr2 = ptr2->left;
		}

		int temp = ptr2->data;
		ptr2->data = curr->data;
		curr->data = temp;

			if(ptr2 == ptr1->left){
				ptr1->left = NULL;
				cout<<ptr2->data<<" is deleted";
				delete ptr2;
			}else{
				ptr1->right = NULL;
				cout<<ptr2->data;
				delete ptr2;
			}
	}

	void search(int info, Node *&curr, Node *&parent){
		while(curr != NULL){
			if(curr->data == info){
				break;
			}
			else{
				parent = curr;

				if(curr->data < info){
					curr = curr->right;
				}else{
					curr = curr->left;
				}
			}
		}
	}

	void deleteBST(int info){
		Node *curr = root;
		Node *parent = NULL;

		search(info, curr, parent);

		if(curr == NULL){
			cout<<"Node doesn't exist";
		}
		else if(curr->left == NULL && curr->right == NULL){
			deletetwochild(info);
		}
		else{
			deletefun(info);
		}
	}

	void searchBST(int info){
		Node *curr = root;
		Node *parent = NULL;

		search(info, curr, parent);

		if(curr == NULL){
			cout<<"Node doesn't exist"<<endl;
		}else{
			cout<<"Node found"<<endl;
		}
	}

	void inorder(Node *t){
		if(t){
			inorder(t->left);
			cout<<t->data<<" ";
			inorder(t->right);
		}
	}

	void preorder(Node *t){
		if(t){
			cout<<t->data<<" ";
			inorder(t->left);
			inorder(t->right);
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

};

int main() {
	Tree t;
	t.insert(14);
	t.insert(4);
	t.insert(15);
	t.insert(3);
	t.insert(9);
	t.insert(18);
	t.insert(16);
	t.insert(8);
	t.insert(10);
	t.insert(19);
	t.insert(20);

//	t.deleteBST(15);
//	t.searchBST(100);
	Node *root = t.getRoot();
	t.inorder(root);
	cout<<endl;
	t.preorder(root);
	int count = t.height(root);
	cout<<endl<<"The height of tree is : "<<count;
	t.swap(root);
	t.inorder(root);
	return 0;
}

