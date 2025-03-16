#include <stdio.h>

int main() {
    # Declare an integer variable to hold the number of inputs
    n = int(input())

    # Initialize counters for multiples of 4 and multiples of 2
    cnt4 = 0
    cnt2 = 0

    # Loop through each integer input
    for i in range(n):
        # Read the current integer
        wk = int(input())
        
        # Check if the integer is a multiple of 4
        if wk % 4 == 0:
            cnt4 += 1
        # Check if the integer is a multiple of 2 (but not a multiple of 4)
        elif wk % 2 == 0:
            cnt2 += 1

    # Check if the total count of multiples of 4 and half the count of multiples of 2 is at least n/2
    if cnt4 + cnt2 / 2 >= n / 2:
        # If the condition is met, print "Yes"
        print("Yes")
    else:
        # If the condition is not met, print "No"
        print("No")

    return 0
}
