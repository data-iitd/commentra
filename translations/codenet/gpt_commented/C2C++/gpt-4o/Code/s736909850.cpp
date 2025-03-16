#include <iostream>

int main() {
    // Declare variables to hold the number of sheep and wolves
    int sheep;
    int wolf;

    // Read the number of sheep and wolves from user input
    std::cin >> sheep >> wolf;

    // Check if the number of wolves is greater than or equal to the number of sheep
    if (wolf >= sheep) {
        // If there are more wolves than sheep, it's unsafe
        std::cout << "unsafe" << std::endl;
    } else {
        // If there are fewer wolves than sheep, it's safe
        std::cout << "safe" << std::endl;
    }

    // Return 0 to indicate successful execution of the program
    return 0;
}

// <END-OF-CODE>
