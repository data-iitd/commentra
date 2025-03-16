#include <iostream> // Include the standard input/output library
#include <vector>   // Include the vector library
using namespace std; // Use the standard namespace

#define N 4 // Define a constant N for the size of the puzzle

struct Pazz { // Define a structure for the puzzle
    int P[N][N]; // 2D array to store the puzzle state
};

Pazz Q; // Initialize a global variable Q to store the puzzle state
int dx[4] = {0, 1, 0, -1}; // Define an array for horizontal movement directions
int dy[4] = {1, 0, -1, 0}; // Define an array for vertical movement directions

int Heu(Pazz Q) { // Heuristic function to calculate the Manhattan distance
    int sum = 0;
    for (int i = 0; i < N; i++) { // Iterate through each row
        for (int j = 0; j < N; j++) { // Iterate through each column
            if (Q.P[i][j] == 0) continue; // Skip the empty tile

            int hx = (Q.P[i][j] - 1) % N - j; // Calculate the horizontal distance
            int hy = (Q.P[i][j] - 1) / N - i; // Calculate the vertical distance

            sum += abs(hx) + abs(hy); // Add the absolute distances to the sum
        }
    }
    return sum; // Return the total sum of Manhattan distances
}

int dfs(int x, int y, int max, int count, int n) { // Depth-first search function
    int ans = -1;
    int h = Heu(Q); // Calculate the heuristic value of the current state

    if (h == 0) return count; // If the puzzle is solved, return the number of moves
    if ((count + h) > max) return -1; // If the maximum depth is exceeded, return -1

    for (int i = 0; i < 4; i++) { // Iterate through all possible moves
        int x0 = x + dx[i];
        int y0 = y + dy[i];

        if (((i == (n + 2) % 4) && (n != -1)) || !((0 <= x0) && (x0 < N) && (0 <= y0) && (y0 < N))) continue; // Skip invalid moves

        // Swap the current tile with the target tile
        swap(Q.P[y][x], Q.P[y0][x0]);

        ans = dfs(x0, y0, max, count + 1, i); // Recursively call dfs with the new state

        if (ans != -1) return ans; // If a solution is found, return the number of moves

        // Swap back to the original state
        swap(Q.P[y][x], Q.P[y0][x0]);
    }

    return -1; // If no solution is found, return -1
}

int main() { // Main function to read the puzzle, initialize it, and start the DFS search
    int kx, ky, ans, a;
    Pazz tP;

    for (int i = 0; i < N; i++) { // Read the puzzle from input
        for (int j = 0; j < N; j++) {
            cin >> a;
            Q.P[i][j] = a;
            if (a == 0) {
                kx = j;
                ky = i;
            }
        }
    }

    tP = Q; // Store the initial puzzle state
    for (int i = 1; i < 46; i++) { // Iterate through possible depths
        Q = tP;
        ans = dfs(kx, ky, i, 0, -1);
        if (ans != -1) {
            cout << ans << endl; // Print the number of moves if a solution is found
            break;
        }
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
