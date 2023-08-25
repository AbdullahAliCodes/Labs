#include <iostream>
#include <vector>

using namespace std;

int COLS = 5;
int ROWS = 2;

int crteVec(int COLS, int ROWS, 
            int x,int y,
            int a, int b, int c, int d, int e, int f){
            
                 vector<vector<int>> Matrix(ROWS, vector<int> (COLS,0) );

                for (int i = 0; i < ROWS; i++){
                    for (int j = 0; j < COLS; j++){
                      Matrix[i][j];
                    }
                    cout << endl;
                }
                Matrix[y][x] = 5;
                Matrix[b][a] = 1;
                Matrix[d][c] = 1;
                Matrix[f][e] = 1;
                for (const auto& row : Matrix) {
                    for (const auto& element : row) {
                        cout << element << " ";
                    }
                cout << endl;
                }
    return 0;
}

int main(){
    int COLS; int ROWS;
    int appleX; int appleY;
    int head1; int head2; int body1; int body2; int tail1; int tail2;
    cin >> COLS >> ROWS;
    cout << endl;
    cin >> appleX >> appleY;
    cout << endl;
    cin >> head1 >> head2 >> body1 >> body2 >> tail1 >> tail2;
    crteVec(COLS,ROWS,
            appleX,appleY,
            head1,head2,body1,body2,tail1,tail2);
    return 0;
}