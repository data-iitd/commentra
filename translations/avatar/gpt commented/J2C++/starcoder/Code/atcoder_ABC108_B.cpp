/C#:
#include <iostream>

using namespace std;

// Method to calculate the new position based on two input positions
int* revpos(int* p, int* q) {
    // Initialize a vector to hold the difference between the two positions
    int* vec = new int[2];
    
    // Calculate the difference between position p and q
    for (int i = 0; i < 2; i++) {
        vec[i] = p[i] - q[i];
    }
    
    // Rotate the vector to get the new direction
    int tmp = 0;
    tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    
    // Initialize a new position array
    int* newpos = new int[2];
    
    // Calculate the new position by adding the rotated vector to position q
    for (int i = 0; i < 2; i++) {
        newpos[i] = q[i] + vec[i];
    }
    
    // Return the newly calculated position
    return newpos;
}

int main() {
    // Array to hold the input values
    int* input = new int[4];
    
    // Read four integers from the user input
    for (int i = 0; i < 4; i++) {
        cin >> input[i];
    }
    
    // Initialize a 2D array to hold positions
    int** position = new int*[4];
    for (int i = 0; i < 4; i++) {
        position[i] = new int[2];
    }
    
    // Assign input values to the first two positions
    position[0][0] = input[0];
    position[0][1] = input[1];
    position[1][0] = input[2];
    position[1][1] = input[3];
    
    // Calculate the new position based on the first two positions
    position[2] = revpos(position[0], position[1]);
    
    // Calculate another new position based on the second and third positions
    position[3] = revpos(position[1], position[2]);
    
    // Check if the first position is equal to the result of revpos on the last two positions
    if (position[0] == revpos(position[2], position[3])) {
        cout << "OK" << endl;
    }
    
    // Prepare an output array to hold the results
    int* output = new int[4];
    
    // Assign the calculated positions to the output array
    output[0] = position[2][0];
    output[1] = position[2][1];
    output[2] = position[3][0];
    output[3] = position[3][1];
    
    // Print the output values
    for (int i = 0; i < 4; i++) {
        cout << output[i] << endl;
    }
    
    // Free the memory allocated to the arrays
    for (int i = 0; i < 4; i++) {
        delete[] position[i];
    }
    delete[] position;
    delete[] input;
    delete[] output;
    
    return 0;
}

