#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

int main() {
    // Declare variables
    int n, k;
    vector<int> p;

    // Read the number of elements (n) and the number of smallest elements to sum (k)
    cin >> n >> k;

    // Read n integers into the vector p
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        p.push_back(temp);
    }

    // Sort the vector p in ascending order
    sort(p.begin(), p.end());

    // Calculate the sum of the first k smallest elements in the sorted vector
    int o = 0;
    for(int i = 0; i < k; i++) {
        o += p[i];
    }

    // Print the result: the sum of the k smallest elements
    cout << o << endl;
    
    return 0;
}
