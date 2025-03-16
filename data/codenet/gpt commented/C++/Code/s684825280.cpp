#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// Define a constant size for the count array
const int SIZE = (1e5 * 2) + 13;

// Declare a vector to hold the counts of each number
vector<int> a;
// Declare a count array initialized to zero with a size of SIZE
vector<int> cnt(SIZE);

int main(){
    // Read the number of elements (n) and the number of largest counts to keep (k)
    int n, k;
    cin >> n >> k;

    // Read n integers and count their occurrences
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        // Increment the count for the number x
        cnt[x]++;
    }

    // Transfer the counts of numbers that appeared at least once to vector a
    for(int i = 0; i < cnt.size(); ++i){
        if(cnt[i] > 0)
            a.push_back(cnt[i]); // Add the count to vector a
    }

    // Initialize the answer variable to accumulate the result
    int ans = 0;
    // Sort the counts in ascending order
    sort(a.begin(), a.end());

    // Calculate the number of counts to exclude (m) based on k
    int m = a.size() - k;
    // Sum the counts of the smallest m elements
    for(int i = 0; i < m; ++i){
        ans += a[i]; // Add the count to the answer
    }

    // Output the final answer
    cout << ans << endl;
}
