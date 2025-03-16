#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

vector<int> ReadInts(int n) {
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        cin >> ret[i];
    }
    return ret;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> As = ReadInts(N);
    vector<int> Fs = ReadInts(N);
    
    sort(As.begin(), As.end());
    sort(Fs.begin(), Fs.end(), greater<int>());
    
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }
    
    sort(scores.begin(), scores.end(), greater<int>());
    
    int ok = scores[0];
    int ng = -1;
    
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        
        int k = K;
        bool isOK = true;
        for (int i = 0; i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = false;
            }
        }
        
        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    
    cout << ok << endl;
    
    return 0;
}

