#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x;
    int y;

    Point(int _x, int _y) : x(_x), y(_y) {}
};

void calculateDistances(const Point& head, const std::vector<std::vector<int>>& matrix, const Point& apple, std::vector<double>& distances, std::vector<std::string>& labels) {
    const std::vector<Point> directions = { Point(1, 0), Point(-1, 0), Point(0, -1), Point(0, 1) };
    const std::vector<std::string> directionLabels = { "RIGHT", "LEFT", "UP", "DOWN" };

    for (int i = 0; i < directions.size(); i++) {
        Point next = Point(head.x + directions[i].x, head.y + directions[i].y);
        if (next.x >= 0 && next.x < matrix[0].size() && next.y >= 0 && next.y < matrix.size() && matrix[next.y][next.x] == 0) {
            double dist = std::sqrt(std::pow(apple.x - next.x, 2) + std::pow(apple.y - next.y, 2));
            distances.push_back(dist);
            labels.push_back(directionLabels[i]);
        }
    }
}

void printBestMoves(std::vector<std::string>& bestMoves) {
    if (bestMoves.empty()) {
        std::cout << "No valid moves available." << std::endl;
    }
    else {
        std::sort(bestMoves.begin(), bestMoves.end(), [](const std::string& a, const std::string& b) {
            return a < b;
        });
        for (const std::string& move : bestMoves) {
            std::cout << move << std::endl;
        }
    }
}

void findBestMoves(const Point& head, const std::vector<std::vector<int>>& matrix, const Point& apple) {
    std::vector<double> distances;
    std::vector<std::string> labels;

    calculateDistances(head, matrix, apple, distances, labels);

    if (distances.empty()) {
        std::vector<std::string> bestMoves;
        printBestMoves(bestMoves);
    }
    else {
        double minDist = *std::min_element(distances.begin(), distances.end());
        std::vector<std::string> bestMoves;
        for (int i = 0; i < distances.size(); i++) {
            if (distances[i] == minDist) {
                bestMoves.push_back(labels[i]);
            }
        }
        printBestMoves(bestMoves);
    }
}

int main() {
    int cols, rows;
    std::cin >> cols >> rows;

    int xapp, yapp;
    std::cin >> xapp >> yapp;
    Point apple(xapp, yapp);

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

    int numsnakes;
    std::cin >> numsnakes;
    std::vector<Point> heads;

    for (int i = 1; i <= numsnakes; i++) {
        int shx, shy, sbx, sby, stx, sty;
        std::cin >> shx >> shy >> sbx >> sby >> stx >> sty;

        matrix[shy][shx] = i;
        matrix[sby][sbx] = i;
        matrix[sty][stx] = i;

        if (i == 1) {
            heads.emplace_back(shx, shy);
        }
    }

    findBestMoves(heads[0], matrix, apple);

    return 0;
}
