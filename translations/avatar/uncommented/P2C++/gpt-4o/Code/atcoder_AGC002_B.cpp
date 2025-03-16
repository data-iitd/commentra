#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> balls(N, vector<int>(2, 1));
    balls[0][0] = 0; // Set the first ball's weight to 0 and radius to 1
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; // Convert to 0-based index
        y--; // Convert to 0-based index
        int w_x = balls[x][0], r_x = balls[x][1];
        int w_y = balls[y][0], r_y = balls[y][1];
        
        if (w_x >= 1 && r_x >= 1) {
            balls[x][0]--; // Decrease weight of x
            balls[y][1]++; // Increase radius of y
        } else if (w_x == 0) {
            balls[x][1]--; // Decrease radius of x
            balls[y][1]++; // Increase radius of y
        } else {
            balls[x][0]--; // Decrease weight of x
            balls[y][0]++; // Increase weight of y
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1]) {
            ans++; // Count balls with non-zero radius
        }
    }
    cout << ans << endl;

    return 0;
}
// <END-OF-CODE>
