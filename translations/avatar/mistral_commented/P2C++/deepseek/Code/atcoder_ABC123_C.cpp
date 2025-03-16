#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric> // for gcd
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Define a constant variable N, which is the input number
    int N;
    cin >> N;

    // Define a vector A, which consists of five integers, each input as a separate line
    vector<int> A(5);
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
    }

    // Calculate the minimum value in the vector A
    int min_value = *min_element(A.begin(), A.end());

    // Calculate the ceiling value of N divided by the minimum value in the vector A
    int ceiling_value = (N + min_value - 1) / min_value;

    // Add 4 to the ceiling value to get the final answer
    int final_answer = ceiling_value + 4;

    // Print the final answer
    cout << final_answer << endl;

    return 0;
}
