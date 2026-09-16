#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isSafe(vector<vector<int>>& maze, vector<vector<int>>& visited, int x, int y) {
        int n = maze.size();
        return (x >= 0 && x < n) && (y >= 0 && y < n) && (maze[x][y] == 1) && (visited[x][y] == 0);
    }

    void solve(vector<vector<int>>& maze, vector<vector<int>>& visited, string path, int x, int y, vector<string>& ans) {
        int n = maze.size();
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }
        visited[x][y] = 1;
        // Up
        int newx = x - 1;
        int newy = y;
        if (isSafe(maze, visited, newx, newy)) {
            path.push_back('U');
            solve(maze, visited, path, newx, newy, ans);
            path.pop_back();
        }
        // Down
        newx = x + 1;
        newy = y;
        if (isSafe(maze, visited, newx, newy)) {
            path.push_back('D');
            solve(maze, visited, path, newx, newy, ans);
            path.pop_back();
        }
        // Left
        newx = x;
        newy = y - 1;
        if (isSafe(maze, visited, newx, newy)) {
            path.push_back('L');
            solve(maze, visited, path, newx, newy, ans);
            path.pop_back();
        }
        // Right
        newx = x;
        newy = y + 1;
        if (isSafe(maze, visited, newx, newy)) {
            path.push_back('R');
            solve(maze, visited, path, newx, newy, ans);
            path.pop_back();
        }
        // Backtracking
        visited[x][y] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if (maze[0][0] == 0)
            return ans;
        string path = "";
        vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(maze, visited, path, 0, 0, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    Solution obj;
    vector<string> ans = obj.ratInMaze(maze);
    cout << "Possible paths:\n";
    for (string path : ans) {
        cout << path << " ";
    }
    cout << endl;
    return 0;
}