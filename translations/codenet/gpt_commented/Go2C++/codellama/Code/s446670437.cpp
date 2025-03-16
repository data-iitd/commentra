
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Dice struct represents a dice with its six faces numbered.
struct Dice {
    vector<int> nums; // Array to hold the numbers on the faces of the dice
};

// rotate method rotates the dice in a specified direction a certain number of times.
void rotate(Dice& d, string direction, int times) {
    times %= 4; // Normalize the number of rotations to be within 0-3
    switch (direction[0]) {
        case 'W': // Rotate West
            for (int i = 0; i < times; i++) {
                d.nums[0] = d.nums[2];
                d.nums[2] = d.nums[5];
                d.nums[5] = d.nums[3];
                d.nums[3] = d.nums[0];
            }
            break;
        case 'E': // Rotate East
            for (int i = 0; i < times; i++) {
                d.nums[0] = d.nums[3];
                d.nums[2] = d.nums[5];
                d.nums[5] = d.nums[3];
                d.nums[3] = d.nums[0];
            }
            break;
        case 'N': // Rotate North
            for (int i = 0; i < times; i++) {
                d.nums[0] = d.nums[1];
                d.nums[0] = d.nums[0];
                d.nums[4] = d.nums[5];
                d.nums[5] = d.nums[1];
            }
            break;
        case 'S': // Rotate South
            for (int i = 0; i < times; i++) {
                d.nums[5] = d.nums[1];
                d.nums[0] = d.nums[0];
                d.nums[4] = d.nums[5];
                d.nums[5] = d.nums[1];
            }
            break;
    }
}

// roll method rolls the dice in a specified direction a certain number of times.
void roll(Dice& d, string direction, int times) {
    times %= 4; // Normalize the number of rolls to be within 0-3
    switch (direction[0]) {
        case 'R': // Roll Right
            for (int i = 0; i < times; i++) {
                d.nums[3] = d.nums[1];
                d.nums[1] = d.nums[2];
                d.nums[2] = d.nums[4];
                d.nums[4] = d.nums[3];
            }
            break;
        case 'L': // Roll Left
            for (int i = 0; i < times; i++) {
                d.nums[3] = d.nums[4];
                d.nums[1] = d.nums[2];
                d.nums[2] = d.nums[4];
                d.nums[4] = d.nums[3];
            }
            break;
    }
}

// printStatus method prints the current status of the dice in a formatted manner.
void printStatus(Dice& d) {
    string status =
    "     _ _ _ _\n"
    "     _ %3d_|_ _ _ _ _ _\n"
    "    |_%3d_|_%3d_|_%3d_|_%3d_|\n"
    "       |_%3d_|\n";
    cout << status << endl;
}

// getIndex function returns the index of a target number in the nums slice.
int getIndex(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (target == nums[i]) {
            return i; // Found the target, return its index
        } else {
            return -1; // Target not found, return -1
        }
    }
}

// isEqual method checks if two dice are in the same state (same numbers on each face).
bool isEqual(Dice& d1, Dice& d2) {
    for (int i = 0; i < d1.nums.size(); i++) {
        if (d1.nums[i] != d2.nums[i]) {
            return false; // If any face differs, return false
        }
    }
    return true; // All faces match, return true
}

// main function to execute the dice comparison logic.
int main() {
    // Initialize two dice
    Dice dice1;
    Dice dice2;

    // Input numbers for the first dice
    for (int i = 0; i < 6; i++) {
        int n;
        cin >> n; // Read input for each face
        dice1.nums.push_back(n); // Assign input to the dice
    }

    // Input numbers for the second dice
    for (int i = 0; i < 6; i++) {
        int n;
        cin >> n; // Read input for each face
        dice2.nums.push_back(n); // Assign input to the dice
    }

    // Define the order of directions and rolls for testing
    vector<string> directionOrder = {"N", "S", "W", "E"};
    vector<string> rollOrder = {"R", "L"};
    bool flag = false; // Flag to indicate if a match is found

    CHECK: // Label for breaking out of nested loops
    // Check all combinations of rotations and rolls
    for (int i = 0; i <= 2; i++) { // Rotate 0 to 2 times
        for (int j = 0; j <= 2; j++) { // Roll 0 to 2 times
            for (string direction : directionOrder) { // Iterate through directions
                for (string roll : rollOrder) { // Iterate through roll directions
                    Dice tmp; // Create a temporary dice
                    tmp.nums = dice2.nums; // Copy the numbers from dice2
                    rotate(tmp, direction, i); // Rotate the temporary dice
                    roll(tmp, roll, j); // Roll the temporary dice
                    if (isEqual(tmp, dice1)) { // Check if it matches dice1
                        flag = true; // Match found
                        break CHECK; // Break out of all loops
                    }
                }
            }
        }
    }
    // Output the result based on the flag
    if (flag) {
        cout << "Yes" << endl; // If a match was found
    } else {
        cout << "No" << endl; // If no match was found
    }
    return 0;
}

