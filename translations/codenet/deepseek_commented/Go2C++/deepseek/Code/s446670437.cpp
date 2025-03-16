#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dice {
public:
    vector<int> Nums;

    Dice() : Nums(6, 0) {}

    void rotate(const string& direction, int times) {
        times %= 4; // Normalize the number of rotations to 4 or less
        for (int i = 0; i < times; ++i) {
            if (direction == "W") {
                swap(Nums[0], Nums[2]);
                swap(Nums[2], Nums[5]);
                swap(Nums[5], Nums[3]);
            } else if (direction == "E") {
                swap(Nums[0], Nums[3]);
                swap(Nums[3], Nums[5]);
                swap(Nums[5], Nums[2]);
            } else if (direction == "N") {
                swap(Nums[0], Nums[1]);
                swap(Nums[1], Nums[5]);
                swap(Nums[5], Nums[4]);
            } else if (direction == "S") {
                swap(Nums[5], Nums[4]);
                swap(Nums[4], Nums[0]);
                swap(Nums[0], Nums[1]);
            }
        }
    }

    void roll(const string& direction, int times) {
        times %= 4; // Normalize the number of rolls to 4 or less
        for (int i = 0; i < times; ++i) {
            if (direction == "R") {
                swap(Nums[3], Nums[1]);
                swap(Nums[1], Nums[2]);
                swap(Nums[2], Nums[4]);
            } else if (direction == "L") {
                swap(Nums[3], Nums[4]);
                swap(Nums[4], Nums[2]);
                swap(Nums[2], Nums[1]);
            }
        }
    }

    void printStatus() const {
        cout << "        _ _ _ _" << endl;
        cout << "    _ _ _|_" << Nums[0] << "_|_ _ _ _ _ _" << endl;
        cout << "   |_" << Nums[3] << "_|_" << Nums[1] << "_|_" << Nums[2] << "_|_" << Nums[4] << "_|" << endl;
        cout << "        |_" << Nums[5] << "|" << endl;
    }

    int getIndex(const vector<int>& nums, int target) const {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    bool isEqual(const Dice& other) const {
        for (int i = 0; i < 6; ++i) {
            if (Nums[i] != other.Nums[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Dice dice1, dice2;

    for (int i = 0; i < 6; ++i) {
        int n;
        cin >> n;
        dice1.Nums[i] = n;
    }
    for (int i = 0; i < 6; ++i) {
        int n;
        cin >> n;
        dice2.Nums[i] = n;
    }

    const vector<string> directionOrder = {"N", "S", "W", "E"};
    const vector<string> rollOrder = {"R", "L"};
    bool flag = false;

    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            for (const auto& direction : directionOrder) {
                for (const auto& roll : rollOrder) {
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

