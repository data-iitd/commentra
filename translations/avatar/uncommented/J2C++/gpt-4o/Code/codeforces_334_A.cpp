#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void debug(const vector<int>& obj) {
    cerr << "[";
    for (size_t i = 0; i < obj.size(); ++i) {
        cerr << obj[i];
        if (i < obj.size() - 1) cerr << ", ";
    }
    cerr << "]" << endl;
}

int main() {
    int n;
    cin >> n;
    int square = n * n;
    vector<int> odd, even;

    for (int i = 1; i <= square; ++i) {
        if (i % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }

    int loop = square / n;
    int div = loop / 2;
    debug({div}); // Debugging output

    for (int i = 1; i <= loop; ++i) {
        for (int j = 0; j < div; ++j) {
            if (i % 2 == 1) {
                cout << odd.front() << " " << even.back() << " ";
                odd.erase(odd.begin());
                even.pop_back();
            } else {
                cout << even.front() << " " << odd.back() << " ";
                even.erase(even.begin());
                odd.pop_back();
            }
        }
        cout << endl;
    }

    return 0;
}

// <END-OF-CODE>
