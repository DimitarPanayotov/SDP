//
// Created by 35988 on 12/24/2024.
//
#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;

struct Position {
    int x, y, distance;
    Position(int x, int y, int distance = 0) : x(x), y(y), distance(distance) {}
};

const int width = 5; //Dimensions for
const int height = 5; //the labirynth

int dx[] = {-1, 1, 0, 0}; //up, down
int dy[] = {0, 0, -1, 1}; //left, right

bool is_valid_move(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited){
    return (x >= 0 && x < width && y >= 0 && y < height &&
    !maze[x][y] && !visited[x][y]);
}
int solve_maze(vector<vector<int>>& maze, Position start, Position end) {
    vector<vector<bool>> visited(width, vector<bool>(height, false));
    queue<Position> q;
    q.push(start);
    while(!q.empty()) {
        Position curr = q.front();
        q.pop();
        if(curr.x == end.x && curr.y == end.y) {
            return curr.distance;
        }
        for(int i=0;i<4;i++){
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];
            if (is_valid_move(newX, newY, maze, visited)){
                q.push(Position(newX, newY, curr.distance+1));
                visited[newX][newY] = true;
            }
        }
    }
        return -1;
}
int main () {
// 0=road, 1=wall
    vector<vector<int>> maze = {
            {0, 0, 0, 0, 1},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0}
    };

    Position start(0, 0);
    Position end(4, 4);

    std::cout << solve_maze(maze, start, end);

    return 0;
}