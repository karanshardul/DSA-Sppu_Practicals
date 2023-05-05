// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        data = 0;
        next = NULL;
    }
};

class HashTable{
    int size;
    Node **table;
    public:
        HashTable(int s){
            this->size = s;
            table = new Node*[s];
            for(int i=0;i<=s;i++){
                table[i] = NULL;
            }
        }
        int Hash(int v){
            return v % size;
        }
        void insert(int key)
        {
            int index = Hash(key);
            Node *n = new Node;
            n->data= key;
            n->next= NULL;
            
            if(table[index] == NULL){
                table[index] = n;
                cout << "Succesfully Inserted: " << key <<endl;
            }
            else{
                Node *temp = table[index];
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next= n;
                cout << "Succesfully Inserted: " << key <<endl ;
            }
        }
        void search(int key){
            int index = Hash(key);
            Node *temp = table[index];
            while(temp != NULL){
                    if(temp->data == key){
                        cout << "element found" << endl;
                    break;}
                temp = temp->next;
            }
                if(temp == NULL){
                cout << "Element not found";
            }   }
        void delet(int key){
            int index = Hash(key);
            Node *temp = table[index];
            while(temp != NULL){
                Node *prev = temp;
                temp = temp->next;
                    if(prev->data == key){
                        table[index] = temp;
                        cout << "Element deleted: " << key << endl;
                    break;}
            else if(temp->data = key){
                prev->next = temp->next;
            
            }
            else{
                cout << "Element not found";
            }
            }
            
        }   
};
int main(){
    HashTable t(10);
    t.insert(90);
    t.delet(90);
    t.search(90);
}