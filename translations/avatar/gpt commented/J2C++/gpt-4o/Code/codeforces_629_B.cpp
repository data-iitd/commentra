#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a variable to read input from the console
    int n;
    
    // Read the number of friends
    cin >> n;
    
    // Vectors to keep track of the number of male and female friends per day
    vector<int> FfriendPerDay(367, 0); // Vector for female friends
    vector<int> MfriendPerDay(367, 0); // Vector for male friends
    
    // Variable to store the maximum number of friends present on any day
    int answer = 0;
    
    // Loop through each friend to gather their availability
    for (int i = 0; i < n; i++) {
        // Read the gender of the friend (M for male, F for female)
        char c;
        cin >> c;
        
        // Read the start day (a) and end day (b) of availability
        int a, b;
        cin >> a >> b;
        
        // Loop through the days from a to b
        for (int j = a; j <= b; j++) {
            // Increment the count for male or female friends based on gender
            if (c == 'M') 
                MfriendPerDay[j]++;
            else 
                FfriendPerDay[j]++;
            
            // Check which gender has more friends on that day and update the answer
            if (MfriendPerDay[j] < FfriendPerDay[j]) {
                // If females are more, check if their count is greater than the current answer
                if (MfriendPerDay[j] > answer) 
                    answer = MfriendPerDay[j];
            } else {
                // If males are more or equal, check if their count is greater than the current answer
                if (FfriendPerDay[j] > answer) 
                    answer = FfriendPerDay[j];
            }
        }
    }
    
    // Output the maximum number of friends present on any day multiplied by 2
    cout << answer * 2 << endl;

    return 0;
}

// <END-OF-CODE>
