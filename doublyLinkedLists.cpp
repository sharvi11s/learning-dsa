#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyList{
public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = NULL;
    }

    int push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    int push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        Node* temp = head;
        head = head -> next;

        if(head != NULL){
            head -> prev = NULL;
            temp -> next = NULL;
        }
        delete temp;
    }

    void pop_back(){
        Node* temp = tail;
        tail = tail -> prev;

        if(tail != NULL){
            tail -> next = NULL;
            temp -> prev = NULL;
        }
        delete temp;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "<=>";
            temp = temp -> next;
        }
        cout << "Null \n";
    }
};


int main(){
    DoublyList dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);

    dll.print();

    dll.pop_back();

    dll.print();

    return 0;
}