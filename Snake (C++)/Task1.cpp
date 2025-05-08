#include <iostream>
#include <vector>

using namespace std;

int COLS = 5;
int ROWS = 2;

int crteVec(int COLS, int ROWS){
    vector<vector<int>> Matrix(ROWS, vector<int> (COLS,0) );

    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            cout << Matrix[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}

int main(){
    int COLS;
    int ROWS;
    cin >> COLS >> ROWS;
    crteVec(COLS,ROWS);
    return 0;
}
