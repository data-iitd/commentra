
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int n, q; cin >> n >> q;
    string c; cin >> c;
    vector<vector<int> > range(q, vector<int>(2));
    for(int i=0; i<q; i++){
        cin >> range[i][0] >> range[i][1];
    }
    vector<int> frag(n+1, 0);
    vector<int> rui(n+1, 0);
    for(int i=2; i<=n; i++){
        if(c[i-2] == 'A' && c[i-1] == 'C'){
            frag[i]++;
        }
        rui[i] = rui[i-1] + frag[i];
    }
    for(int i=0; i<q; i++){
        int left = range[i][0];
        int right = range[i][1];
        cout << rui[right] - rui[left] << endl;
    }
    return 0;
}
//END-OF-CODE