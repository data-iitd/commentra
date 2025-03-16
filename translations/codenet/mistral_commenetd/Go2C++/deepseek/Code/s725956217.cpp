#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void out(vector<int> x) {
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

int getInt() {
    int x;
    cin >> x;
    return x;
}

string getString() {
    string x;
    cin >> x;
    return x;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int asub(int a, int b) {
    return a > b ? a - b : b - a;
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

int lowerBound(vector<int>& a, int x) {
    int left = 0, right = a.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int upperBound(vector<int>& a, int x) {
    int left = 0, right = a.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

struct shop {
    int a, b;
};

bool compare(shop& s1, shop& s2) {
    return s1.a < s2.a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = getInt();
    int M = getInt();
    vector<shop> s(N);

    for (int i = 0; i < N; i++) {
        s[i].a = getInt();
        s[i].b = getInt();
    }

    sort(s.begin(), s.end(), compare);

    int total = 0;
    for (auto& e : s) {
        int n = min(e.b, M);
        total += n * e.a;
        M -= n;
        if (M == 0) {
            break;
        }
    }

    cout << total << endl;

    return 0;
}

