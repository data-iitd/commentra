
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += abs(a[i] - a[i - 1]);
    }
    sum += abs(a[n + 1] - a[n]);

    for (int i = 1; i <= n; i++) {
        int ans = sum - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]) + abs(a[i + 1] - a[i - 1]);
        fout << ans << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

