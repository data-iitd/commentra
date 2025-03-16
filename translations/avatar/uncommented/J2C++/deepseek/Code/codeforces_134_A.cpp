#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int c = 0;
    stringstream sb;
    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) {
            c++;
            sb << (i + 1) << " ";
        }
    }
    cout << c << endl;
    cout << sb.str() << endl;
    return 0;
}
