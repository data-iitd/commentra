

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

int main() {
    // Main function declaration

    int n, m;
    cin >> n >> m;

    set<int> bannedRows;
    set<int> bannedCols;

    for (int i = 0; i < m; i++) {
        // Reading banned cells and adding them to the respective sets

        int r, c;
        cin >> r >> c;
        if (r > 1 && r < n) bannedRows.insert(r);
        if (c > 1 && c < n) bannedCols.insert(c);
    }

    int answer = (n - 2) * 2;
    answer -= bannedRows.size();
    answer -= bannedCols.size();

    if (n % 2!= 0) {
        // Special case when the number of rows is odd

        int mid = (n + 1) / 2;
        if (!bannedRows.count(mid) &&!bannedCols.count(mid)) {
            // If the middle cell is not banned, decrement the answer
            answer--;
        }
    }

    cout << answer << endl;

    return 0;
}

This code should be self-explanatory and should output the same result as the original Java code.