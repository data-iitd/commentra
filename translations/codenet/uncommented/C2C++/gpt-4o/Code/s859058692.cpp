#include <iostream>
using namespace std;

int main() 
{
    long sum = 0;
    int m, n, min, max;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        sum += m;
        if(i == 0) {
            min = m;
            max = m;
        }
         
        if(min > m) {
            min = m;
        }
        if(max < m) {
            max = m;
        }
    }
    cout << min << " " << max << " " << sum << endl;
}

// <END-OF-CODE>
