#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    try {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(cin);

        // Reading a line of input from the console and splitting it into an array of strings using space as delimiter
        vector<string> x = sc.nextLine().trim().split(" ");

        // Parsing the first and second elements of the input array into integers 'a' and 'b' respectively
        int a = stoi(x[0]);
        int b = stoi(x[1]);

        // Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
        int c = a - b * 2;

        // If the value of 'c' is negative, set it to zero
        if (c < 0) {
            c = 0;
        }

        // Print the value of 'c' to the console
        cout << c << endl;
    } catch (exception &e) {
        // Handling any exceptions that might occur during the execution of the program
    }
    return 0;
}

