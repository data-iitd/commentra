#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <iomanip>
#include <utility>
#include <bitset>
#include <set>
#include <map>
#include <ios>
#include <cstdlib>
using namespace std;

int main() {
    // Step 3: Input a string
    string N; 
    cin >> N;

    // Step 4: Calculate the sum of digits
    int S = 0;
    for (int i = 0; i < N.size(); i++) {
        S += N[i] - '0';
    }

    // Step 5: Check if the number is divisible by the sum of its digits
    if (stoi(N) % S == 0) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    // Step 6: Return 0
    return 0;
}
