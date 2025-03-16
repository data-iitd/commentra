#include <bits/stdc++.h>
using namespace std;

#define BUFFERSIZE 512000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long position;
    cin >> position;
    long long nrstSeqStartIndx = 1;
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }
    long long startIndex = getValueAtIndex(nrstSeqStartIndx);
    cout << (position - startIndex) + 1 << endl;
    return 0;
}

long long getValueAtIndex(long long index) {
    return 1 + ((index - 1) * index / 2);
}

