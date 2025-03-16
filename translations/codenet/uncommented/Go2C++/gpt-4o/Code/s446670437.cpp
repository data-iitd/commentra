#include <iostream>
#include <vector>

class Dice {
public:
    std::vector<int> nums;

    Dice() : nums(6) {}

    void rotate(const std::string& direction, int times) {
        times %= 4;
        for (int i = 0; i < times; i++) {
            if (direction == "W") {
                std::swap(nums[0], nums[2]);
                std::swap(nums[2], nums[5]);
                std::swap(nums[5], nums[3]);
            } else if (direction == "E") {
                std::swap(nums[0], nums[3]);
                std::swap(nums[3], nums[5]);
                std::swap(nums[5], nums[2]);
            } else if (direction == "N") {
                std::swap(nums[0], nums[1]);
                std::swap(nums[1], nums[5]);
                std::swap(nums[5], nums[4]);
            } else if (direction == "S") {
                std::swap(nums[5], nums[1]);
                std::swap(nums[1], nums[0]);
                std::swap(nums[0], nums[4]);
            }
        }
    }

    void roll(const std::string& direction, int times) {
        times %= 4;
        for (int i = 0; i < times; i++) {
            if (direction == "R") {
                std::swap(nums[3], nums[1]);
                std::swap(nums[1], nums[2]);
                std::swap(nums[2], nums[4]);
            } else if (direction == "L") {
                std::swap(nums[3], nums[4]);
                std::swap(nums[4], nums[1]);
                std::swap(nums[1], nums[2]);
            }
        }
    }

    void printStatus() const {
        std::cout << "         ___\n"
                     "    ____|_" << nums[0] << "_|_______\n"
                     "    |_4_|_" << nums[3] << "_|_" << nums[1] << "_|_" << nums[2] << "_|_" << nums[4] << "_|\n"
                     "        |_6_|\n\n";
    }

    bool isEqual(const Dice& other) const {
        return nums == other.nums;
    }
};

int main() {
    Dice dice1, dice2;

    for (int i = 0; i < 6; i++) {
        std::cin >> dice1.nums[i];
    }
    for (int i = 0; i < 6; i++) {
        std::cin >> dice2.nums[i];
    }

    std::string directionOrder[] = {"N", "S", "W", "E"};
    std::string rollOrder[] = {"R", "L"};
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
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}

// <END-OF-CODE>
