#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    vector<int> p(99999);
    // Read the number of elements (n) and the number of elements to sum (k)
    cin >> n >> k;
    // Read n integers and store them in the array p
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    // Sort the array p
    sort(p.begin(), p.begin() + n);
    // Sum the first k elements of the sorted array
    int o = 0;
    for(int i = 0; i < k; i++){
        o += p[i];
    }
    // Print the sum of the first k elements
    cout << o << endl;
    return 0;
}
