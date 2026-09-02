#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
        
    }
};

class CircularList{
    Node* head;
    Node* tail;

public:
    CircularList(){
        head = tail = NULL;
    }

    int InsertAtHead(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            tail -> next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
    }

    int InsertAtTail(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
            tail -> next = head;
        } else {
            newNode -> next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead(){
    if(head == NULL){
        return;                 
    }
    if(head == tail){
        delete head;
        head = tail = NULL;     
        return;
    }
    Node* temp = head;          
    head = head->next;          
    tail->next = head;          
    temp->next = NULL;        
    delete temp;
    }

    void deleteAtTail(){
        if(head == NULL){
            return;
        }
        else if(head == tail){
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            Node* prev = head;
            while(prev->next != tail){
                prev = prev ->next;
            }
            tail = prev;
            tail->next = head;
            temp -> next = NULL;
            delete temp;
        }
    }

    void print(){
        if(head == NULL) return;

        cout << head->data << "-> ";
        Node* temp = head -> next;

        while(temp != head){
            cout << temp->data << "-> ";
            temp = temp -> next;
        }
        cout << head->data << endl;
    }
};

int main(){
    CircularList cll;

    cll.InsertAtHead(1);
    cll.InsertAtHead(2);
    cll.InsertAtHead(3);

    cll.print();

    cll.deleteAtTail();

    cll.print();

    return 0;
}