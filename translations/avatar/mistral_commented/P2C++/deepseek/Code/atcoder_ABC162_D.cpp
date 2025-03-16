#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void calculate(int n, string s) {
    // Create a list arr from the string s
    char arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = s[i];
    }

    // Count the number of occurrences of each color in the list arr and store them in variables rNum, gNum, and bNum
    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'R') rNum++;
        else if (arr[i] == 'G') gNum++;
        else if (arr[i] == 'B') bNum++;
    }

    // Initialize a variable sum to 0
    int sum = 0;

    // Use a for loop to iterate through each step from 1 to the ceiling of N/2
    for (int step = 1; step <= ceil(n / 2.0); step++) {
        // Inside the inner for loop, join three consecutive elements of the list arr to form a string s
        string s = "";
        for (int i = 0; i < 3; i++) {
            s += arr[step - 1 + i];
        }

        // Check if the string s is equal to any of the six possible color combinations: "RGB", "RBG", "BGR", "BRG", "GBR", or "GRB"
        if (s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB") {
            sum += 1;
        }
    }

    // After the inner for loop, print the result of the calculation: rNum * gNum * bNum - sum
    cout << rNum * gNum * bNum - sum << endl;
}

int main() {
    // Take an integer input N and a string input S from the user
    int N;
    string S;
    cin >> N;
    cin >> S;

    // Call the calculate function with the input values N and S
    calculate(N, S);

    return 0;
}
