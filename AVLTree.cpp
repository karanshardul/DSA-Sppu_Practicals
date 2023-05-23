#include<iostream>

using namespace std;

class Node{
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    friend class AVL;
}*r;


class AVL{
    // private:
    //     Node* root;

    public:
        AVL(){
            r = NULL;
        }

        bool is_leaf(Node* node){
            return (node->left == NULL && node->right == NULL);
        }

        int find_height(Node* node){

            //if(node == NULL || is_leaf(node)) return 0;
            if(node != NULL){
            int left_height = find_height(node->left);
            int right_height = find_height(node->right);

            return max(left_height, right_height) + 1;
            }
        }

        int difference(Node* node){

            int left_height = find_height(node->left);
            int right_height = find_height(node->right);    

            return left_height - right_height;
        }

        Node* rr_rotate(Node* node){

            Node* temp_root = node->right;

            node->right = temp_root->left;
            temp_root->left = node;

            return temp_root;
        }


        Node* ll_rotate(Node* node){

            Node* temp_root = node->left;

            node->left = temp_root->right;
            temp_root->right = node;

            return temp_root;
        }
        
        
        Node* lr_rotate(Node* node){

            Node* temp_root = node->left->right;
            Node* temp_root_left = temp_root->left;
            Node* temp_root_right = temp_root->right;

            temp_root->left = node->left;
            temp_root->right = node;

            temp_root->left->right = temp_root_left;
            temp_root->right->left = temp_root_right;

            return temp_root;
        }

        Node* rl_rotate(Node* node){

            Node* temp_root = node->right->left;
            Node* temp_root_left = temp_root->left;
            Node* temp_root_right = temp_root->right;

            temp_root->left = node;
            temp_root->right = node->right;

            temp_root->left->right = temp_root_left;
            temp_root->right->left = temp_root_right; // YET to be edited

            return temp_root;
        }   

    Node *balance(Node *t){
        int bal_fac = difference(t);
        if(bal_fac > 1){
            if(difference(t->left) > 0){
                t = ll_rotate(t);
            }
            else
                t = lr_rotate(t);
        }
        else if(bal_fac < -1){
            if(difference(t->right) > 0)    
                t = rl_rotate(t);
            else 
                t = rr_rotate(t);
        }
        return t;
    }

    Node *insert(Node *root, int data){
        if(root == NULL){
            root = new Node(data);
            return root;
        }
        else if(root->data > data){
            root->left = insert(root->left, data);
            root = balance(root);
        }
        else if(root->data <= data){
            root->right = insert(root->right, data);
            root = balance(root);
        }
        return root;
    }

    // void show(Node *parent, int l){
    //     if(parent!=NULL){
    //         show(parent->right,1+1);
    //         cout << " ";
    //         if( parent == r){
    //             cout << "Root -> ";
    //             for(int i=0; i < l && parent != r; i++){
    //                 cout << " ";
    //                 cout << parent->data;
    //                 show(parent->left,l+1);
    //             }
    //         }
    //     }
    // }

    void inorder(Node *t){
        if(t == NULL){
            return;
        }
            inorder(t->left);
            cout << t->data << " ";
            inorder(t->right); 
    }

    void preorder(Node *t){
        if(t == NULL){
            return;
        }
            cout << t->data << " ";
            preorder(t->left);
            preorder(t->right); 
    }
    void postorder(Node *t){
        if(t == NULL){
            return;
        }
            postorder(t->left);
            postorder(t->right); 
            cout << t->data << " ";
    }
};

int main() {
   int c, i;
   AVL avl;
   //Node *r = NULL;
   while (1) {
      cout << "1.Insert Element into the tree" << endl;
      cout << "3.InOrder traversal" << endl;
      cout << "4.PreOrder traversal" << endl;
      cout << "5.PostOrder traversal" << endl;
      cout << "6.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c) {
         case 1:
            cout << "Enter value to be inserted: ";
            cin >> i;
            r = avl.insert(r, i);
         break;
        //  case 2:
        //     if (r == NULL) {
        //        cout << "Tree is Empty" << endl;
        //        continue;
        //     }
        //     cout << "Balanced AVL Tree:" << endl;
        //     avl.show(r, 0);
        //     cout<<endl;
        //  break;
         case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(r);
            cout << endl;
         break;
         case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(r);
            cout << endl;
         break;
         case 5:
            cout << "Postorder Traversal:" << endl;
            avl.postorder(r);
            cout << endl;
         break;
         case 6:
            exit(1);
         break;
         default:
            cout << "Wrong Choice" << endl;
      }
   }
   return 0;
}
