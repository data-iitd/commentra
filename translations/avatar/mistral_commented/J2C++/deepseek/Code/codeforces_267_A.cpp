#include <iostream>
using namespace std;

int sub(int a, int b) {
    int min = std::min(a, b);
    int max = std::max(a, b);
    int result = 0;

    while (min > 0) {
        result += max / min;
        max = max % min;
        int curr_min = std::min(min, max);
        int curr_max = std::max(min, max);
        min = curr_min;
        max = curr_max;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << sub(a, b) << endl;
    }

    return 0;
}

