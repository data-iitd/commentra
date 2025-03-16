#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, o = 0;
    // Read the number of elements (n) and the number of elements to sum (k)
    cin >> n >> k;
    vector<int> p(n);
    
    // Read n integers and store them in the vector p
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    // Perform selection sort on the vector p
    for (int i = 0; i < n; i++) {
        int l = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j] < p[l]) {
                l = j;
            }
        }
        if (l != i) {
            swap(p[i], p[l]);
        }
    }
    
    // Sum the first k elements of the sorted vector
    for (int i = 0; i < k; i++) {
        o += p[i];
    }
    
    // Print the sum of the first k elements
    cout << o << endl;
    return 0;
}

// <END-OF-CODE>
