#include <iostream>
#include <sstream>
#include <vector>

int main() {
    // 1. The code starts by taking input from the user, which is split into a list of strings.
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> p;
    int num;

    // Read integers from the input
    while (iss >> num) {
        p.push_back(num);
    }

    // 2. The first element of the list is converted to an integer and assigned to x1.
    int x1 = p[0];

    // 3. The second element of the list is converted to an integer and assigned to y1.
    int y1 = p[1];

    // 4. The third element of the list is converted to an integer and assigned to x2.
    int x2 = p[2];

    // 5. The fourth element of the list is converted to an integer and assigned to y2.
    int y2 = p[3];

    // 6. The difference between x2 and x1 is calculated and assigned to DIF1.
    int DIF1 = x2 - x1;

    // 7. The difference between y2 and y1 is calculated and assigned to DIF2.
    int DIF2 = y2 - y1;

    // 8. x3 is calculated as x2 minus DIF2.
    int x3 = x2 - DIF2;

    // 9. y3 is calculated as y2 plus DIF1.
    int y3 = y2 + DIF1;

    // 10. x4 is calculated as x1 minus DIF2.
    int x4 = x1 - DIF2;

    // 11. y4 is calculated as y1 plus DIF1.
    int y4 = y1 + DIF1;

    // 12. Finally, the coordinates x3, y3, x4, and y4 are printed in a formatted string.
    std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;

    return 0;
}

// <END-OF-CODE>
