#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dice {
public:
    vector<int> Nums;

    Dice(vector<int> nums) : Nums(nums) {}

    void rotate(string direction, int times) {
        times %= 4;
        if (direction == "W") {
            for (int i = 0; i < times; i++) {
                swap(Nums[0], Nums[2]);
                swap(Nums[2], Nums[5]);
                swap(Nums[5], Nums[3]);
            }
        } else if (direction == "E") {
            for (int i = 0; i < times; i++) {
                swap(Nums[0], Nums[3]);
                swap(Nums[3], Nums[5]);
                swap(Nums[5], Nums[2]);
            }
        } else if (direction == "N") {
            for (int i = 0; i < times; i++) {
                swap(Nums[0], Nums[4]);
                swap(Nums[4], Nums[5]);
                swap(Nums[5], Nums[1]);
            }
        } else if (direction == "S") {
            for (int i = 0; i < times; i++) {
                swap(Nums[5], Nums[1]);
                swap(Nums[1], Nums[0]);
                swap(Nums[0], Nums[4]);
            }
        }
    }

    void roll(string direction, int times) {
        times %= 4;
        if (direction == "R") {
            for (int i = 0; i < times; i++) {
                swap(Nums[3], Nums[1]);
                swap(Nums[1], Nums[2]);
                swap(Nums[2], Nums[4]);
            }
        } else if (direction == "L") {
            for (int i = 0; i < times; i++) {
                swap(Nums[3], Nums[4]);
                swap(Nums[4], Nums[2]);
                swap(Nums[2], Nums[1]);
            }
        }
    }

    void printStatus() {
        cout << "	　　　 _ _ _ _" << endl;
        cout << "     _ _ _|_" << Nums[0] << "_|_ _ _ _ _ _" << endl;
        cout << "    |_" << Nums[3] << "_|_" << Nums[1] << "_|_" << Nums[2] << "_|_" << Nums[4] << "_|" << endl;
        cout << " 　       |_" << Nums[5] << "|" << endl;
    }

    bool isEqual(Dice other) {
        for (int i = 0; i < 6; i++) {
            if (Nums[i] != other.Nums[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> dice1Nums(6);
    vector<int> dice2Nums(6);

    for (int i = 0; i < 6; i++) {
        cin >> dice1Nums[i];
    }

    for (int i = 0; i < 6; i++) {
        cin >> dice2Nums[i];
    }

    Dice dice1(dice1Nums);
    Dice dice2(dice2Nums);

    string directionOrder[] = {"N", "S", "W", "E"};
    string rollOrder[] = {"R", "L"};
    bool flag = false;

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
