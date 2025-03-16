
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int firstline;
    cin >> firstline;
    int total = 0;
    vector<string> memory;
    for (int x = 0; x < firstline; x++) {
        int A, G;
        cin >> A >> G;
        if (total + A <= 500) {
            total += A;
            memory.push_back("A");
        } else {
            total -= G;
            memory.push_back("G");
        }
    }
    string output = "";
    for (int x = 0; x < memory.size(); x++) {
        output += memory[x];
    }
    cout << output << endl;
    return 0;
}

