#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

int main() {
    // Step 1: Read two times from the user, split by colon and convert to time
    string input1, input2;
    cin >> input1 >> input2;

    int h1, m1, h2, m2;
    char colon;

    stringstream ss1(input1);
    ss1 >> h1 >> colon >> m1;

    stringstream ss2(input2);
    ss2 >> h2 >> colon >> m2;

    // Create time points
    auto time1 = chrono::hours(h1) + chrono::minutes(m1);
    auto time2 = chrono::hours(h2) + chrono::minutes(m2);

    // Step 2: Calculate the difference between the two times
    auto duration = chrono::duration_cast<chrono::minutes>(time1 - time2);
    cout << duration.count() << " minutes" << endl;

    return 0;
}

// <END-OF-CODE>
