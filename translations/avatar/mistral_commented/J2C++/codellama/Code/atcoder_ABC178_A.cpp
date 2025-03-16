// Including necessary C++ libraries for this program
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Creating a new Scanner object to read user input from the standard input
    Scanner scan(cin);

    // Reading an integer value from the user input
    int x = atoi(scan.next().c_str());

    // Determining a boolean value based on the condition x equals to 1
    bool bool = x == 1 ? true : false;

    // Calculating the result based on the boolean value
    int result = !bool ? 1 : 0;

    // Creating a new PrintWriter object to write the output to the standard output
    PrintWriter out(cout);

    // Writing the result to the standard output
    out.println(result);

    // Flushing the PrintWriter buffer to ensure the output is written immediately
    out.flush();

    // Closing the Scanner object to release system resources
    scan.close();

    // End of code
    return 0;
}


