
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Take input from the user and split it using a space as the delimiter
    string s;
    getline(cin, s);
    vector<string> p;
    stringstream ss(s);
    string word;
    while (getline(ss, word,'')) {
        p.push_back(word);
    }

    // Extract the first four elements of the vector p and convert them to integers
    int x1 = stoi(p[0]);
    int y1 = stoi(p[1]);
    int x2 = stoi(p[2]);
    int y2 = stoi(p[3]);

    // Calculate the differences between the coordinates
    int DIF1 = x2 - x1;
    int DIF2 = y2 - y1;

    // Calculate the coordinates of the other two points based on the given coordinates and the differences
    int x3 = x2 - DIF2;
    int y3 = y2 + DIF1;
    int x4 = x1 - DIF2;
    int y4 = y1 + DIF1;

    // Print the calculated coordinates in the format x3 x4 y3 y4
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}
