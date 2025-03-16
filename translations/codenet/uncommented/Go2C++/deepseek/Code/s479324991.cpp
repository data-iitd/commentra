#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Scanner {
public:
    Scanner() : buffer(istream_iterator<string>(cin), istream_iterator<string>()) {}
    int NextInt() { return stoi(buffer[index++]); }
    vector<int> NextIntArray() {
        vector<int> result;
        while (index < buffer.size() && isdigit(buffer[index][0])) {
            result.push_back(stoi(buffer[index++]));
        }
        index--;
        return result;
    }
private:
    vector<string> buffer;
    int index = 0;
};

int main() {
    Scanner sc;
    int n = sc.NextInt();
    vector<double> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = sc.NextInt();
    }
    sort(arr.begin(), arr.end());
    double prev = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prev = (prev + arr[i]) / 2;
    }
    cout << fixed << setprecision(10) << prev << endl;
}
