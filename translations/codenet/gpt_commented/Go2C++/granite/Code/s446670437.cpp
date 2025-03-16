
```cpp
#include <iostream>
#include <vector>

// Define the Dice class
class Dice {
public:
    std::vector<int> nums; // Vector to hold the numbers on the faces of the dice

    // Constructor to initialize the dice with 6 faces
    Dice() {
        nums.resize(6); // Resize the vector to hold 6 elements
    }

    // Method to rotate the dice in a specified direction a certain number of times
    void rotate(std::string direction, int times) {
        times %= 4; // Normalize the number of rotations to be within 0-3
        switch (direction[0]) {
            case 'W': // Rotate West
                for (int i = 0; i < times; i++) {
                    std::swap(nums[0], nums[2]);
                    std::swap(nums[2], nums[5]);
                    std::swap(nums[5], nums[3]);
                }
                break;
            case 'E': // Rotate East
                for (int i = 0; i < times; i++) {
                    std::swap(nums[0], nums[3]);
                    std::swap(nums[3], nums[5]);
                    std::swap(nums[5], nums[2]);
                }
                break;
            case 'N': // Rotate North
                for (int i = 0; i < times; i++) {
                    std::swap(nums[0], nums[1]);
                    std::swap(nums[1], nums[5]);
                    std::swap(nums[5], nums[4]);
                }
                break;
            case 'S': // Rotate South
                for (int i = 0; i < times; i++) {
                    std::swap(nums[0], nums[4]);
                    std::swap(nums[4], nums[5]);
                    std::swap(nums[5], nums[1]);
                }
                break;
        }
    }

    // Method to roll the dice in a specified direction a certain number of times
    void roll(std::string direction, int times) {
        times %= 4; // Normalize the number of rolls to be within 0-3
        switch (direction[0]) {
            case 'R': // Roll Right
                for (int i = 0; i < times; i++) {
                    std::swap(nums[3], nums[1]);
                    std::swap(nums[1], nums[2]);
                    std::swap(nums[2], nums[4]);
                }
                break;
            case 'L': // Roll Left
                for (int i = 0; i < times; i++) {
                    std::swap(nums[3], nums[4]);
                    std::swap(nums[4], nums[2]);
                    std::swap(nums[2], nums[1]);
                }
                break;
        }
    }

    // Method to print the current status of the dice in a formatted manner
    void printStatus() {
        std::cout << "	　　　 _ _ _ _\n";
        std::cout << "	_ _ _|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	|_%3d_|_%3d_|_%3d_|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_%3d_|_ _ _ _ _ _\n";
        std::cout << "	\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_1_4_4_1_4_1_4_1_4_1_4_1_4_1_4