#include <stdio.h>

int main() {
    // Read the number of friends
    int n;
    scanf("%d", &n);
    
    // Arrays to keep track of the number of male and female friends per day
    int FfriendPerDay[367] = {0}; // Array for female friends
    int MfriendPerDay[367] = {0}; // Array for male friends
    
    // Variable to store the maximum number of friends present on any day
    int answer = 0;
    
    // Loop through each friend to gather their availability
    for (int i = 0; i < n; i++) {
        // Read the gender of the friend (M for male, F for female)
        char c;
        scanf(" %c", &c); // Note the space before %c to consume any whitespace
        // Read the start day (a) and end day (b) of availability
        int a, b;
        scanf("%d %d", &a, &b);
        
        // Loop through the days from a to b
        for (int j = a; j <= b; j++) {
            // Increment the count for male or female friends based on gender
            if (c == 'M') {
                MfriendPerDay[j]++;
            } else {
                FfriendPerDay[j]++;
            }
            
            // Check which gender has more friends on that day and update the answer
            if (MfriendPerDay[j] < FfriendPerDay[j]) {
                // If females are more, check if their count is greater than the current answer
                if (FfriendPerDay[j] > answer) {
                    answer = FfriendPerDay[j];
                }
            } else {
                // If males are more or equal, check if their count is greater than the current answer
                if (MfriendPerDay[j] > answer) {
                    answer = MfriendPerDay[j];
                }
            }
        }
    }
    
    // Output the maximum number of friends present on any day multiplied by 2
    printf("%d\n", answer * 2);
    
    return 0;
}

// <END-OF-CODE>
