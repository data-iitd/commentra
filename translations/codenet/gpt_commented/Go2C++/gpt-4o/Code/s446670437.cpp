#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Dice class represents a dice with its six faces numbered.
class Dice {
public:
    vector<int> Nums; // Array to hold the numbers on the faces of the dice

    Dice() : Nums(6) {} // Constructor to initialize the dice with 6 faces

    // rotate method rotates the dice in a specified direction a certain number of times.
    void rotate(const string& direction, int times) {
        times %= 4; // Normalize the number of rotations to be within 0-3
        for (int i = 0; i < times; i++) {
            if (direction == "W") { // Rotate West
                swap(Nums[0], Nums[2]);
                swap(Nums[2], Nums[5]);
                swap(Nums[5], Nums[3]);
            } else if (direction == "E") { // Rotate East
                swap(Nums[0], Nums[3]);
                swap(Nums[3], Nums[5]);
                swap(Nums[5], Nums[2]);
            } else if (direction == "N") { // Rotate North
                swap(Nums[0], Nums[1]);
                swap(Nums[1], Nums[5]);
                swap(Nums[5], Nums[4]);
            } else if (direction == "S") { // Rotate South
                swap(Nums[5], Nums[1]);
                swap(Nums[1], Nums[0]);
                swap(Nums[0], Nums[4]);
            }
        }
    }

    // roll method rolls the dice in a specified direction a certain number of times.
    void roll(const string& direction, int times) {
        times %= 4; // Normalize the number of rolls to be within 0-3
        for (int i = 0; i < times; i++) {
            if (direction == "R") { // Roll Right
                swap(Nums[3], Nums[1]);
                swap(Nums[1], Nums[2]);
                swap(Nums[2], Nums[4]);
            } else if (direction == "L") { // Roll Left
                swap(Nums[3], Nums[4]);
                swap(Nums[4], Nums[2]);
                swap(Nums[2], Nums[1]);
            }
        }
    }

    // printStatus method prints the current status of the dice in a formatted manner.
    void printStatus() const {
        cout << "         ___\n"
             << "    ____|_" << setw(3) << Nums[0] << "_|_______\n"
             << "    |_4_|_" << setw(3) << Nums[3] << "_|_" << setw(3) << Nums[1] << "_|_" << setw(3) << Nums[2] << "_|_" << setw(3) << Nums[4] << "_|\n"
             << "        |_6_|\n\n";
    }

    // isEqual method checks if two dice are in the same state (same numbers on each face).
    bool isEqual(const Dice& other) const {
        return Nums == other.Nums; // Check if all faces match
    }
};

// main function to execute the dice comparison logic.
int main() {
    // Initialize two dice
    Dice dice1, dice2;

    // Input numbers for the first dice
    for (int i = 0; i < 6; i++) {
        cin >> dice1.Nums[i]; // Read input for each face
    }

    // Input numbers for the second dice
    for (int i = 0; i < 6; i++) {
        cin >> dice2.Nums[i]; // Read input for each face
    }

    // Define the order of directions and rolls for testing
    vector<string> directionOrder = {"N", "S", "W", "E"};
    vector<string> rollOrder = {"R", "L"};
    bool flag = false; // Flag to indicate if a match is found

    // Check all combinations of rotations and rolls
    for (int i = 0; i <= 2; i++) { // Rotate 0 to 2 times
        for (int j = 0; j <= 2; j++) { // Roll 0 to 2 times
            for (const auto& direction : directionOrder) { // Iterate through directions
                for (const auto& roll : rollOrder) { // Iterate through roll directions
                    Dice tmp = dice2; // Create a temporary dice
                    tmp.rotate(direction, i); // Rotate the temporary dice
                    tmp.roll(roll, j); // Roll the temporary dice
                    if (tmp.isEqual(dice1)) { // Check if it matches dice1
                        flag = true; // Match found
                        break; // Break out of the loop
                    }
                }
                if (flag) break; // Break if match found
            }
            if (flag) break; // Break if match found
        }
        if (flag) break; // Break if match found
    }

    // Output the result based on the flag
    if (flag) {
        cout << "Yes\n"; // If a match was found
    } else {
        cout << "No\n"; // If no match was found
    }

    return 0;
}

// <END-OF-CODE>
