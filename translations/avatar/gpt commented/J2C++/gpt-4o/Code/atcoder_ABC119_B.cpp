#include <iostream>
#include <vector>
#include <string>

using namespace std;

double solve(const vector<double>& x, const vector<string>& u) {
    double total = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        total += x[i] * (u[i] == "JPY" ? 1 : 380000); // Convert JPY to standard currency (1) and other currencies to JPY (380000)
    }
    return total; // Return the total sum
}

int main() {
    // Create a variable to hold the number of currency entries
    int N;
    cin >> N; // Read the number of currency entries

    // Initialize vectors to hold the amounts and their corresponding currency units
    vector<double> x(N);
    vector<string> u(N);

    // Loop to read each amount and its currency unit
    for (int i = 0; i < N; ++i) {
        cin >> x[i]; // Read the amount
        cin >> u[i]; // Read the currency unit
    }

    // Calculate the total value in a standard currency and print the result
    cout << solve(x, u) << endl;

    return 0; // End of the program
}

// <END-OF-CODE>
