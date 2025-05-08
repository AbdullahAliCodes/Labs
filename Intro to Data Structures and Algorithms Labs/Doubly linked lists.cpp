#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

Link::Link(int v){
     value = v;
}

void PushBack(int value){
    if (head== nullptr){
        link * NewLink = new link(value);
        head = NewLink;
        tail = NewLink;
    }
    else{
        link * NewLink = new link(value);
        tail-> next = NewLink;
        NewLink -> prev = tail;
        tail = NewLink;  
    }
}

void PushFront (int value){
    if (head == nullptr){
        link * NewLink = new link(value);
        head = NewLink;
        tail = Newlink;
     }
     else {
        link * NewLink = new link(value);
        NewLink -> prev = head;
        head -> prev = NewLink;
        head = NewLink;
     }
}

void PopBack(){
    if ( head == nullptr){
        return;
    }

    else{
        link * buffer = tail -> prev;
        delete tail;
        buffer -> next = nullptr;
        tail = buffer;
    }
}

void PopFront(){
    if ( head == nullptr){
        return;
    }
    else{
        link * buffer = head -> next;
        delete head;
        buffer -> prev = nullptr;
        head = buffer;

    }
}

void RemoveAtIndex(int index){

    int id=0;
    link * curr = head;

    while ( id != index){
        curr = curr -> next;
        id ++;
    }

    curr -> prev -> next = curr -> next;
    curr -> next -> prev = curr -> prev;
    delete curr;
}


void InsertAtIndex(int value, int index){
    link * NewLink = new link(value);
    int id =0;
    link * curr = head;

    while (id != index ){
        curr = curr -> next;
        id ++;
         }

         curr -> prev -> next = NewLink;
         NewLink -> prev = curr -> prev;
         curr -> prev = NewLink;
         NewLink -> next = curr;

}