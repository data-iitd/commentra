#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N, K; // Declare N and K to store the number of elements and the number of days respectively
    cin >> N >> K; // Read the values of N and K

    unordered_map<int, int> as; // Create a map to keep track of the occurrences of each element
    for (int i = 1; i <= N; i++) {
        as[i] = 0; // Initialize all elements to zero in the map
    }

    for (int i = 0; i < K; i++) {
        int d; // Declare d to store the number of elements chosen on a day
        cin >> d; // Read the number of elements chosen on the i-th day
        for (int j = 0; j < d; j++) {
            int a; // Declare a to store an element
            cin >> a; // Read the elements chosen on the i-th day
            as[a]++; // Increment the count of the chosen element in the map
        }
    }

    int ans = 0; // Initialize the answer variable to count unchosen elements
    for (const auto& pair : as) {
        if (pair.second == 0) {
            ans++; // Increment the answer if an element was not chosen
        }
    }

    cout << ans << endl; // Print the number of unchosen elements
    return 0;
}

// <END-OF-CODE>
