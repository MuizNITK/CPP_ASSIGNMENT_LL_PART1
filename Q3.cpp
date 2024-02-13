#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;

    Node(int val){     // Constructor
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{       // user defined Data Structure
public:
    Node* head = NULL;      // head and tail nodes are initialized 
    Node* tail = NULL;      // same
    int size=0;             // size initialized 
    LinkedList(){       // constructor
        head = tail = NULL;       // initializing the value of head and tail
        size = 0;
    }
    // important
    void insertAtEnd(int val){                
        Node* temp = new Node(val);
        if(size == 0){  
            head = tail = temp;   // pointer to pointer assigning
            size++;
        } 
        else{
            tail->next = temp;   // assigning the new pointer to the next of the tail
            tail=temp;
            size++;
        }
    }

    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0){
            head = tail = temp;
            size++;
        }
        else{
            temp->next = head;
            head = temp;
            size++;
        }
    }

    void insert(int idx, int val){      // inserting at a particular index
        if(idx<0 || idx>=size){
            cout<<"Invalid index ";
            return;
        }
        if(idx == 0) {
            insertAtHead(val);
            return;
        }
        else if(idx == size-1){
            insertAtEnd(val);
            return;
        } 
        else{
            Node* temp = head;
            Node* t = new Node(val); 
            int i=0;
            while(i<=idx-1){
                temp = temp->next;
                i++;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
            return;
        }

    }

    int getAt(int idx){
        if(idx<0 || idx>=size) return -1;
        else if(idx == 0) return head->val;
        else if(idx == size - 1) return tail->val;
        else{
            Node* temp = head;
            for (int i=0; i<idx; i++){
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void deleteAtHead(){
        if(size == 0) {
            cout<<"List is already empty ";
            return;
        }
        else if(size >1 ){
            head = head->next;
            size--;
            return;
        }
        if(size == 1){
            head = head->next;
            tail = NULL;
            size--;
            return;
        }
    }

    void deleteAtTail(){
        if(size == 0){
            cout<<"List is empty ";
            return;
        }
        else if(size == 1){
            tail->next = NULL;
            head->next = NULL;
            return;
        }
        else if(size>1){
            Node* temp = head;
            for(int i=0 ; i<size-2 ; i++){
                temp = temp->next;
            }
            temp->next = 0;
            tail = temp;
            size--;
            return;
        }
    }

    void deleteAtIndex(int idx){
        if(idx == 0) deleteAtHead();
        else if(idx == size-1) deleteAtTail();
        else if(idx>0 && idx<size-1){
            Node* temp = head;
            for(int i=0;i<idx-1 ; i++){
                temp=temp->next;

            }
            temp->next = temp->next->next;
            size--;

        }
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<" "<<size;
        cout<<endl;
    }


};


int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.display();    
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtHead(5);
    ll.display();
    ll.insert(2,52);
    ll.display();
    ll.insert(0,2);
    ll.display();
    ll.insert(5,40);
    ll.display();
    cout<<ll.getAt(3)<<endl;
    ll.deleteAtHead();

    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIndex(3);
    ll.display();
    cout<<endl<<ll.size;
}