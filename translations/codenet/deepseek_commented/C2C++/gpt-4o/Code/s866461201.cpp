#include <iostream>
#include <vector>

int main() {
    // Declare variables
    int n; // n: number of heights
    std::vector<int> fd(6, 0); // fd: vector to store counts
    double height; // height: variable to store each height input

    // Read the number of heights
    std::cin >> n;

    // Loop to read each height and categorize it
    while (n--) {
        std::cin >> height;
        if (height >= 185.0) fd[5]++;
        else if (height >= 180.0) fd[4]++;
        else if (height >= 175.0) fd[3]++;
        else if (height >= 170.0) fd[2]++;
        else if (height >= 165.0) fd[1]++;
        else fd[0]++;
    }

    // Loop to print the histogram
    for (int i = 0; i < 6; i++) {
        std::cout << (i + 1) << ":";
        for (int j = 0; j < fd[i]; j++)
            std::cout << '*';
        std::cout << std::endl;
    }
    return 0;
}

// <END-OF-CODE>
