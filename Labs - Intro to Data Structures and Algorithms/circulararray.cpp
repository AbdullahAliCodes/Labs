#include "circulararray.h"

using std::cout;
using std::endl;

CircularArray::CircularArray() : data(nullptr), n_items(0), n_allocated(0), idx_front(0)
{

}

/**
 * @brief CircularArray::print
 * Print the objects stored in the array separated by commas, starting at the "front" of the circular array. The content should be enclosed by square brackets.
 * The format should be: [1,2,3,4]
 * You can use cout as usual inside this function: "cout << myThing;"
 */
void CircularArray::print(std::ostream &cout) const
{
    cout << "[";
    for(int i = 0; i < n_items; i++){
        if(i != 0) cout << ",";
        cout << data[(idx_front + i) % n_allocated];
    }
    cout << "]";
}


/**
 * @brief CircularArray::size
 * @return The number of items actually stored in the array.
 */
int CircularArray::size() const
{
    return n_items;
}

/**
 * @brief CircularArray::allocated
 * @return The amount of space allocated - i.e. the number of Things that we could store in the current memory buffer.
 */
int CircularArray::allocated() const
{
    return n_allocated;
}

/**
 * @brief CircularArray::reallocate
 * @param new_size
 *
 * Allocate a new memory buffer that can store new_size number of Thing objects.
 * Remember that Thing at the "front" of the circular array should be copied to data[0] in the new memory.
 * Remember to free the old memory buffer and update all relevant variables in the class.
 */
void CircularArray::reallocate(int new_size)
{
    Thing* tmp = new Thing[new_size];
    for(int i = 0; i < n_items; i++){
        tmp[i] = data[(idx_front+i) % n_allocated];
    }

    delete [] data;
    data = tmp;
    idx_front = 0;
    n_allocated = new_size;
}

/**
 * @brief CircularArray::push_front
 * @param t
 *
 * Push Thing t to the front of the circular array.
 * If the array is full, then fist reallocate with twice the size.
 * If there is no memory allocated, then reallocate(1)
 */
void CircularArray::push_front(const Thing &t)
{
    if(n_allocated == 0){
        reallocate(1);
    }else if(n_items == n_allocated){
        reallocate(2*n_allocated);
    }

    idx_front--;
    if(idx_front < 0) {
        idx_front = n_allocated -1;
    }
    data[idx_front] = t;
    n_items++;
}

/**
 * @brief CircularArray::push_front
 * @param t
 *
 * Push Thing t to the back of the circular array.
 * If the array is full, then fist reallocate with twice the size.
 * If the array is empty (n_items == 0), then place the item at data[0].
 * If there is no memory allocated, then reallocate(1)
 */
void CircularArray::push_back(const Thing &t)
{
    if(n_allocated == 0){
        reallocate(1);
    }else if(n_items == n_allocated){
        reallocate(2*n_allocated);
    }

    data[(idx_front + n_items) % n_allocated] = t;
    n_items++;
}

/**
 * @brief CircularArray::pop_front
 * Pop the object from the "front" of the circular array.
 * You don't need to delete the actual Thing object, but to mark it as deleted, you should set its value to -1
 *  i.e. data[something].value = -1
 * If the number of items in the array is < n_allocated/4.0 then reallocate with half the allocated space
 */
void CircularArray::pop_front()
{
    data[idx_front].value = -1;
    idx_front = (idx_front + 1) % n_allocated;
    n_items--;

    if(n_items < n_allocated/4.0){
        reallocate(n_allocated/2);
    }
}

/**
 * @brief CircularArray::pop_back
 * Pop the object from the "back" of the circular array.
 * You don't need to delete the actual Thing object, but to mark it as deleted, you should set its value to -1
 *  i.e. data[something].value = -1
 * If the number of items in the array is < n_allocated/4.0 then reallocate with half the allocated space
 */
void CircularArray::pop_back()
{
    data[(idx_front + n_items -1) % n_allocated].value = -1;
    n_items--;

    if(n_items < n_allocated/4.0){
        reallocate(n_allocated/2);
    }
}

/**
 * @brief CircularArray::operator []
 * @param index
 * @return the Thing object that is index units from the "front"
 */
Thing &CircularArray::operator[](int index)
{
    return data[(idx_front + index) % n_allocated];
}

/**
 * @brief CircularArrayIterator::CircularArrayIterator
 * @param p Pointer to the parent CircularArray
 * @param idx Index in the CircularArray that this iterator refers to
 */
CircularArrayIterator::CircularArrayIterator(CircularArray *p, int idx) : parent(p), index(idx){

}

/**
 * @brief CircularArrayIterator::operator ++
 * Increment the iterator to point to the next item in the CircularArray
 * @return a reference to this iterator object
 */
CircularArrayIterator& CircularArrayIterator::operator++(){
    index = (index+1) % parent->n_allocated;
    return *this;
}

/**
 * @brief CircularArrayIterator::operator *
 * @return a reference to the relevant Thing object stored in the underlying CircularArray
 */
Thing& CircularArrayIterator::operator*(){
    return parent->operator[](index);
}

/**
 * @brief CircularArrayIterator::operator !=
 * @param other Iterator to compare with
 * @return true/false depending on whether this iterator refers to the same object or not
 */
bool CircularArrayIterator::operator!=(const CircularArrayIterator& other) const{
    return parent != other.parent || index != other.index;
}

/**
 * @brief CircularArray::begin
 * @return a CircularArrayIterator that refers to the first item in the CircularArray
 */
CircularArrayIterator CircularArray::begin()
{
    return CircularArrayIterator(this, 0);
}

/**
 * @brief CircularArray::end
 * @return a CircularArrayIterator that refers to the item "one past the end" in the CircularArray
 */
CircularArrayIterator CircularArray::end()
{
    return CircularArrayIterator(this, n_items);
}

/**
 * @brief CircularArray::~CircularArray
 */
CircularArray::~CircularArray()
{
    delete [] data;
}
