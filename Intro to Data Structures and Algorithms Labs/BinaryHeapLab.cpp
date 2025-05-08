#include <iostream>
#include <vector>
using namespace std;

class BinaryHeap{

public:
    
    vector<int>data ;
    int _size{};
    bool isEmpty() const { 
        return _size == 0;
    }
    
    int parent(int idx){
        return (idx - 1)/2; //(i>>1) is i divided by two. this is how we find the parent. Its the child divided by 2 to get the parent
    }

    int left_child(int idx){
        return idx*2;
    }

    int right_child(int idx){
        return (idx*2)+1;
    }

    void push(int value){
        data.push_back(value);
        ShiftDown(data.size()-1);
    }
    void ShiftUp(int idx){
        if(idx > _size){
            return;
        }
        if( idx == 1){
            return;
        }
        if(data[idx] > data[parent(idx)]){
            std::swap(data[parent(idx)],data[idx]);
        }
        ShiftUp(parent(idx));
    }
    void ShiftDown(int idx){
        int p = data[parent(idx)];
        int child = data[idx];
        if(p < child){
            data[parent(idx)] = child;
            data[idx] = p;
            int new_child = parent(idx);
            ShiftDown(new_child);
        }
    }
    void pop(){
        data[0] = data.back();
        data.pop_back();
        ShiftDown(0);
    }

    void print(){
        for(auto &v : data){
            cout << v << " ";
        }
        cout << endl;
    }
    
};    
int main()
{
    
    BinaryHeap bh;
    string line;
    while(getline(cin, line) && line[0] != 'x'){
        
        if(line[0] == 'p'){
            bh.pop();
        }else{
            bh.push(stoi(line));
        }
        bh.print();
    }

    return 0;
}