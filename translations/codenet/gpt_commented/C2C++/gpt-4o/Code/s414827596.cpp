#include <iostream>
#include <iomanip>

int main() {
    // Declare integer variables for input coefficients
    int a, b, c, d, e, f;
    // Declare double variables for the results of the equations
    double x, y;

    // Continuously read input until EOF (End of File) is reached
    while (std::cin >> a >> b >> c >> d >> e >> f) {
        // Calculate the value of y using the given formula
        y = static_cast<double>(c * d - f * a) / (b * d - e * a);
        // Calculate the value of x using the given formula
        x = static_cast<double>(c * e - f * b) / (a * e - d * b);
        
        // Adjust y to 0 if it is a small negative number close to zero
        if (y <= 0 && y > -0.0005) y = 0;
        // Adjust x to 0 if it is a small negative number close to zero
        if (x <= 0 && x > -0.0005) x = 0;

        // Print the results x and y formatted to three decimal places
        std::cout << std::fixed << std::setprecision(3) << x << " " << y << std::endl;
    }
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
