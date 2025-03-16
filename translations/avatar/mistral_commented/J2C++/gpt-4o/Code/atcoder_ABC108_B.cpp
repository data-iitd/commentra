#include <iostream>
#include <vector>

using namespace std;

// Define a function to reverse the order of elements in an array
vector<int> revpos(const vector<int>& p, const vector<int>& q) {
    vector<int> vec(2, 0); // Initialize a temporary vector with zeros

    // Iterate through the elements of the vector and calculate their differences
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = p[i] - q[i]; // Subtract corresponding elements of p and q and store the result in vec[i]
    }

    // Swap the first and second elements of the vector
    int tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;

    // Calculate the new positions by adding the vector elements to the corresponding elements of q
    vector<int> newpos(2, 0);
    for (int i = 0; i < newpos.size(); i++) {
        newpos[i] = q[i] + vec[i];
    }

    // Return the new positions
    return newpos;
}

// Define the main function to read input and perform the required calculations
int main() {
    // Create a vector to read input
    vector<int> input(4, 0);
    
    // Read four integers as input and store them in the vector
    for (int i = 0; i < input.size(); i++) {
        cin >> input[i]; // Read an integer from the standard input stream and store it in input[i]
    }

    // Define a 2D vector to store the positions of the four integers
    vector<vector<int>> position(4, vector<int>(2, 0));
    position[0][0] = input[0]; // Store the first integer as the x-coordinate of the first position
    position[0][1] = input[1]; // Store the second integer as the y-coordinate of the first position
    position[1][0] = input[2]; // Store the third integer as the x-coordinate of the second position
    position[1][1] = input[3]; // Store the fourth integer as the y-coordinate of the second position

    // Calculate the reversed positions of the first and second positions
    vector<vector<int>> reversedPositions(2, vector<int>(2, 0));
    reversedPositions[0] = revpos(position[0], position[1]);
    reversedPositions[1] = revpos(position[1], position[0]);

    // Check if the first and second reversed positions are equal
    if (position[0] == reversedPositions[1]) { // Compare the first position with the reversed second position
        cout << "OK" << endl; // Print "OK" if they are equal
    }

    // Calculate the output array by taking the reversed positions and swapping their x and y coordinates
    vector<int> output(4, 0);
    output[0] = reversedPositions[0][0]; // Store the x-coordinate of the reversed first position in output[0]
    output[1] = reversedPositions[0][1]; // Store the y-coordinate of the reversed first position in output[1]
    output[2] = reversedPositions[1][0]; // Store the x-coordinate of the reversed second position in output[2]
    output[3] = reversedPositions[1][1]; // Store the y-coordinate of the reversed second position in output[3]

    // Print the output array
    for (int i : output) {
        cout << i << endl;
    }

    return 0;
}

// <END-OF-CODE>
