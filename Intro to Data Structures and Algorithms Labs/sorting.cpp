#include <iostream>
#include <vector>
using namespace std;

//O(n^2)

void bubbleSort(std::vector<int>vals){
    //sorted side is on the right
    int n = vals.size();
    for (int i=0;i<n-1;i++){              //n
        for (int j =0 ;j<n-1-i;j++){   //n
            if (vals[j]>vals[j+1]){
                int temp = vals[j];
                vals[j]=vals[j+1];
                vals[j+1]=temp;
            }
        }
    }
}

void selectionSort(std::vector<int>vals){
    //select minimum, move to left side / "sorted side"
    int n = vals.size();
    for (int i=0;i<n-1;i++){
        int minIndex =i;
        for (int j=i+1;j<n;j++){
            if (vals[j]<vals[minIndex]){
                minIndex = j;
            }
        }

        if (minIndex!=i){
            int temp = vals[minIndex];
            vals[minIndex]=vals[i];
            vals[i]=temp;
        }
    }

}

void insertionSort(std::vector<int>vals){
    int n = vals.size();
    for (int i=1;i<n;i++){
        int key = vals[i];
        int j = i-1;

        while (j>=0 && vals[j]>key){
            vals[j+1]=vals[j];
            j = j-1;
        }

        vals[j+1]=key;
    }
}


int main(){
    std::vector<int> vals = {7,4,8,1,4,9,0,2};
    
    for (auto v : vals){
        std::cout << v << " ";
    }
}