#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Get user input as a string and convert it to a list of integers
    string input;
    cin >> input;
    istringstream iss(input);
    vector<int> numbers{istream_iterator<int>(iss), istream_iterator<int>()};

    // Initialize an empty list to store the games
    vector<pair<int, int>> games;

    // Iterate through a range of numbers from a to x+1
    for (int i = numbers[0]; i <= numbers[2]; i++) {
        // If i is less than or equal to b, skip to the next iteration
        if (i <= numbers[3]) {
            continue;
        }
        // Iterate through a range of numbers from b to y+1
        for (int j = numbers[3]; j <= numbers[1]; j++) {
            // If i is greater than j, append the tuple (i, j) to the games list
            if (i > j) {
                games.push_back(make_pair(i, j));
            }
        }
    }

    // Print the length of the games list
    cout << games.size() << endl;
    // Iterate through the games list and print each tuple
    for (auto i : games) {
        // Print the tuple as a string in the format "i j"
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}

