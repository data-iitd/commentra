#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

const int N = 200 + 10;
int f[N];
char b[N];

// Computes the failure array for the given pattern
void getFail(char b[], int m) {
    int j = 0;
    f[0] = f[1] = 0;
    for (int i = 2; i <= m; i++) {
        while (j > 0 && b[j + 1] != b[i])
            j = f[j];
        if (b[j + 1] == b[i])
            j++;
        f[i] = j;
    }
}

int main() {
    int n;
    string s1, str;
    
    // Read input values
    cin >> n;
    cin >> s1;
    cin >> str;
    
    // Construct a combined string
    int cnt = 0;
    for (int i = 0; i < n; i++)
        b[++cnt] = str[i];
    for (int i = 0; i < n; i++)
        b[++cnt] = s1[i];
    
    // Compute the failure array for the combined string
    getFail(b, cnt);
    
    // Calculate the result based on the failure array
    int len = min(f[cnt], min(n, n));
    
    // Print the result
    cout << 2 * n - len << endl;
    
    return 0;
}

