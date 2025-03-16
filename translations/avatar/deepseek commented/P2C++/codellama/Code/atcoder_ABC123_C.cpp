
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(5);
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }

    int min_value = *min_element(A.begin(), A.end());
    cout << ceil(N / min_value) + 4 << endl;

    return 0;
}

