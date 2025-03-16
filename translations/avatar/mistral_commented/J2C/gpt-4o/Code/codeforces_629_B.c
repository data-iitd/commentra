#include <stdio.h> // Including standard input-output library

int main() { // Defining the main function as the entry point of the program
    int n; // Variable to store the number of test cases
    scanf("%d", &n); // Reading the number of test cases

    int FfriendPerDay[367] = {0}; // Initializing an array of size 367 to store the number of friends of type F for each day
    int MfriendPerDay[367] = {0}; // Initializing an array of size 367 to store the number of friends of type M for each day
    int answer = 0; // Initializing an integer variable to store the maximum difference between the number of friends of type F and M for any day

    for (int i = 0; i < n; i++) { // Iterating through each test case
        char c; // Variable to store the character representing the gender of the friend
        int a, b; // Variables to store the starting and ending day of the range
        scanf(" %c %d %d", &c, &a, &b); // Reading the character and the range

        for (int j = a; j <= b; j++) { // Iterating through each day in the range
            if (c == 'M') {
                MfriendPerDay[j]++; // Incrementing the counter in the MfriendPerDay array for the day if the friend is of type M
            } else {
                FfriendPerDay[j]++; // Incrementing the counter in the FfriendPerDay array for the day if the friend is of type F
            }

            if (MfriendPerDay[j] < FfriendPerDay[j]) { // Checking if the number of friends of type M is less than the number of friends of type F for the current day
                if (MfriendPerDay[j] > answer) {
                    answer = MfriendPerDay[j]; // Updating the value of answer if the current difference is greater than the previous maximum difference
                }
            } else { // Repeating the same check for the number of friends of type F
                if (FfriendPerDay[j] > answer) {
                    answer = FfriendPerDay[j];
                }
            }
        }
    }

    printf("%d\n", answer * 2); // Printing the answer, which is twice the maximum difference between the number of friends of type F and M for any day.

    return 0; // Returning 0 to indicate successful completion of the program
} // End of main function
// <END-OF-CODE>
