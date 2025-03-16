#include <iostream> // Include the iostream library for input and output
#include <vector>   // Include the vector library for using vectors

using namespace std;

// The revpos function calculates the difference between two positions,
// swaps the components of the difference vector, and then adds the modified
// difference vector to the second position.
vector<int> revpos(const vector<int>& p, const vector<int>& q) {
    vector<int> vec(2); // Initialize the vector to store the difference
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = p[i] - q[i]; // Calculate the difference between p and q
    }
    int tmp = vec[0]; // Temporary variable to swap the components of the vector
    vec[0] = vec[1]; // Swap the second component to the first position
    vec[1] = -tmp;   // Negate the first component and store it in the second position
    vector<int> newpos(2); // Initialize the new position vector
    for (int i = 0; i < newpos.size(); i++) {
        newpos[i] = q[i] + vec[i]; // Add the modified difference vector to the second position
    }
    return newpos; // Return the new position
}

int main() {
    vector<int> input(4); // Initialize the input vector to store four integers
    for (int i = 0; i < input.size(); i++) {
        cin >> input[i]; // Read four integers from the user
    }
    
    vector<vector<int>> position(4, vector<int>(2, 0)); // Initialize the position array
    position[0][0] = input[0]; // Assign the first integer to the first position's x-coordinate
    position[0][1] = input[1]; // Assign the second integer to the first position's y-coordinate
    position[1][0] = input[2]; // Assign the third integer to the second position's x-coordinate
    position[1][1] = input[3]; // Assign the fourth integer to the second position's y-coordinate
    position[2] = revpos(position[0], position[1]); // Compute the new position using revpos
    position[3] = revpos(position[1], position[2]); // Compute another new position using revpos

    // Check if the first position is equal to the result of revpos on the second and third positions
    if (position[0] == revpos(position[2], position[3])) {
        cout << "OK" << endl; // Print "OK" if they are equal
    }

    vector<int> output(4); // Initialize the output vector
    output[0] = position[2][0]; // Assign the x-coordinate of the second new position to the output vector
    output[1] = position[2][1]; // Assign the y-coordinate of the second new position to the output vector
    output[2] = position[3][0]; // Assign the x-coordinate of the third new position to the output vector
    output[3] = position[3][1]; // Assign the y-coordinate of the third new position to the output vector

    for (int i : output) {
        cout << i << endl; // Print each element of the output vector
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
