#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

int main() {
    // Main function is the entry point of the program
    try {
        double input;
        cin >> input;

        // Reading a double value from the input
        double countOdd = round(input / 2);

        // Calculating the number of odd numbers up to the given input
        double result = countOdd / input;

        // Using setprecision to handle precise decimal calculations and setting the precision to 10
        cout << fixed << setprecision(10) << result << endl;

        // Printing the result
    } catch (const ios_base::failure& e) {
        cerr << e.what() << endl;
        return 0;

        // Handling input/output exceptions to ensure program termination
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 0;

        // Handling any other potential exceptions to ensure program termination
    }
    return 0;
}

// <END-OF-CODE>
