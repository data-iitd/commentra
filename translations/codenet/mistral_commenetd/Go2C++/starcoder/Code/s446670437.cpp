#include <iostream>
#include <vector>

using namespace std;

// Define a Dice struct with a Numbers vector to store the numbers on the dice.
struct Dice {
	vector<int> Nums;
};

// Function to rotate the dice in a given direction by a given number of times.
void rotate(Dice &d, string direction, int times) {
	times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
	switch (direction[0]) {
	case 'W': // West direction rotation logic
		for (int i = 0; i < times; i++) {
			int temp = d.Nums[0];
			d.Nums[0] = d.Nums[2];
			d.Nums[2] = d.Nums[5];
			d.Nums[5] = d.Nums[3];
			d.Nums[3] = temp;
		}
	case 'E': // East direction rotation logic
		for (int i = 0; i < times; i++) {
			int temp = d.Nums[0];
			d.Nums[0] = d.Nums[3];
			d.Nums[3] = d.Nums[5];
			d.Nums[5] = d.Nums[2];
			d.Nums[2] = temp;
		}
	case 'N': // North direction rotation logic
		for (int i = 0; i < times; i++) {
			int temp = d.Nums[0];
			d.Nums[0] = d.Nums[4];
			d.Nums[4] = d.Nums[5];
			d.Nums[5] = d.Nums[1];
			d.Nums[1] = temp;
		}
	case 'S': // South direction rotation logic
		for (int i = 0; i < times; i++) {
			int temp = d.Nums[5];
			d.Nums[5] = d.Nums[1];
			d.Nums[1] = d.Nums[0];
			d.Nums[0] = d.Nums[4];
			d.Nums[4] = temp;
		}
	}
}

// Function to roll the dice in a given direction by a given number of times.
void roll(Dice &d, string direction, int times) {
	times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
	switch (direction[0]) {
	case 'R': // Right direction roll logic
		for (int i = 0; i < times; i++) {
			int temp = d.Nums[3];
			d.Nums[3] = d.Nums[1];
			d.Nums[1] = d.Nums[2];
			d.Nums[2] = d.Nums[4];
			d.Nums[4] = temp;
		}
	case 'L': // Left direction roll logic
		for (int i = 0; i < times; i++) {
			int temp = d.Nums[3];
			d.Nums[3] = d.Nums[4];
			d.Nums[4] = d.Nums[2];
			d.Nums[2] = d.Nums[1];
			d.Nums[1] = temp;
		}
	}
}

// Function to print the current status of the dice.
void printStatus(Dice &d) {
	cout << "	　　　 _ _ _ _\n"
		 << "     _ _ _|_%3d_|_ _ _ _ _ _\n"
		 << "    |_%3d_|_%3d_|_%3d_|_%3d_|\n"
		 << " 　       |_%3d_|\n"
		 << endl;
}

// Function to get the index of a target number in a given vector.
int getIndex(vector<int> nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		if (target == nums[i]) {
			return i;
		}
	}
	return -1;
}

// Function to check if two dice have the same numbers.
bool isEqual(Dice &d, Dice &other) {
	for (int i = 0; i < d.Nums.size(); i++) {
		if (d.Nums[i]!= other.Nums[i]) {
			return false;
		}
	}
	return true;
}

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
	string rollOrder[] = {"R", "L"};                 // Order of rolls
	bool flag = false;

	// Check all possible combinations of rotations and rolls to find if the dice are the same.
	CHECK:
		for (int i = 0; i <= 2; i++) {
			for (int j = 0; j <= 2; j++) {
				for (int k = 0; k < 4; k++) {
					string direction = directionOrder[k];
					for (int l = 0; l < 2; l++) {
						string roll = rollOrder[l];
						Dice tmp;
						tmp.Nums = dice2.Nums;
						rotate(tmp, direction, i);
						roll(tmp, roll, j);
						if (isEqual(dice1, tmp)) {
							flag = true;
							break CHECK;
						}
					}
				}
			}
		}
	if (flag) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

