#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a Dice struct with a Numbers vector to store the numbers on the dice.
struct Dice {
    vector<int> Nums;

    // Function to rotate the dice in a given direction by a given number of times.
    void rotate(string direction, int times) {
        times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
        if (direction == "W") { // West direction rotation logic
            for (int i = 0; i < times; i++) {
                swap(Nums[0], Nums[2]);
                swap(Nums[2], Nums[5]);
                swap(Nums[5], Nums[3]);
            }
        } else if (direction == "E") { // East direction rotation logic
            for (int i = 0; i < times; i++) {
                swap(Nums[0], Nums[3]);
                swap(Nums[3], Nums[5]);
                swap(Nums[5], Nums[2]);
            }
        } else if (direction == "N") { // North direction rotation logic
            for (int i = 0; i < times; i++) {
                swap(Nums[0], Nums[4]);
                swap(Nums[4], Nums[5]);
                swap(Nums[5], Nums[1]);
            }
        } else if (direction == "S") { // South direction rotation logic
            for (int i = 0; i < times; i++) {
                swap(Nums[5], Nums[1]);
                swap(Nums[1], Nums[0]);
                swap(Nums[0], Nums[4]);
            }
        }
    }

    // Function to roll the dice in a given direction by a given number of times.
    void roll(string direction, int times) {
        times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
        if (direction == "R") { // Right direction roll logic
            for (int i = 0; i < times; i++) {
                swap(Nums[3], Nums[1]);
                swap(Nums[1], Nums[2]);
                swap(Nums[2], Nums[4]);
            }
        } else if (direction == "L") { // Left direction roll logic
            for (int i = 0; i < times; i++) {
                swap(Nums[3], Nums[4]);
                swap(Nums[4], Nums[2]);
                swap(Nums[2], Nums[1]);
            }
        }
    }

    // Function to print the current status of the dice.
    void printStatus() {
        printf("        _ _ _ _ \n");
        printf("     _ _ _|_%3d_|_ _ _ _ _ _ \n", Nums[3]);
        printf("    |_%3d_|_%3d_|_%3d_|_%3d_| \n", Nums[1], Nums[2], Nums[4], Nums[5]);
        printf("        |_%3d| \n", Nums[0]);
        cout << endl;
    }

    // Function to get the index of a target number in a given vector.
    int getIndex(int target) {
        for (int i = 0; i < Nums.size(); i++) {
            if (Nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    // Function to check if two dice have the same numbers.
    bool isEqual(Dice other) {
        for (int i = 0; i < Nums.size(); i++) {
            if (Nums[i] != other.Nums[i]) {
                return false;
            }
        }
        return true;
    }
};

// Main function to read user input and check if two dice are the same after certain rotations and rolls.
int main() {
    Dice dice1;
    Dice dice2;

    for (int i = 0; i < 6; i++) {
        int n;
        cin >> n;
        dice1.Nums.push_back(n);
    }
    for (int i = 0; i < 6; i++) {
        int n;
        cin >> n;
        dice2.Nums.push_back(n);
    }

    string directionOrder[] = {"N", "S", "W", "E"}; // Order of directions to rotate
    string rollOrder[] = {"R", "L"};             // Order of rolls
    bool flag = false;

    // Check all possible combinations of rotations and rolls to find if the dice are the same.
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (string direction : directionOrder) {
                for (string roll : rollOrder) {
                    Dice tmp = dice2;
                    tmp.rotate(direction, i);
                    tmp.roll(roll, j);
                    if (tmp.isEqual(dice1)) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) break;
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
