
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dice {
public:
    vector<int> Nums;

    Dice() {
        Nums = vector<int>(6);
    }

    void rotate(string direction, int times) {
        times %= 4;
        switch (direction[0]) {
        case 'W':
            for (int i = 0; i < times; i++) {
                Nums[0], Nums[2], Nums[5], Nums[3] = Nums[2], Nums[5], Nums[3], Nums[0];
            }
            break;
        case 'E':
            for (int i = 0; i < times; i++) {
                Nums[0], Nums[2], Nums[5], Nums[3] = Nums[3], Nums[0], Nums[2], Nums[5];
            }
            break;
        case 'N':
            for (int i = 0; i < times; i++) {
                Nums[0], Nums[4], Nums[5], Nums[1] = Nums[1], Nums[0], Nums[4], Nums[5];
            }
            break;
        case 'S':
            for (int i = 0; i < times; i++) {
                Nums[5], Nums[1], Nums[0], Nums[4] = Nums[1], Nums[0], Nums[4], Nums[5];
            }
            break;
        }
    }

    void roll(string direction, int times) {
        times %= 4;
        switch (direction[0]) {
        case 'R':
            for (int i = 0; i < times; i++) {
                Nums[3], Nums[1], Nums[2], Nums[4] = Nums[1], Nums[2], Nums[4], Nums[3];
            }
            break;
        case 'L':
            for (int i = 0; i < times; i++) {
                Nums[3], Nums[1], Nums[2], Nums[4] = Nums[4], Nums[3], Nums[1], Nums[2];
            }
            break;
        }
    }

    void printStatus() {
        string status =
            "     _ _ _ _\n"
            "     _ %3d_|_ _ _ _ _ _\n"
            "    |_%3d_|_%3d_|_%3d_|_%3d_|\n"
            " 　       |_%3d_|\n";
        printf(status.c_str(), Nums[0], Nums[3], Nums[1], Nums[2], Nums[4], Nums[5]);
        printf("\n");
    }

    int getIndex(vector<int> nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i]) {
                return i;
            }
        }
        return -1;
    }

    bool isEqual(Dice other) {
        for (int i = 0; i < Nums.size(); i++) {
            if (Nums[i] != other.Nums[i]) {
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
        dice1.Nums[i] = n;
    }
    for (int i = 0; i < 6; i++) {
        int n;
        cin >> n;
        dice2.Nums[i] = n;
    }

    vector<string> directionOrder = {"N", "S", "W", "E"};
    vector<string> rollOrder = {"R", "L"};
    bool flag = false;

    CHECK:
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            for (string direction : directionOrder) {
                for (string roll : rollOrder) {
                    Dice tmp;
                    tmp.Nums = vector<int>(dice2.Nums);
                    tmp.rotate(direction, i);
                    tmp.roll(roll, j);
                    if (tmp.isEqual(dice1)) {
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
}

