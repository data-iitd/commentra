#include <iostream>
#include <vector>

using namespace std;

// Dice struct represents a dice with its six faces numbered.
struct Dice {
	vector<int> nums; // Array to hold the numbers on the faces of the dice
};

// rotate method rotates the dice in a specified direction a certain number of times.
void rotate(Dice &dice, string direction, int times) {
	times %= 4; // Normalize the number of rotations to be within 0-3
	switch (direction) {
	case "W": // Rotate West
		for (int i = 0; i < times; i++) {
			int temp = dice.nums[0];
			dice.nums[0] = dice.nums[2];
			dice.nums[2] = dice.nums[5];
			dice.nums[5] = dice.nums[3];
			dice.nums[3] = temp;
		}
	case "E": // Rotate East
		for (int i = 0; i < times; i++) {
			int temp = dice.nums[0];
			dice.nums[0] = dice.nums[3];
			dice.nums[3] = dice.nums[5];
			dice.nums[5] = dice.nums[2];
			dice.nums[2] = temp;
		}
	case "N": // Rotate North
		for (int i = 0; i < times; i++) {
			int temp = dice.nums[0];
			dice.nums[0] = dice.nums[4];
			dice.nums[4] = dice.nums[5];
			dice.nums[5] = dice.nums[1];
			dice.nums[1] = temp;
		}
	case "S": // Rotate South
		for (int i = 0; i < times; i++) {
			int temp = dice.nums[5];
			dice.nums[5] = dice.nums[1];
			dice.nums[1] = dice.nums[0];
			dice.nums[0] = dice.nums[4];
			dice.nums[4] = temp;
		}
	}
}

// roll method rolls the dice in a specified direction a certain number of times.
void roll(Dice &dice, string direction, int times) {
	times %= 4; // Normalize the number of rolls to be within 0-3
	switch (direction) {
	case "R": // Roll Right
		for (int i = 0; i < times; i++) {
			int temp = dice.nums[3];
			dice.nums[3] = dice.nums[1];
			dice.nums[1] = dice.nums[2];
			dice.nums[2] = dice.nums[4];
			dice.nums[4] = temp;
		}
	case "L": // Roll Left
		for (int i = 0; i < times; i++) {
			int temp = dice.nums[3];
			dice.nums[3] = dice.nums[4];
			dice.nums[4] = dice.nums[2];
			dice.nums[2] = dice.nums[1];
			dice.nums[1] = temp;
		}
	}
}

// printStatus method prints the current status of the dice in a formatted manner.
void printStatus(Dice &dice) {
	cout << "	　　　 _ _ _ _\n";
	cout << "     _ _ _|_%3d_|_ _ _ _ _ _\n";
	cout << "    |_%3d_|_%3d_|_%3d_|_%3d_|\n";
	cout << " 　       |_%3d_|\n";
	cout << endl;
}

// getIndex function returns the index of a target number in the nums slice.
int getIndex(vector<int> nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == target) {
			return i; // Found the target, return its index
		}
	}
	return -1; // Target not found, return -1
}

// isEqual method checks if two dice are in the same state (same numbers on each face).
bool isEqual(Dice &dice1, Dice &dice2) {
	for (int i = 0; i < dice1.nums.size(); i++) {
		if (dice1.nums[i]!= dice2.nums[i]) {
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
	string directionOrder[] = {"N", "S", "W", "E"};
	string rollOrder[] = {"R", "L"};
	bool flag = false; // Flag to indicate if a match is found

	// Check all combinations of rotations and rolls
	for (int i = 0; i <= 2; i++) { // Rotate 0 to 2 times
		for (int j = 0; j <= 2; j++) { // Roll 0 to 2 times
			for (int k = 0; k < 4; k++) { // Iterate through directions
				string direction = directionOrder[k];
				for (int l = 0; l < 2; l++) { // Iterate through roll directions
					string roll = rollOrder[l];
					Dice tmp;
					tmp.nums = dice2.nums; // Copy the numbers from dice2
					rotate(tmp, direction, i); // Rotate the temporary dice
					roll(tmp, roll, j); // Roll the temporary dice
					if (isEqual(tmp, dice1)) { // Check if it matches dice1
						flag = true; // Match found
						break;
					}
				}
				if (flag) {
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			break;
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

