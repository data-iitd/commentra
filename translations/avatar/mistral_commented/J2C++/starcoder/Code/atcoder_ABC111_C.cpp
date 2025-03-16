
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Declaring an integer variable 'n' to store the number of elements in the input array

    // Reading the number of elements 'n' from the standard input stream
    cin >> n;

    int v[100010]; // Declaring an integer array 'v' of size 100010 to store the input elements

    // Reading the elements of the array 'v' from the standard input stream
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int vo[100010]; // Declaring an integer array 'vo' of size 100010 to store the count of occurrences of each unique value in the odd indexed elements of the array 'v'
    int ve[100010]; // Declaring an integer array've' of size 100010 to store the count of occurrences of each unique value in the even indexed elements of the array 'v'
    int vt[100010]; // Declaring an integer array 'vt' of size 100010 to store the total count of occurrences of each unique value in the array 'v'

    // Initializing all the elements of the arrays 'vo','ve', and 'vt' to zero
    fill_n(vo, 100010, 0);
    fill_n(ve, 100010, 0);
    fill_n(vt, 100010, 0);

    // Counting the occurrences of each unique value in the odd indexed elements of the array 'v' and updating the 'vo' array accordingly
    for (int i = 0; i < n; i += 2) {
        int currentElement = v[i];
        vo[currentElement]++;
    }

    // Counting the occurrences of each unique value in the even indexed elements of the array 'v' and updating the've' array accordingly
    for (int i = 1; i < n; i += 2) {
        int currentElement = v[i];
        ve[currentElement]++;
    }

    // Sorting the arrays 'vo','ve', and 'vt' in descending order
    sort(vo, vo + 100010, greater<int>());
    sort(ve, ve + 100010, greater<int>());
    sort(vt, vt + 100010, greater<int>());

    int ans = 0; // Declaring an integer variable 'ans' to store the answer

    // Checking if the sum of the first elements of the arrays 'vo' and've' is equal to the first element of the array 'vt'
    if (vo[0] + ve[0] == vt[0]) {
        // Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the arrays 'vo' and've'
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
    } else {
        // Calculating the answer as the difference between the count of the first element of the array 'vo' and the count of the first element of the array've'
        ans = n - vo[0] - ve[0];
    }

    // Printing the answer to the standard output stream
    cout << ans << "\n";

    return 0;
}

