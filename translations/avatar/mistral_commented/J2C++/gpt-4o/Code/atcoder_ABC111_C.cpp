#include <iostream> // Including iostream for input and output
#include <vector>   // Including vector for dynamic array
#include <algorithm> // Including algorithm for sorting
#include <unordered_map> // Including unordered_map for counting occurrences

using namespace std;

int main() {
    int n; // Declaring an integer variable 'n' to store the number of elements in the input array

    // Reading the number of elements 'n' from the standard input stream
    cin >> n;

    vector<int> v(n); // Declaring a vector 'v' to store the input elements

    // Reading the elements of the vector 'v' from the standard input stream
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    unordered_map<int, int> vo; // Map to store counts of occurrences of unique values in odd indexed elements
    unordered_map<int, int> ve; // Map to store counts of occurrences of unique values in even indexed elements

    // Counting the occurrences of each unique value in the odd indexed elements of the vector 'v'
    for (int i = 0; i < n; i += 2) {
        vo[v[i]]++;
    }

    // Counting the occurrences of each unique value in the even indexed elements of the vector 'v'
    for (int i = 1; i < n; i += 2) {
        ve[v[i]]++;
    }

    // Creating vectors to store the counts for sorting
    vector<int> oddCounts, evenCounts;

    for (const auto& pair : vo) {
        oddCounts.push_back(pair.second);
    }
    for (const auto& pair : ve) {
        evenCounts.push_back(pair.second);
    }

    // Sorting the counts in descending order
    sort(oddCounts.rbegin(), oddCounts.rend());
    sort(evenCounts.rbegin(), evenCounts.rend());

    int ans = 0; // Declaring an integer variable 'ans' to store the answer

    // Checking if the sum of the first elements of the vectors 'oddCounts' and 'evenCounts' is equal to the first element of the total counts
    if (!oddCounts.empty() && !evenCounts.empty() && oddCounts[0] + evenCounts[0] == n) {
        // Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the vectors
        ans = min(n - oddCounts[0] - (evenCounts.size() > 1 ? evenCounts[1] : 0), n - (oddCounts.size() > 1 ? oddCounts[1] : 0) - evenCounts[0]);
    } else {
        // Calculating the answer as the difference between the count of the first element of the vector 'oddCounts' and the count of the first element of the vector 'evenCounts'
        ans = n - oddCounts[0] - evenCounts[0];
    }

    // Printing the answer to the standard output stream
    cout << ans << endl;

    return 0; // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
