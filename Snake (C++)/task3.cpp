#include <iostream>
#include <vector>

using namespace std;

int crteVec(int COLS, int ROWS, int X, int Y, int N){

// create vector and allocate 0
    vector<vector<int>> Matrix(ROWS, vector<int> (COLS,0) );
                for (int i = 0; i < ROWS; i++){
                    for (int j = 0; j < COLS; j++){
                      Matrix[i][j];
                    }
                }
// place apple
                Matrix[Y][X] = 5;

 // create a vector to store snake values       
    vector<int> snake;
    for (int i = 1; i <= (6*N); i++){
        int input; 
        cin >> input; cout << " ";
        snake.push_back(input);
    }

// print out vector which is storing snake info 
    //for (int i = 0; i < snake.size();i++){
      //  cout << snake[i] << endl;
    //}

// hard code for changing values of snake to 1, 2, 3 or 4
    if (N == 1){
        Matrix[snake[1]][snake[0]] = 1;
        Matrix[snake[3]][snake[2]] = 1;
        Matrix[snake[5]][snake[4]] = 1;
    }
    else if (N == 2){
        Matrix[snake[1]][snake[0]] = 1;
        Matrix[snake[3]][snake[2]] = 1;
        Matrix[snake[5]][snake[4]] = 1;
        Matrix[snake[7]][snake[6]] = 2;
        Matrix[snake[9]][snake[8]] = 2;
        Matrix[snake[11]][snake[10]] = 2;
    }
    else if (N == 3){
        Matrix[snake[1]][snake[0]] = 1;
        Matrix[snake[3]][snake[2]] = 1;
        Matrix[snake[5]][snake[4]] = 1;
        Matrix[snake[7]][snake[6]] = 2;
        Matrix[snake[9]][snake[8]] = 2;
        Matrix[snake[11]][snake[10]] = 2;
        Matrix[snake[13]][snake[12]] = 3;
        Matrix[snake[15]][snake[14]] = 3;
        Matrix[snake[17]][snake[16]] = 3;
    }
    else if (N == 4){
        Matrix[snake[1]][snake[0]] = 1;
        Matrix[snake[3]][snake[2]] = 1;
        Matrix[snake[5]][snake[4]] = 1;
        Matrix[snake[7]][snake[6]] = 2;
        Matrix[snake[9]][snake[8]] = 2;
        Matrix[snake[11]][snake[10]] = 2;
        Matrix[snake[13]][snake[12]] = 3;
        Matrix[snake[15]][snake[14]] = 3;
        Matrix[snake[17]][snake[16]] = 3;
        Matrix[snake[19]][snake[18]] = 4;
        Matrix[snake[21]][snake[20]] = 4;
        Matrix[snake[23]][snake[22]] = 4;
    }

// print final Matrix, with apple and snakes    
cout << endl;
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
    int N;
    cin >> COLS; cout << " "; cin >> ROWS; cout << endl;
    cin >> appleX; cout << " "; cin >> appleY; cout << endl;
    cin >> N; cout << endl;
    crteVec(COLS,ROWS,appleX,appleY,N);
    return 0;
}