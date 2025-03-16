#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    int N, x;
    cin >> N >> x;
    
    // Initialize a list to store the sweetness values of the items
    vector<long> sweet;
    
    // Read the sweetness values and add them to the list
    for (int i = 0; i < N; i++) {
        long a;
        cin >> a;
        sweet.push_back(a);
    }
    
    // Sort the list of sweetness values in ascending order
    sort(sweet.begin(), sweet.end());
    
    // Initialize a counter for the number of sweet items that can be bought
    int num = 0;
    
    // Iterate through the sorted sweetness values
    for (int i = 0; i < N; i++) {
        // Check if the current sweetness value can be bought with the remaining money
        if (x - sweet[num] >= 0) {
            // Deduct the sweetness value from the total money
            x = x - sweet[num];
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
    
    // End of code
    return 0;
}


