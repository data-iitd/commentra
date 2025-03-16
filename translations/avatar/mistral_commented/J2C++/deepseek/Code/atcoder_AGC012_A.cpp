#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> array(3 * n);

    // Initializing the array with input values
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }

    // Sorting the array in ascending order
    sort(array.begin(), array.end());

    int head = array.size() - 2;
    long long res = 0;

    // Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for (int i = 0; i < n; i++) {
        res += array[head];
        head -= 2;
    }

    // Printing the result
    cout << res << endl;

    return 0;
}

