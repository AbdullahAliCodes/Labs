

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

void pushBack(int value){
    if (head == nullptr){
        Link*tmp = new Link(value);
        head = tmp;
        tail = tmp;
    }
    else{
        Link*tmp = new Link(value);
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}

void pushFront(int value){
   if (head == nullptr){
    Link*tmp = new Link(value);
    head = tmp;
    tail = tmp;
   }
   else{
    Link*tmp = new Link(value);
    tmp->next = head;
    head->prev = tmp;
    head = tmp;
   }
}

void popFront(){
    if (head == nullptr){
        return;
    }
    else{
        link*tmp = head->next;
        delete head;
        tmp -> prev = nullptr;
        head = tmp;
    }
}

void popBack(){
   if (head == nullptr){
    return;
   }
   else{
    Link*tmp = tail->prev;
    delete tail;
    tmp->next = tmp;
    tail = tmp;
   }
}

void reverse(){
    if (head == nullptr){
        return;
    }
    else{
        DoublyLinkedList tempList;
        Node*tmp = tail;
        while (temp != nullptr){
            tempList.pushback(temp->value);
            tmp = tmp->prev;
        }
        while (head!=nullptr){
            Node*tmp2 = head;
            head = temp->next;
            delete temp;
        }
        head = 
    }
}

void InsertAtIndex (int value, int index){
    Link*tmp = new Link(value);
    int id = 0;
    Link*curr = head;
    while(id!=index){
        curr = curr->next;
        id++
    }
    curr->prev->next = tmp;
    tmp->prev = curr->prev;
    curr->prev = tmp;
    tmp->next = curr;
}