
#include <iostream> // Include the necessary header file for input/output operations

using namespace std; // Using the standard namespace for input/output operations

int main() { // Defining the main function
    int N, M; // Declaring the variables N and M to store the number of boxes and the number of moves, respectively
    cin >> N >> M; // Reading the input values for N and M from the user

    int* num = new int[N]; // Creating an array of integers to store the number of items in each box
    bool* red = new bool[N]; // Creating an array of booleans to store the color of each box

    // Initializing the first box with red color
    num[0] = 1;
    red[0] = true;

    // Initializing the remaining boxes with red color set to false
    for (int i = 1; i < N; i++) {
        num[i] = 1;
        red[i] = false;
    }

    // Reading the moves from the user and performing them on the boxes
    for (int i = 0; i < M; i++) {
        int x, y; // Declaring the variables x and y to store the source and destination box indices, respectively
        cin >> x >> y; // Reading the input values for x and y from the user
        if (num[x - 1] > 0) { // If the source box is not empty
            num[x - 1]--; // Decrementing the number of items in the source box
            num[y - 1]++; // Incrementing the number of items in the destination box
            if (red[x - 1]) { // If the source box was red
                red[y - 1] = true; // Setting the destination box to be red
            }
        }
    }

    // Counting the number of red boxes
    int counter = 0;
    for (int i = 0; i < N; i++) { // Iterating through all the boxes
        if (red[i]) { // If the current box is red
            counter++; // Increment the counter
        }
    }

    // Printing the result
    cout << counter << endl; // Printing the number of red boxes

    delete[] num; // Deallocating the memory used by the num array
    delete[] red; // Deallocating the memory used by the red array

    return 0; // Returning 0 to indicate successful execution of the program
}

