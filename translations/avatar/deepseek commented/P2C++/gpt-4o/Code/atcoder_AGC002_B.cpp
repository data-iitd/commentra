#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Function to read a single integer from input
int readInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read multiple integers from a single line of input
vector<int> readInts() {
    int n;
    cin >> n;
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        cin >> result[i];
    }
    return result;
}

int main() {
    // Reading the number of balls (N) and the number of operations (M)
    int N = readInt();
    int M = readInt();

    // Initializing the list of balls with pairs [white pieces, red pieces]
    vector<pair<int, int>> balls(N, {1, 0});
    
    // Special initialization for the first ball
    balls[0] = {0, 1};

    // Loop to process each operation
    for (int i = 0; i < M; ++i) {
        int x = readInt();
        int y = readInt();
        
        // Extracting the current state of ball x and ball y
        int w_x = balls[x - 1].first;
        int r_x = balls[x - 1].second;
        int w_y = balls[y - 1].first;
        int r_y = balls[y - 1].second;

        // Swapping the balls if possible
        if (w_x >= 1 && r_x >= 1) {
            balls[x - 1].first -= 1;
            balls[y - 1].second += 1;
        } else if (w_x == 0) {
            balls[x - 1].second -= 1;
            balls[y - 1].second += 1;
        } else {
            balls[x - 1].first -= 1;
            balls[y - 1].first += 1;
        }
    }

    // Counting the number of balls with at least one red or white piece
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (balls[i].second > 0) {
            ans += 1;
        }
    }

    // Printing the final count
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
