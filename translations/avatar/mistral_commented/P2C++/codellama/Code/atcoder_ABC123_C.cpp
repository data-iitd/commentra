#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    // Define a constant variable N, which is the input number
    int N;
    cin >> N;

    // Define a list A, which consists of five integers, each input as a separate line
    vector<int> A;
    for (int i = 0; i < 5; i++) {
        int input;
        cin >> input;
        A.push_back(input);
    }

    // Calculate the minimum value in the list A
    int min_value = *min_element(A.begin(), A.end());

    // Calculate the ceiling value of N divided by the minimum value in the list A
    int ceiling_value = ceil(N / min_value);

    // Add 4 to the ceiling value to get the final answer
    int final_answer = ceiling_value + 4;

    // Print the final answer
    cout << final_answer << endl;

    return 0;
}

