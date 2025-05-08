


void print (){
    cout << "[";
    for (int i = 0; i < n_items; i++){
        if (i != 0){
            cout << ",";
        }
        cout << data[ (idx_front + i) % n_allocated];
    }
    cout << "]";
}

int size(){
    return n_items;
}

int allocated(){
    return n_allocated;
}

void reallocate(int new_size){
    Thing*tmp = new Thing[new_size];
    for (int i = 0; i < n_items; i++){
        tmp[i] = data[(idx_front+i)%n_allocated];
    }
    delete[]data;
    data = tmp;
    idx_front = 0;
    n_allocated = new_size;
}

void push_back(const Thing &t){
    if (n_allocated == 0){
        reallocate(1);
    }
    else if (n_allocated == n_items){
        reallocate(2*n_allocated);
    }
    data[(idx_front + n_items) % n_allocated] = t;
    n_items++;
}

void push_front(){
   if (n_allocated == 0){
    reallocate(1);
   }
   else if (n_allocated = n_items){
    reallocate(2*n_allocated);
   }
   idx_front--;
   if (idx_front <0){
    idx_front = n_allocated-1;
   }
   data[idx_front] = t;
   n_items++;
}

void pop_front(){
    data[idx_front].value = -1;
    idx_front = (idx_front+1)%n_allocated;
    n_items--;

    if (n_items < n_allocated/4){
        reallocate(n_allocated/2);
    }
}

void pop_back(){
    data[(idx_front+n_items-1)%n_allocated];
    n_items--;

    if (n_items)
}

void operator[](int index){
    return data[(idx_front+index)%n_allocated];
}

