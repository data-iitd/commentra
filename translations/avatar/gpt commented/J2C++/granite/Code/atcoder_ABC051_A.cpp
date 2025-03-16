
#include <iostream> // Importingiostream for input/output operations
#include <string> // Importing string for string manipulation
#include <sstream> // Importing stringstream for string stream operations

using namespace std;

int main() {
    // Creating a stringstream to read input from the console
    stringstream ss;
    
    // Reading a line of input from the user
    string a;
    getline(cin, a);
    
    // Replacing commas in the input string with spaces and storing the result in a stringstream
    ss << a.substr(0, a.find(",")) << " ";
    
    // Reading the remaining part of the input string and appending it to the stringstream
    string b = a.substr(a.find(",") + 1);
    ss << b;
    
    // Printing the modified string to the console
    cout << ss.str() << endl;
    
    return 0;
}

