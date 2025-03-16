#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <cmath>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
    try
    {
        // Read a line of input and parse it as a double
        string input;
        getline(cin, input);
        double input_double = stod(input);

        // Calculate the count of odd numbers based on the input
        double count_odd = round(input_double / 2);

        // Create a stringstream to hold the result of the division
        stringstream result_stream;
        result_stream << fixed << setprecision(10) << count_odd / input_double;

        // Print the result to the console
        cout << result_stream.str() << endl;
    }
    catch (const invalid_argument& e)
    {
        // Handle input/output exceptions and number format exceptions
        cerr << e.what() << endl;
        return 0;
    }
    catch (const exception& e)
    {
        // Handle any other exceptions that may occur
        cerr << e.what() << endl;
        return 0;
    }
    return 0;
}

