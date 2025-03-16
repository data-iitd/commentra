#include <iostream>
#include <vector>

using namespace std;

// Box class representing a box with a number and a color state
class Box {
public:
    int num; // Number of items in the box
    bool red; // Indicates if the box is red

    // Constructor to initialize the box with a number and color
    Box(int n, bool r) : num(n), red(r) {}

    // Method to move items from this box to another box
    void moveTo(Box& other) {
        // If this box is empty, do nothing
        if (num == 0) {
            return;
        }
        // If this box has one item, transfer it to the other box
        else if (num == 1) {
            num = 0;
            other.num++;
            // If this box is red, the other box becomes red
            if (red) {
                other.red = true;
            }
            red = false; // This box is no longer red
        }
        // If this box has more than one item, transfer one item to the other box
        else {
            num--;
            other.num++;
            // If this box is red, the other box becomes red
            if (red) {
                other.red = true;
            }
        }
    }
};

int main() {
    // Create a Scanner object to read input from the user
    int N, M;
    cin >> N >> M;

    // Initialize a vector of Box objects
    vector<Box> B;

    // Create the first box as red and the rest as not red
    B.emplace_back(1, true);
    for (int i = 1; i < N; i++) {
        B.emplace_back(1, false);
    }

    // Process M moves based on user input
    for (int i = 0; i < M; i++) {
        // Read the indices of the boxes to move from and to
        int x, y;
        cin >> x >> y;
        // Move the contents from box x to box y (adjusting for 0-based index)
        B[x - 1].moveTo(B[y - 1]);
    }

    // Count the number of red boxes after all moves
    int counter = 0;
    for (const Box& b : B) {
        if (b.red) {
            counter++;
        }
    }

    // Output the count of red boxes
    cout << counter << endl;

    return 0;
}

// <END-OF-CODE>
