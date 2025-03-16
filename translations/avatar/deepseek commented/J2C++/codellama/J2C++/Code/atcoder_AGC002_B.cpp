
#include <iostream>
#include <cstdlib>

using namespace std;

class Box {
    public:
        int num;
        bool red;
        Box(int n, bool r) {
            num = n;
            red = r;
        }
        void moveTo(Box other) {
            if (num == 0) {
                return; // Do nothing if the box is already empty
            } else if (num == 1) {
                num = 0; // Set the current box to empty
                other.num++; // Increment the destination box's number
                if (red) {
                    other.red = true; // If the current box was red, make the destination box red
                }
                red = false; // The current box is no longer red
            } else {
                num--; // Decrement the current box's number
                other.num++; // Increment the destination box's number
                if (red) {
                    other.red = true; // If the current box was red, make the destination box red
                }
            }
        }
};

int main() {
    int N, M;
    cin >> N >> M; // Read the number of boxes and the number of moves
    Box *B = new Box[N]; // Initialize the array of boxes
    B[0] = Box(1, true); // Initialize the first box with num=1 and red=true
    for (int i = 1; i < N; i++) {
        B[i] = Box(1, false); // Initialize the rest of the boxes with num=1 and red=false
    }
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y; // Read the source box index (0-based) and the destination box index (0-based)
        B[x].moveTo(B[y]); // Move the box from source to destination
    }
    int counter = 0;
    for (int i = 0; i < N; i++) {
        if (B[i].red) {
            counter++; // Count the number of red boxes
        }
    }
    cout << counter << endl; // Print the count of red boxes
    return 0;
}

