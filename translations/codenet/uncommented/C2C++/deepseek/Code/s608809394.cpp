#include<iostream>
using namespace std;

int main()
{
    int n, i, j, m, s, t;
    cin >> n;
    int a[n];
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    t = 0;
    for(i = 0; i < n; i++){
        s = 0;
        for(j = 1; j < n; j++){
            if(j <= i){
                continue;
            }
            m = a[i] * a[j];
            s = s + m;
        }
        t = t + s;
    }
    cout << t << endl;
    return 0;
}
