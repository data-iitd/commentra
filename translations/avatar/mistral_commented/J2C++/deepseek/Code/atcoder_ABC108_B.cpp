#include <iostream>
#include <vector>

// Define a function to reverse the order of elements in an array
std::vector<int> revpos(const std::vector<int>& p, const std::vector<int>& q) {
    std::vector<int> vec(2, 0); // Initialize a temporary vector with zeros

    // Iterate through the elements of the vector and calculate their differences
    vec[0] = p[0] - q[0]; // Subtract corresponding elements of p and q and store the result in vec[0]
    vec[1] = p[1] - q[1]; // Subtract corresponding elements of p and q and store the result in vec[1]

    // Swap the first and second elements of the vector
    int tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;

    // Calculate the new positions by adding the vector elements to the corresponding elements of q
    std::vector<int> newpos(2, 0);
    newpos[0] = q[0] + vec[0];
    newpos[1] = q[1] + vec[1];

    // Return the new positions
    return newpos;
}

int main() {
    // Create a vector to store the positions of the four integers
    std::vector<int> input(4, 0);

    // Read four integers as input and store them in the vector
    for (int i = 0; i < 4; i++) {
        std::cin >> input[i]; // Read an integer from the standard input stream and store it in input[i]
    }

    // Define a 2D vector to store the positions of the four integers
    std::vector<std::vector<int>> position(2, std::vector<int>(2, 0));
    position[0][0] = input[0]; // Store the first integer as the x-coordinate of the first position
    position[0][1] = input[1]; // Store the second integer as the y-coordinate of the first position
    position[1][0] = input[2]; // Store the third integer as the x-coordinate of the second position
    position[1][1] = input[3]; // Store the fourth integer as the y-coordinate of the second position

    // Calculate the reversed positions of the first and second positions
    std::vector<std::vector<int>> reversedPositions(2, std::vector<int>(2, 0));
    reversedPositions[0] = revpos(position[0], position[1]);
    reversedPositions[1] = revpos(position[1], position[0]);

    // Check if the first and second reversed positions are equal
    if (position[0] == reversedPositions[1]) { // Compare the first position with the reversed second position
        std::cout << "OK" << std::endl; // Print "OK" if they are equal
    }

    // Calculate the output array by taking the reversed positions and swapping their x and y coordinates
    std::vector<int> output(4, 0);
    output[0] = reversedPositions[0][0]; // Store the x-coordinate of the reversed first position in output[0]
    output[1] = reversedPositions[0][1]; // Store the y-coordinate of the reversed first position in output[1]
    output[2] = reversedPositions[1][0]; // Store the x-coordinate of the reversed second position in output[2]
    output[3] = reversedPositions[1][1]; // Store the y-coordinate of the reversed second position in output[3]

    // Print the output array
    for (int i : output) {
        std::cout << i << std::endl;
    }

    return 0;
}
