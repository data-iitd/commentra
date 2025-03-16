#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // Number of entries
    cin >> n; // Read the number of entries
    vector<int> FfriendPerDay(367, 0); // Array to store the number of female friends per day
    vector<int> MfriendPerDay(367, 0); // Array to store the number of male friends per day
    int answer = 0; // Variable to store the maximum number of friends on any single day

    // Loop through each entry
    for (int i = 0; i < n; i++) {
        char c; // Gender (M or F)
        int a, b; // Start and end day
        cin >> c >> a >> b; // Read the gender and the days

        // Update the friend counts for each day in the range
        for (int j = a; j <= b; j++) {
            if (c == 'M') 
                MfriendPerDay[j]++; // Increment male friend count
            else 
                FfriendPerDay[j]++; // Increment female friend count

            // Determine which gender has the lower count and update the answer
            if (MfriendPerDay[j] < FfriendPerDay[j]) {
                if (MfriendPerDay[j] > answer) 
                    answer = MfriendPerDay[j]; // Update answer if current male count is greater
            } else {
                if (FfriendPerDay[j] > answer) 
                    answer = FfriendPerDay[j]; // Update answer if current female count is greater
            }
        }
    }

    // Output the result, which is twice the maximum number of friends on any single day
    cout << answer * 2 << endl;

    return 0;
}

// <END-OF-CODE>
