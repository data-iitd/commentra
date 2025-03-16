#include <iostream> // For input and output
#include <map> // For using std::map
using namespace std;

int main() {
    int n;
    cin >> n; // Reading the integer n from the input
    map<int, int> freqMap; // Initializing a map to store the frequency of numbers

    // Looping n times to read n numbers
    while (n-- > 0) {
        int num;
        cin >> num; // Reading the next integer from the input

        // Checking if there is no key less than the current number
        auto it = freqMap.lower_bound(num);
        if (it == freqMap.begin()) {
            // Incrementing the frequency of the current number
            freqMap[num]++;
        } else {
            // Finding the largest key less than the current number
            --it; // Move iterator to the largest key less than num
            int key = it->first;
            // Decrementing the frequency of the found key and removing it if frequency becomes zero
            if (--(it->second) == 0) {
                freqMap.erase(it); // Remove the key if frequency becomes zero
            }
            // Incrementing the frequency of the current number
            freqMap[num]++;
        }
    }

    // Calculating the sum of all frequencies in the map
    int ans = 0;
    for (const auto& pair : freqMap) {
        ans += pair.second; // Summing up the frequencies
    }

    // Printing the sum of frequencies
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
