#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input_string;
    getline(cin, input_string);
    istringstream iss(input_string);
    string str;
    int result = 0;
    while (iss >> str) {
        result++;
        if (str == "0") break;
    }
    cout << result << endl;
    return 0;
}

