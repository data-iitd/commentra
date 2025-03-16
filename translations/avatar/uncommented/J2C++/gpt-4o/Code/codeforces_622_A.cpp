#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

const int BUFFERSIZE = 512000;

long getValueAtIndex(long index) {
    return 1 + ((index - 1) * index / 2);
}

void solve() {
    long position;
    cin >> position;
    
    long nrstSeqStartIndx = 1;
    while (getValueAtIndex(nrstSeqStartIndx * 2) < position) {
        nrstSeqStartIndx *= 2;
    }
    
    while (getValueAtIndex(nrstSeqStartIndx + 1) <= position) {
        nrstSeqStartIndx++;
    }
    
    long startIndex = getValueAtIndex(nrstSeqStartIndx);
    cout << (position - startIndex) + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}

// <END-OF-CODE>
