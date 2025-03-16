#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(5);
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }
    int min_value = *min_element(A.begin(), A.end());
    int ceiling_value = ceil(N / min_value);
    int final_answer = ceiling_value + 4;
    cout << final_answer << endl;
    return 0;
}

