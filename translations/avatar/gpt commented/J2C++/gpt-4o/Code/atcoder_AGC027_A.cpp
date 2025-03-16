#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of sweet items (N) and the initial amount of money (x)
    int N;
    long long x;
    cin >> N >> x;
    
    // Initialize a vector to store the sweetness values of the items
    vector<long long> sweet(N);
    
    // Read the sweetness values and add them to the vector
    for (int i = 0; i < N; i++) {
        cin >> sweet[i];
    }
    
    // Sort the vector of sweetness values in ascending order
    sort(sweet.begin(), sweet.end());
    
    // Initialize a counter for the number of sweet items that can be bought
    int num = 0;
    
    // Iterate through the sorted sweetness values
    for (int i = 0; i < N; i++) {
        // Check if the current sweetness value can be bought with the remaining money
        if (x - sweet[num] >= 0) {
            // Deduct the sweetness value from the total money
            x -= sweet[num];
            // Increment the count of items bought
            num++;
        } else {
            // If the current item cannot be bought, exit the loop
            break;
        }
    }
    
    // Adjust the count if all items were bought but there is still money left
    if ((num == N) && (x > 0)) {
        num -= 1;
    }
    
    // Print the total number of sweet items that can be bought
    cout << num << endl;

    return 0;
}

// <END-OF-CODE>
