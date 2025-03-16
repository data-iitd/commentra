// Include the iostream library for input and output
#include <iostream>

int main() {
    // Declare four variables of type int to store the x and y coordinates of two points
    int x1, y1, x2, y2;

    // Use std::cin to read the values of x1, y1, x2, and y2 from the standard input
    std::cin >> x1 >> y1 >> x2 >> y2;

    // Calculate the differences between the x and y coordinates of the second point and the first point
    int a = x2 - x1;
    int b = y2 - y1;

    // Calculate the new x and y coordinates of the first point and the second point based on the values of a and b
    int x3 = x2 - b;
    int y3 = y2 + a;
    int x4 = x1 - b;
    int y4 = y1 + a;

    // Print the new x and y coordinates of the first and second points
    std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;

    return 0;
}

// <END-OF-CODE>
