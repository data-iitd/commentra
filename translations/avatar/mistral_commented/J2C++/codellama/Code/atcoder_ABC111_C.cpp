
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; // Declaring an integer variable 'n' to store the number of elements in the input array

    // Reading the number of elements 'n' from the standard input stream
    cin >> n;

    vector<int> v; // Declaring a vector 'v' of size 100010 to store the input elements

    // Reading the elements of the vector 'v' from the standard input stream
    for (int i = 0; i < n; i++) {
        int currentElement;
        cin >> currentElement;
        v.push_back(currentElement);
    }

    vector<int> vo(100010, 0); // Declaring a vector 'vo' of size 100010 to store the count of occurrences of each unique value in the odd indexed elements of the vector 'v'
    vector<int> ve(100010, 0); // Declaring a vector 've' of size 100010 to store the count of occurrences of each unique value in the even indexed elements of the vector 'v'
    vector<int> vt(100010, 0); // Declaring a vector 'vt' of size 100010 to store the total count of occurrences of each unique value in the vector 'v'

    // Counting the occurrences of each unique value in the odd indexed elements of the vector 'v' and updating the 'vo' vector accordingly
    for (int i = 0; i < n; i += 2) {
        int currentElement = v[i];
        vo[currentElement]++;
    }

    // Counting the occurrences of each unique value in the even indexed elements of the vector 'v' and updating the 've' vector accordingly
    for (int i = 1; i < n; i += 2) {
        int currentElement = v[i];
        ve[currentElement]++;
    }

    // Sorting the vectors 'vo', 've', and 'vt' in descending order
    sort(vo.begin(), vo.end(), greater<int>());
    sort(ve.begin(), ve.end(), greater<int>());
    sort(vt.begin(), vt.end(), greater<int>());

    int ans = 0; // Declaring an integer variable 'ans' to store the answer

    // Checking if the sum of the first elements of the vectors 'vo' and 've' is equal to the first element of the vector 'vt'
    if (vo[0] + ve[0] == vt[0]) {
        // Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the vectors 'vo' and 've'
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
    } else {
        // Calculating the answer as the difference between the count of the first element of the vector 'vo' and the count of the first element of the vector 've'
        ans = n - vo[0] - ve[0];
    }

    // Printing the answer to the standard output stream
    cout << ans << endl;

    return 0;
}

