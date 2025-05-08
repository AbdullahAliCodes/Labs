#include <iostream>
#include <vector>

using namespace std;

void setCellValue(int row, int col, vector<vector<int>>& matrix, int value) {
    matrix[row][col] = value;
}

void updateSnakePosition(std::vector<std::vector<int>>& matrix, const std::vector<int>& snakeCoords, int snakeID) {
    for (size_t i = 0; i < snakeCoords.size() - 2; i += 2) {
        int startX = snakeCoords[i];
        int startY = snakeCoords[i + 1];
        int endX = snakeCoords[i + 2];
        int endY = snakeCoords[i + 3];

        int dx = (endX > startX) ? 1 : ((endX < startX) ? -1 : 0);
        int dy = (endY > startY) ? 1 : ((endY < startY) ? -1 : 0);

        int currX = startX;
        int currY = startY;

        while (currX != endX || currY != endY) {
            setCellValue(currY, currX, matrix, snakeID);
            currX += dx;
            currY += dy;
        }
    }

    int tailX = snakeCoords[snakeCoords.size() - 2];
    int tailY = snakeCoords[snakeCoords.size() - 1];
    setCellValue(tailY, tailX, matrix, snakeID);
}


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    int numCols;
    int numRows;

    // Apple coordinates
    int appleX;
    int appleY;

    cin >> numCols >> numRows;
    cin >> appleX >> appleY;

    vector<vector<int>> matrix(numRows, vector<int>(numCols, 0));
    setCellValue(appleY, appleX, matrix, 5);

    int numSnakes;
    cin >> numSnakes;

    for (int snakeID = 1; snakeID <= numSnakes; snakeID++) {
        int numSegments;
        cin >> numSegments;
        vector<int> snakeCoords;

        for (int i = 0; i < numSegments * 2; i++) {
            int coord;
            cin >> coord;
            snakeCoords.push_back(coord);
        }

        updateSnakePosition(matrix, snakeCoords, snakeID);
    }

    printMatrix(matrix);

    return 0;
}
