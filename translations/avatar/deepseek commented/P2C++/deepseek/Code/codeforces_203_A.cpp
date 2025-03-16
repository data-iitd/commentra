#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    // Define the main function to perform the logic
    auto main = [&]() -> string {
        // Check if the value of x is 0
        if (x == 0) {
            cout << "YES" << endl;
            return "Result Found";
        }

        // Calculate the maximum number of times a and b can be decremented within the time limit t
        int a_time = min({a / da, t - 1});
        int b_time = min({b / db, t - 1});

        // Iterate over all possible combinations of decrements for a and b within their respective limits
        for (int i = 0; i <= a_time; ++i) {
            for (int j = 0; j <= b_time; ++j) {
                // Check if either a or b (or their sum) equals x
                if (a - da * i == x || b - db * j == x) {
                    cout << "YES" << endl;
                    return "Result Found";
                }
                if ((a - da * i) + (b - db * j) == x) {
                    cout << "YES" << endl;
                    return "Result Found";
                }
            }
        }

        // Return "Result Not Found" if no combination results in x
        return "Result Not Found";
    };

    // Call the main function and store the result
    string ff = main();

    // Check the result and print "NO" if the result is "Result Not Found"
    if (ff == "Result Not Found") {
        cout << "NO" << endl;
    }

