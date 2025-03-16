#include <iostream>
using namespace std;

int main() {
    int n, m, i, min, max;
    long sum = 0;
    
    cin >> n;
    for(i=0; i<n; i++){
        cin >> m;
        sum += m;
        if(min > m){
            min = m;
        }
        if(max < m){
            max = m;
        }
    }
    cout << min << " " << max << " " << sum << endl;
}

