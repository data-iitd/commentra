
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Create a BufferedReader to read input from the user
    string line;
    getline(cin, line);
    
    // Split the input line into an array of strings
    string list [ ] = line.split(" ");
    
    // Parse the first three elements of the array as integers
    int x = stoi(list[0]);
    int a = stoi(list[1]);
    int y = stoi(list[2]);
    
    // Initialize a variable to store the result
    string h = "NO";
    
    // Check if any of the integers is either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // Check if the sum of the integers is 17
        if (x + y + a == 17) {
            h = "YES";
        }
    }
    
    // Print the result
    cout << h << endl;
    
    return 0;
}

