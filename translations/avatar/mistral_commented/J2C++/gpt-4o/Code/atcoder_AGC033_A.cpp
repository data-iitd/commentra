#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    // Create a Scanner object to read input from the standard input
    int H, W;
    cin >> H >> W;

    // Initialize a 2D char vector 'A' to store the input grid
    vector<vector<char>> A(H, vector<char>(W));

    // Initialize a Queue to store the cells to be processed
    queue<vector<int>> q;

    // Read the grid and initialize the queue with the starting points of 'B'
    for (int i = 0; i < H; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++) {
            A[i][j] = row[j];
            // If the cell contains '#', add its starting point to the queue
            if (A[i][j] == '#') {
                q.push({i, j, 0});
            }
        }
    }

    // Initialize a 2D int vector 'flag' to mark the visited cells
    vector<vector<int>> flag(H, vector<int>(W, 0));

    // Initialize variables for the answer and the directions
    int ans = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // Process the queue and find the answer
    while (!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        int y = temp[0];
        int x = temp[1];
        int depth = temp[2];

        // Process the neighboring cells
        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];

            // If the cell is within the grid and hasn't been visited yet,
            // and contains a '.', mark it as visited and add it to the queue
            if (0 <= newY && newY < H && 0 <= newX && newX < W) {
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1;
                    q.push({newY, newX, depth + 1});
                    ans = max(ans, depth + 1);
                }
            }
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
