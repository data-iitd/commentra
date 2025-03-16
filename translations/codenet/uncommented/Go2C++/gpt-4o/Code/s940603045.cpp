#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

bool isDivisibleBySumOfDigits(const string& number) {
    int sum = 0;
    for (char digit : number) {
        sum += digit - '0';
    }
    int num = stoi(number);
    return num % sum == 0;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    string N;
    cin >> N;

    if (isDivisibleBySumOfDigits(N)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// <END-OF-CODE>
