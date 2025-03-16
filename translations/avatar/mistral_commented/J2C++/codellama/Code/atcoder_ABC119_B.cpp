
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N; // Declaring an integer variable 'N' to store the number of elements

    // Reading the number of elements from the user input
    cin >> N;

    vector<double> x(N); // Declaring and initializing a vector 'x' of size 'N' to store the double values
    vector<string> u(N); // Declaring and initializing a vector 'u' of size 'N' to store the currency strings

    // Reading the double values and currency strings from the user input and storing them in respective vectors
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        cin >> u[i];
    }

    // Calling the 'solve' function to find the sum of products of double values and their respective currency conversion factors
    cout << solve(x, u) << endl;

    return 0;
}

double solve(vector<double> x, vector<string> u) {
    return accumulate(x.begin(), x.end(), 0.0, [&](double sum, double value) {
        return sum + value * (u[distance(x.begin(), find(x.begin(), x.end(), value))].compare("JPY") == 0 ? 1 : 380000);
    });
}

