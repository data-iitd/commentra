#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    switch (S) {
    case "Sunny":
        cout << "Cloudy" << endl;
        break;
    case "Cloudy":
        cout << "Rainy" << endl;
        break;
    case "Rainy":
        cout << "Sunny" << endl;
        break;
    }
    return 0;
}

