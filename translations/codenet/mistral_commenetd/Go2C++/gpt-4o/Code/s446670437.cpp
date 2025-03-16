#include <iostream>
#include <vector>
#include <iomanip>

class Dice {
public:
    std::vector<int> Nums;

    Dice() : Nums(6) {}

    void rotate(const std::string& direction, int times) {
        times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
        for (int i = 0; i < times; i++) {
            if (direction == "W") { // West direction rotation logic
                std::swap(Nums[0], Nums[2]);
                std::swap(Nums[2], Nums[5]);
                std::swap(Nums[5], Nums[3]);
            } else if (direction == "E") { // East direction rotation logic
                std::swap(Nums[0], Nums[3]);
                std::swap(Nums[3], Nums[5]);
                std::swap(Nums[5], Nums[2]);
            } else if (direction == "N") { // North direction rotation logic
                std::swap(Nums[0], Nums[4]);
                std::swap(Nums[4], Nums[5]);
                std::swap(Nums[5], Nums[1]);
            } else if (direction == "S") { // South direction rotation logic
                std::swap(Nums[5], Nums[1]);
                std::swap(Nums[1], Nums[0]);
                std::swap(Nums[0], Nums[4]);
            }
        }
    }

    void roll(const std::string& direction, int times) {
        times %= 4; // Ensure times is less than or equal to 3 to avoid index out of bounds error.
        for (int i = 0; i < times; i++) {
            if (direction == "R") { // Right direction roll logic
                std::swap(Nums[3], Nums[1]);
                std::swap(Nums[1], Nums[2]);
                std::swap(Nums[2], Nums[4]);
            } else if (direction == "L") { // Left direction roll logic
                std::swap(Nums[3], Nums[4]);
                std::swap(Nums[4], Nums[2]);
                std::swap(Nums[2], Nums[1]);
            }
        }
    }

    void printStatus() const {
        std::cout << "        _ _ _ _\n"
                     "     _ _ _|_" << std::setw(3) << Nums[0] << "|_ _ _ _ _ _\n"
                     "    |_" << std::setw(3) << Nums[3] << "|_" << std::setw(3) << Nums[1] << "|_" << std::setw(3) << Nums[2] << "|_" << std::setw(3) << Nums[4] << "_|\n"
                     "            |_" << std::setw(3) << Nums[5] << "_|\n";
    }

    bool isEqual(const Dice& other) const {
        return Nums == other.Nums;
    }
};

int main() {
    Dice dice1, dice2;

    for (int i = 0; i < 6; i++) {
        std::cin >> dice1.Nums[i];
    }
    for (int i = 0; i < 6; i++) {
        std::cin >> dice2.Nums[i];
    }

    std::vector<std::string> directionOrder = {"N", "S", "W", "E"}; // Order of directions to rotate
    std::vector<std::string> rollOrder = {"R", "L"};             // Order of rolls
    bool flag = false;

    // Check all possible combinations of rotations and rolls to find if the dice are the same.
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
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
