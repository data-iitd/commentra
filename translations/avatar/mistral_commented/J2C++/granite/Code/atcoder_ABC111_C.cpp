

#include <bits/stdc++.h> // Including the standard library header file

using namespace std; // Using the standard namespace

int main() {
    ios_base::sync_with_stdio(false); // Disabling synchronization between C++ and C IO libraries
    cin.tie(NULL); // Setting the input stream to null to avoid buffering issues

    int n; // Declaring an integer variable 'n' to store the number of elements in the input array

    // Reading the number of elements 'n' from the standard input stream
    cin >> n;

    vector<int> v(100010); // Declaring a vector 'v' of size 100010 to store the input elements

    // Reading the elements of the vector 'v' from the standard input stream
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> vo(100010, 0); // Declaring a vector 'vo' of size 100010 to store the count of occurrences of each unique value in the odd indexed elements of the vector 'v'
    vector<int> ve(100010, 0); // Declaring a vector've' of size 100010 to store the count of occurrences of each unique value in the even indexed elements of the vector 'v'
    vector<int> vt(100010, 0); // Declaring a vector 'vt' of size 100010 to store the total count of occurrences of each unique value in the vector 'v'

    // Counting the occurrences of each unique value in the odd indexed elements of the vector 'v' and updating the 'vo' vector accordingly
    for (int i = 0; i < n; i += 2) {
        int currentElement = v[i];
        vo[currentElement]++;
    }

    // Counting the occurrences of each unique value in the even indexed elements of the vector 'v' and updating the've' vector accordingly
    for (int i = 1; i < n; i += 2) {
        int currentElement = v[i];
        ve[currentElement]++;
    }

    // Sorting the vectors 'vo','ve', and 'vt' in descending order
    sort(vo.rbegin(), vo.rend());
    sort(ve.rbegin(), ve.rend());
    sort(vt.rbegin(), vt.rend());

    int ans = 0; // Declaring an integer variable 'ans' to store the answer

    // Checking if the sum of the first elements of the vectors 'vo' and've' is equal to the first element of the vector 'vt'
    if (vo[0] + ve[0] == vt[0]) {
        // Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the vectors 'vo' and've'
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
    } else {
        // Calculating the answer as the difference between the count of the first element of the vector 'vo' and the count of the first element of the vector've'
        ans = n - vo[0] - ve[0];
    }

    // Printing the answer to the standard output stream
    cout << ans << endl;

    return 0; // Returning 0 to indicate successful execution of the program
}

