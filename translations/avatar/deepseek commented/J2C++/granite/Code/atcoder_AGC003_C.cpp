

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Define a constant for array or list size
    const int NUM = ( int ) ( 1e5 + 2 ) ; 

    // Initialize a Scanner object to read input
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    // Read the number of elements
    int N;
    cin >> N;

    // Initialize a map to store value and its index
    map < int, int > map;

    // Initialize a PriorityQueue to store numbers
    priority_queue < int > nums;

    // Read each number, add it to the PriorityQueue, and store its value and index in the map
    for ( int i = 0 ; i < N ; i ++ ) {
        int tmp;
        cin >> tmp;
        nums.push(tmp);
        map[tmp] = i;
    }

    // Initialize variables to keep track of the current index and the count of differences
    int bin = 0;
    int diff = 0;

    // Loop until the PriorityQueue is empty
    while (!nums.empty()) {
        // Retrieve the next number and its index from the PriorityQueue and map
        int num = nums.top();
        nums.pop();
        int idx = map[num];

        // If the current index is not even when bin is even (or vice versa), increment the diff counter
        if ((bin % 2)!= (idx % 2)) {
            diff ++ ;
        }

        // Update bin and take modulo 2 to keep it within 0 or 1
        bin ++ ;
        bin %= 2;
    }

    // Calculate the answer by dividing diff by 2
    int ans = ( diff / 2 ) ;

    // Print the result
    cout << ans << endl;

    return 0;
}
