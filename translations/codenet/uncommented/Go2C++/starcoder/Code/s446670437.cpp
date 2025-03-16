#include <iostream>
#include <vector>

using namespace std;

class Dice {
public:
	vector<int> nums;
	Dice() {
		nums.resize(6);
	}
	void rotate(string direction, int times) {
		times %= 4;
		switch (direction) {
		case "W":
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[2];
				nums[2] = nums[5];
				nums[5] = nums[3];
				nums[3] = tmp;
			}
			break;
		case "E":
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[3];
				nums[3] = nums[5];
				nums[5] = nums[2];
				nums[2] = tmp;
			}
			break;
		case "N":
			for (int i = 0; i < times; i++) {
				int tmp = nums[0];
				nums[0] = nums[4];
				nums[4] = nums[5];
				nums[5] = nums[1];
				nums[1] = tmp;
			}
			break;
		case "S":
			for (int i = 0; i < times; i++) {
				int tmp = nums[5];
				nums[5] = nums[1];
				nums[1] = nums[0];
				nums[0] = nums[4];
				nums[4] = tmp;
			}
			break;
		}
	}
	void roll(string direction, int times) {
		times %= 4;
		switch (direction) {
		case "R":
			for (int i = 0; i < times; i++) {
				int tmp = nums[3];
				nums[3] = nums[1];
				nums[1] = nums[2];
				nums[2] = nums[4];
				nums[4] = tmp;
			}
			break;
		case "L":
			for (int i = 0; i < times; i++) {
				int tmp = nums[3];
				nums[3] = nums[4];
				nums[4] = nums[2];
				nums[2] = nums[1];
				nums[1] = tmp;
			}
			break;
		}
	}
	void printStatus() {
		cout << "	　　　 _ _ _ _\n";
		cout << "     _ _ _|_%3d_|_ _ _ _ _ _\n";
		cout << "    |_%3d_|_%3d_|_%3d_|_%3d_|\n";
		cout << " 　       |_%3d_|\n";
		cout << endl;
	}
	bool isEqual(Dice other) {
		for (int i = 0; i < 6; i++) {
			if (nums[i]!= other.nums[i]) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	Dice dice1;
	Dice dice2;
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		dice1.nums[i] = n;
	}
	for (int i = 0; i < 6; i++) {
		int n;
		cin >> n;
		dice2.nums[i] = n;
	}

	string directionOrder[] = {"N", "S", "W", "E"};
	string rollOrder[] = {"R", "L"};
	bool flag = false;

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			for (int k = 0; k < 4; k++) {
				string direction = directionOrder[k];
				for (int l = 0; l < 2; l++) {
					string roll = rollOrder[l];
					Dice tmp = dice2;
					tmp.rotate(direction, i);
					tmp.roll(roll, j);
					if (tmp.isEqual(dice1)) {
						flag = true;
						break;
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
}

