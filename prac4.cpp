#include <iostream>
#include <string>
using namespace std;

class HashTable{
    string name;
    int no;
    public:
        void create_table();
        void show_table();
        int hash(string m);
        void insert_ht1();
        void insert_ht2();
}HT1[10],HT2[10];

void HashTable::create_table(){
    for(int i=0;i<10;i++){
        HT1[i].name="Blank";
        HT1[i].no=0;
        HT2[i].name="Blank";                              
        HT2[i].no=0;   
    }
}
void HashTable::show_table(){
    for(int i=0;i<10;i++){
        cout << HT1[i].name << "->" << HT1[i].no << "        " << HT2[i].name << "->" << HT2[i].no << endl;
    }
}

int HashTable::hash(string m){
        int k;
        int score;
        for(int i=0;i<10;i++){
            k=m[i];
            score=score+k;
        }
        return score%10;
}

void HashTable::insert_ht1(){
    int k;
    cout<< "How many enteries you want to make: ";
    cin>>k;
    for(int i=0;i<k;i++){
        string nam;int num;
        int hash;
        cout <<"Enter Name for entry no." <<i+1<<": ";
        cin>>nam;
        cout <<endl;
        cout <<"Enter Number for entry no." <<i+1<<": ";
        cin>>num;
        hash = HT1[i].hash(nam);
        HT1[hash].name=nam;
        HT1[hash].no=num;
    }
}

void HashTable::insert_ht2(){
    int k;
    cout<< "How many enteries you want to make: ";
    cin>>k;
    for(int i=0;i<k;i++){
        string nam;int num;
        int hash;
        cout <<"Enter Name for entry no." <<i+1<<": ";
        cin>>nam;
        cout <<endl;
        cout <<"Enter Number for entry no." <<i+1<<": ";
        cin>>num;
        hash = HT2[i].hash(nam);
        if(HT2[hash].name != "Blank"){
            for(int q=hash+1;q<10;q++){
                if(q==10){
                    q=0;
                }
                if(HT2[q].name == "Blank"){
                        HT2[q].name=nam;
                        HT2[q].no=num;
                        break;
                }
            }
        }
        HT2[hash].name=nam;
        HT2[hash].no=num;
    }
}

int main(){
    HashTable h;
    h.create_table();
    //h.insert_ht1();
    h.insert_ht2();
    h.show_table();
    int m= h.hash("Karan");
    // cout << m;

}