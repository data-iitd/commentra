#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    vector < int > A(N);
    for ( int i = 0 ; i < N ; i++ )
        cin >> A[i];
    A.push_back(0);
    sort(A.begin(),A.end());
    int ans = 0;
    for ( int i = 0 ; i < N ; i++ ) {
        if (A[i] >= A[i+1])
            continue;
        int l = i+1, r = N-1;
        while (l < r) {
            int mid = (l+r)/2;
            if (A[mid] >= A[i])
                l = mid+1;
            else
                r = mid;
        }
        ans = max(ans,l-i);
    }
    cout << ans << endl;
    return 0;
}
