#include <iostream>
#include <iomanip>

int main() {
    int a, b, c, d, e, f;
    double x, y;

    // Reading the input values
    // The code uses a while loop to read six integers from the standard input until the end of the input is reached.
    while (std::cin >> a >> b >> c >> d >> e >> f) {
        
        // Calculating the values of x and y
        // The code calculates the values of x and y using the formula derived from the given equations.
        y = static_cast<double>(c * d - f * a) / (b * d - e * a);
        x = static_cast<double>(c * e - f * b) / (a * e - d * b);
        
        // Adjusting the values of x and y if they are very close to zero
        // The code checks if the values of x and y are very close to zero and adjusts them to exactly zero if they are.
        if (y <= 0 && y > -0.0005) y = 0;
        if (x <= 0 && x > -0.0005) x = 0;
        
        // Printing the results
        // The code prints the calculated values of x and y with three decimal places.
        std::cout << std::fixed << std::setprecision(3) << x << " " << y << std::endl;
    }
    return 0;
}

// <END-OF-CODE>
