
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, x, y;
        cin >> n >> x >> y;

        priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int sum = 0, sum2 = 0, min = 0;

        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            sum += a;
            pq.push(a);
            pq2.push(a);

            if(pq.size() > pq2.size()){
                sum2 += pq.top();
                pq2.pop();
            }
            else if(pq.size() < pq2.size()){
                sum2 -= pq2.top();
                pq.pop();
            }

            min = pq.top();
        }

        if(n == 1){
            cout << x << " " << y << " " << sum << "\n";
        }
        else if(n == 2){
            cout << min << " " << (min * pq.size() + sum2) << " " << sum << "\n";
        }
        else{
            cout << min << " " << (min * pq.size() + sum2) << " " << sum << "\n";
        }
    }

    return 0;
}

