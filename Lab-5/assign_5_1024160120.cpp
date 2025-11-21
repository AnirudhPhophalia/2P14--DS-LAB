// Lab Assignment 5 (Singly Linked List)
// 1. 1. Develop a menu driven program for the following operations on a Singly Linked List. 
// (a) Insertion at the beginning.
// (b) Insertion at the end. 
// (c) Insertion in between 
// (d) Deletion from the beginning. 
// (e) Deletion from the end. 
// (f) Deletion of a specific node. 
// (g) Search for a node and display its position from head. 
// (h) Display all the node values.
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class SLL{
public:
    Node* head;

    SLL(){
        head = NULL;
    }

    void insertBeg(int x){
        Node* t = new Node(x);
        t->next = head;
        head = t;
    }

    void insertEnd(int x){
        Node* t = new Node(x);
        if(!head){
            head = t;
            return;
        }
        Node* p = head;
        while(p->next) p = p->next;
        p->next = t;
    }

    void insertBefore(int v, int x){
        if(!head) return;

        if(head->data == v){
            insertBeg(x);
            return;
        }

        Node* p = head;
        while(p->next && p->next->data != v)
            p = p->next;

        if(p->next){
            Node* t = new Node(x);
            t->next = p->next;
            p->next = t;
        }
    }

    void insertAfter(int v, int x){
        Node* p = head;
        while(p && p->data != v)
            p = p->next;

        if(p){
            Node* t = new Node(x);
            t->next = p->next;
            p->next = t;
        }
    }

    void deleteBeg(){
        if(!head) return;
        Node* t = head;
        head = head->next;
        delete t;
    }

    void deleteEnd(){
        if(!head) return;

        if(!head->next){
            delete head;
            head = NULL;
            return;
        }

        Node* p = head;
        while(p->next->next)
            p = p->next;

        delete p->next;
        p->next = NULL;
    }

    void deleteValue(int v){
        if(!head) return;

        if(head->data == v){
            deleteBeg();
            return;
        }

        Node* p = head;
        while(p->next && p->next->data != v)
            p = p->next;

        if(p->next){
            Node* t = p->next;
            p->next = t->next;
            delete t;
        }
    }

    int search(int v){
        Node* p = head;
        int pos = 1;
        while(p){
            if(p->data == v) return pos;
            p = p->next;
            pos++;
        }
        return -1;
    }

    void display(){
        Node* p = head;
        while(p){
            cout << p->data << " ";
            p = p->next;
        }
        cout << "\n";
    }
};

int main(){
    SLL obj;
    int ch, x, v;

    do{
        cout<<"\n1 Insert Beg\n2 Insert End\n3 Insert Before\n4 Insert After\n"
              "5 Delete Beg\n6 Delete End\n7 Delete Value\n8 Search\n9 Display\n0 Exit\n";
        cin>>ch;

        switch(ch){
            case 1: cin>>x; obj.insertBeg(x); break;
            case 2: cin>>x; obj.insertEnd(x); break;
            case 3: cin>>v>>x; obj.insertBefore(v,x); break;
            case 4: cin>>v>>x; obj.insertAfter(v,x); break;
            case 5: obj.deleteBeg(); break;
            case 6: obj.deleteEnd(); break;
            case 7: cin>>v; obj.deleteValue(v); break;
            case 8: cin>>v; cout<<obj.search(v)<<endl; break;
            case 9: obj.display(); break;
        }

    }while(ch != 0);
}
// 2. Write a program to count the number of occurrences of a given key in a singly linked list and then delete all the occurrences.
int deleteAllKey(Node* &h, int k){
    int c = 0;

    while(h && h->data == k){
        Node* t = h;
        h = h->next;
        delete t;
        c++;
    }

    Node* p = h;

    while(p && p->next){
        if(p->next->data == k){
            Node* t = p->next;
            p->next = t->next;
            delete t;
            c++;
        }else{
            p = p->next;
        }
    }

    return c;
}
// 3. Write a program to find the middle of a linked list
int findMiddle(Node* h){
    Node* s = h;
    Node* f = h;

    while(f && f->next){
        s = s->next;
        f = f->next->next;
    }

    return s->data;
}
// 4. Write a program to reverse a linked list
Node* reverse(Node* h){
    Node *p = NULL, *c = h, *n;

    while(c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

