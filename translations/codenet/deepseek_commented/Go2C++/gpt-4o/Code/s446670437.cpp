#include <iostream>
#include <vector>
#include <algorithm>

class Dice {
public:
    std::vector<int> nums; // Vector of integers representing the faces of the die

    Dice() : nums(6) {}

    // Rotate the die in a specified direction a given number of times
    void rotate(const std::string& direction, int times) {
        times %= 4; // Normalize the number of rotations to 4 or less
        for (int i = 0; i < times; ++i) {
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

    // Roll the die in a specified direction a given number of times
    void roll(const std::string& direction, int times) {
        times %= 4; // Normalize the number of rolls to 4 or less
        for (int i = 0; i < times; ++i) {
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

    // Print the current status of the die in a formatted string
    void printStatus() const {
        std::cout << "         _ _ _ _\n"
                     "     _ _ _|_" << nums[0] << "_|_ _ _ _ _ _\n"
                     "    |_" << nums[4] << "_|_" << nums[1] << "_|_" << nums[2] << "_|_" << nums[3] << "_|\n"
                     "          |_" << nums[5] << "_|\n\n";
    }

    // Check if two Dice objects have the same faces
    bool isEqual(const Dice& other) const {
        return nums == other.nums;
    }
};

int main() {
    Dice dice1, dice2;

    for (int i = 0; i < 6; ++i) {
        std::cin >> dice1.nums[i];
    }
    for (int i = 0; i < 6; ++i) {
        std::cin >> dice2.nums[i];
    }

    std::vector<std::string> directionOrder = {"N", "S", "W", "E"};
    std::vector<std::string> rollOrder = {"R", "L"};
    bool flag = false;

    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            for (const auto& direction : directionOrder) {
                for (const auto& roll : rollOrder) {
                    Dice tmp = dice2; // Create a copy of dice2
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
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}

// <END-OF-CODE>
