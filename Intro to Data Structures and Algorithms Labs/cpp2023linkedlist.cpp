#include "linkedlist.h"

/**
 * @brief LinkedListIterator::operator*
 * @return Return a reference to the thing in the link that we're pointing to
 */
Thing &LinkedListIterator::operator*()
{
    return ptr -> value;

}

/**
 * @brief LinkedListIterator::operator++
 * Make the current iterator point to the next link in the list.
 * @return Return a reference to this object.
 */
LinkedListIterator &LinkedListIterator::operator++()
{
    ptr = ptr -> next;
    return *this;
}


/**
 * @brief LinkedList::LinkedList
 * Already correct as head is set to nullptr in the header file.
 */
LinkedList::LinkedList()
{
    // This is already correct.
}

/**
 * @brief LinkedList::~LinkedList
 * Free every link in the list. Do this function last.
 */
LinkedList::~LinkedList()
{
    // Consider using functions that already exist.
    Link*tmp = head;
    while(tmp!= nullptr){
        Link*prev = tmp;
        tmp = tmp ->next;
        delete prev;
    }
    head = nullptr;
}

/**
 * @brief LinkedList::push_front
 * @param t
 * Push t to the front of the list
 */
void LinkedList::push_front(Thing t)
{
    Link*tmp = new Link(t);
    tmp -> next = head;
    head = tmp;
}

/**
 * @brief LinkedList::pop_front
 * Remove the front item in the list
 */
void LinkedList::pop_front()
{
    Link*tmp = head;
    head = head -> next;
    delete tmp;

}

/**
 * @brief LinkedList::push_back
 * @param t
 * Add t to the back of the list
 */
void LinkedList::push_back(Thing t)
{
    Link*curr = new Link(t);
    if(head == nullptr){
        head = curr;
        curr ->next=nullptr;
    }
    else{
        Link*tmp = head;
        while(tmp->next != nullptr){
            tmp = tmp -> next;
        }
        tmp -> next = curr;
        curr -> next = nullptr;
    }


}

/**
 * @brief LinkedList::pop_back
 * Remove the last link in the list
 */
void LinkedList::pop_back()
{
   Link*tmp = head;
   if(tmp ->next == nullptr){
       delete tmp;
       head = nullptr;
   }
   else{
       while(tmp->next->next!=nullptr){
       tmp=tmp->next;
   }
   delete tmp -> next;
   tmp -> next = nullptr;
    }
}

/**
 * @brief LinkedList::size
 * @return number of items in the list
 */
size_t LinkedList::size()
{
    Link*tmp = head;
    int count = 0;
    while(tmp != nullptr){
        tmp = tmp -> next;
        ++count;
    }
    return count;
}

/**
 * @brief LinkedList::front
 * @return a reference to the first item in the list
 */
Thing &LinkedList::front()
{
    Link*tmp = head;
    return tmp->value;

}

/**
 * @brief LinkedList::back
 * @return a reference to the last item in the list
 */
Thing &LinkedList::back()
{
    Link*tmp = head;
    while(tmp -> next != nullptr){
        tmp = tmp -> next;
    }
    return tmp -> value;
}

/**
 * @brief LinkedList::get_link
 * @param i
 * @return A pointer to the ith link
 * @throws std::out_of_range("i out of bounds") - try do this without calling size()
 */
Link *LinkedList::get_link(int i)
{
    Link*tmp = head;
    int count = 0;

    while(tmp != nullptr){ // SIZE
        tmp = tmp -> next;
        ++count;
    }

    if(i < 0){
        throw std::out_of_range("i out of bounds");
    }
    else{
        if(i == count){
           throw std::out_of_range("i out of bounds");
        }
        else{
            if(i > count){
                throw std::out_of_range("i out of bounds");
            }
        }
        Link*tmp2 = head;
        for( int c = 0; c < i ; ++c){ // get link
            tmp2 = tmp2 -> next;

        }
        return tmp2;
    }

}

/**
 * @brief LinkedList::at
 * @param i
 * @return A reference to the thing at index i
 * @throws std::out_of_range("i out of bounds") - try do this without calling size()
 */
Thing &LinkedList::at(int i)
{
    Link*tmp = get_link(i);
    if(i < 0 ){
        std::out_of_range("i out of bounds");
    }
    else{
        return tmp ->value;
    }

}

/**
 * @brief LinkedList::begin
 * @return a LinkedListIterator object referencing the first item
 */
LinkedListIterator LinkedList::begin()
{
    // Remember to implemente both LinkedListIterator::operator* and
    //   LinkedListIterator::operator++ in order to pass the test cases.
    // They are at the top of this file.
    LinkedListIterator Head;
    Head.ptr = head;
    return LinkedListIterator(Head);
}

/**
 * @brief LinkedList::end
 * @return a LinkedListIterator representing one past the last item
 * Let this be a LinkedLIstIterator with ptr equal to the nullptr
 */
LinkedListIterator LinkedList::end()
{
    LinkedListIterator End;
    End.ptr = nullptr;
    return LinkedListIterator(End);
}

/**
 * @brief LinkedList::copy
 * @return A pointer to a copy of the list
 * Allocate a new list on the heap, then add all the items to the list.
 * Do not allocate the list on the stack, because it would be destroyed when the function ends.
 *  - See the C++ Concepts PDF example.
 */
LinkedList *LinkedList::copy()
{
    LinkedList*newList = new LinkedList();
    Link*tmp = head;
    if(head == nullptr){
        newList -> head = nullptr;
        return newList;
    }
    while(tmp != nullptr){
        newList -> push_back(tmp->value);
        tmp = tmp ->next;
    }
    return newList;

}

/**
 * @brief LinkedList::reverse
 * Reverse the list.
 *  half marks: all the values are reversed
 *  remaining marks: list is reversed by changing link pointers *only*
 *    - if it was expensive to copy Thing objects, then reversing the values would take
 *       a lot of time. If you can do it by only changing the link pointers, then it will
 *       always be fast no matter how big the thing objects are.
 *  You can do this in O(n^2) time quite easily. Try think about how you could do this in O(n) time.
 */
void LinkedList::reverse()
{
    Link*curr = head;
    Link*prev = nullptr;
    Link*next = nullptr;
    while(curr != nullptr){
        next = curr ->next;
        curr ->next =prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

