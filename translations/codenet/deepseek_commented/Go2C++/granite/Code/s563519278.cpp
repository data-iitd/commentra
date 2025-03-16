
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    int a;
    for (int i = 1; i < N; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        ss >> a;
        v[a - 1]++;
    }
    for (int i = 0; i < N; i++) {
        cout << v[i] << endl;
    }
    return 0;
}

