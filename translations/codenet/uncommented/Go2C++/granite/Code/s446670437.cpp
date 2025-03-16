
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Dice {
public:
    std::vector<int> nums;

    void rotate(std::string direction, int times) {
        times %= 4;
        switch (direction[0]) {
            case 'W':
                std::rotate(nums.begin(), nums.begin() + 2, nums.begin() + 5);
                break;
            case 'E':
                std::rotate(nums.rbegin(), nums.rbegin() + 2, nums.rbegin() + 5);
                break;
            case 'N':
                std::rotate(nums.begin(), nums.begin() + 1, nums.begin() + 4);
                break;
            case 'S':
                std::rotate(nums.rbegin(), nums.rbegin() + 1, nums.rbegin() + 4);
                break;
        }
    }

    void roll(std::string direction, int times) {
        times %= 4;
        switch (direction[0]) {
            case 'R':
                std::rotate(nums.begin() + 1, nums.begin() + 2, nums.begin() + 4);
                break;
            case 'L':
                std::rotate(nums.rbegin() + 1, nums.rbegin() + 2, nums.rbegin() + 4);
                break;
        }
    }

    void printStatus() {
        std::cout << "	　　　 _ _ _ _\n";
        std::cout << "	_ _ _|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	|_%3d_|_%3d_|_%3d_|_%3d_|%\n";
        std::cout << "	       |_%3d_|%\n";
    }

    int getIndex(std::vector<int> nums, int target) {
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i]) {
                index = i;
                break;
            }
        }
        return index;
    }

    bool isEqual(Dice other) {
        for (int i = 0; i < nums.size(); i++) {
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
        std::cin >> n;
        dice1.nums.push_back(n);
    }
    for (int i = 0; i < 6; i++) {
        int n;
        std::cin >> n;
        dice2.nums.push_back(n);
    }

    std::vector<std::string> directionOrder = {"N", "S", "W", "E"};
    std::vector<std::string> rollOrder = {"R", "L"};
    bool flag = false;

    CHECK:
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                for (const auto& direction : directionOrder) {
                    for (const auto& roll : rollOrder) {
                        Dice tmp = dice2;
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
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}

