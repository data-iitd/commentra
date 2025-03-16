#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays

using namespace std; // Using the standard namespace

class Box { // Defining the Box class
public:
    int num; // Initializing the number property
    bool red; // Initializing the red property

    // Constructor for initializing the Box object
    Box(int n, bool r) : num(n), red(r) {}

    // Method for moving the box to another box
    void moveTo(Box& other) {
        if (num == 0) { // If the current box is empty
            return; // Do nothing
        } else if (num == 1) { // If the current box has only one item
            num = 0; // Setting the current box to be empty
            other.num++; // Incrementing the number of items in the other box
            if (red) { // If the current box was red
                other.red = true; // Setting the other box to be red
            }
            red = false; // Setting the current box to be empty and not red
        } else { // If the current box has more than one item
            num--; // Decrementing the number of items in the current box
            other.num++; // Incrementing the number of items in the other box
            if (red) { // If the current box was red
                other.red = true; // Setting the other box to be red
            }
        }
    }
};

int main() { // Defining the main function
    int N, M; // Declaring variables for number of boxes and moves
    cin >> N >> M; // Reading the first integer input (number of boxes) and second integer input (number of moves)

    vector<Box> B; // Creating a vector of Box objects
    B.push_back(Box(1, true)); // Initializing the first box with red color

    // Initializing the remaining boxes with red color set to false
    for (int i = 1; i < N; i++) {
        B.push_back(Box(1, false));
    }

    // Reading the moves from the user and performing them on the boxes
    for (int i = 0; i < M; i++) {
        int x, y; // Declaring variables for source and destination box indices
        cin >> x >> y; // Reading the x-coordinate of the source box and y-coordinate of the destination box
        B[x - 1].moveTo(B[y - 1]); // Moving the box at index x to the box at index y
    }

    // Counting the number of red boxes
    int counter = 0; // Initializing the counter
    for (const Box& b : B) { // Iterating through all the boxes in the vector
        if (b.red) { // If the current box has red color
            counter++; // Increment the counter
        }
    }

    // Printing the result
    cout << counter << endl; // Outputting the count of red boxes
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
