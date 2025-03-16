
#include <iostream>
#include <vector>

using namespace std;

// Dice represents a die with six faces
class Dice {
public:
	vector<int> Nums;
	Dice() {
		Nums.resize(6);
	}
};

// rotate rotates the die in a specified direction a given number of times
void rotate(Dice &d, string direction, int times) {
	times %= 4; // Normalize the number of rotations to 4 or less
	switch (direction) {
	case "W":
		for (int i = 0; i < times; i++) {
			int tmp = d.Nums[0];
			d.Nums[0] = d.Nums[2];
			d.Nums[2] = d.Nums[5];
			d.Nums[5] = d.Nums[3];
			d.Nums[3] = tmp;
		}
		break;
	case "E":
		for (int i = 0; i < times; i++) {
			int tmp = d.Nums[0];
			d.Nums[0] = d.Nums[3];
			d.Nums[3] = d.Nums[5];
			d.Nums[5] = d.Nums[2];
			d.Nums[2] = tmp;
		}
		break;
	case "N":
		for (int i = 0; i < times; i++) {
			int tmp = d.Nums[0];
			d.Nums[0] = d.Nums[4];
			d.Nums[4] = d.Nums[5];
			d.Nums[5] = d.Nums[1];
			d.Nums[1] = tmp;
		}
		break;
	case "S":
		for (int i = 0; i < times; i++) {
			int tmp = d.Nums[5];
			d.Nums[5] = d.Nums[1];
			d.Nums[1] = d.Nums[0];
			d.Nums[0] = d.Nums[4];
			d.Nums[4] = tmp;
		}
		break;
	}
}

// roll rolls the die in a specified direction a given number of times
void roll(Dice &d, string direction, int times) {
	times %= 4; // Normalize the number of rolls to 4 or less
	switch (direction) {
	case "R":
		for (int i = 0; i < times; i++) {
			int tmp = d.Nums[3];
			d.Nums[3] = d.Nums[1];
			d.Nums[1] = d.Nums[2];
			d.Nums[2] = d.Nums[4];
			d.Nums[4] = tmp;
		}
		break;
	case "L":
		for (int i = 0; i < times; i++) {
			int tmp = d.Nums[3];
			d.Nums[3] = d.Nums[4];
			d.Nums[4] = d.Nums[2];
			d.Nums[2] = d.Nums[1];
			d.Nums[1] = tmp;
		}
		break;
	}
}

// printStatus prints the current status of the die in a formatted string
void printStatus(Dice &d) {
	cout << "	　　　 _ _ _ _\n";
	cout << "     _ _ _|_%3d_|_ _ _ _ _ _\n";
	cout << "    |_%3d_|_%3d_|_%3d_|_%3d_|  \n";
	cout << " 　       |_%3d_|\n";
	cout << endl;
}

// getIndex returns the index of the target number in the slice
int getIndex(vector<int> nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		if (target == nums[i]) {
			return i;
		}
	}
	return -1;
}

// isEqual checks if two Dice objects have the same faces
bool isEqual(Dice &d, Dice &other) {
	for (int i = 0; i < d.Nums.size(); i++) {
		if (d.Nums[i]!= other.Nums[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	Dice dice1;
	Dice dice2;
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		dice1.Nums[i] = n;
	}
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		dice2.Nums[i] = n;
	}

	string directionOrder[] = {"N", "S", "W", "E"};
	string rollOrder[] = {"R", "L"};
	bool flag = false;

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			for (int k = 0; k < 4; k++) {
				Dice tmp = dice2;
				rotate(tmp, directionOrder[k], i);
				roll(tmp, rollOrder[j], j);
				if (isEqual(tmp, dice1)) {
					flag = true;
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
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}

