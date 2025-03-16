#include <stdio.h>

int main() {
    # Declare variables to hold the month and day values for two dates
    m1, d1, m2, d2 = 0, 0, 0, 0

    # Read input values for the two dates (month and day)
    scanf("%d%d%d%d", &m1, &d1, &m2, &d2)

    # Compare the months of the two dates
    if m1 != m2:
        # If the months are different, print "1"
        print("1\n")
    else:
        # If the months are the same, print "0"
        print("0\n")

    return 0 # Return 0 to indicate successful completion of the program
}

