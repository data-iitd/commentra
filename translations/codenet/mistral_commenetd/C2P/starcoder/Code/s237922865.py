#include <stdio.h>

# Main function starts here
def main():
    # Declare and initialize variables
    n = 0

    # Read an integer value from the user
    n = int(input("Enter the number of integers: "))

    cnt4 = 0
    cnt2 = 0

    # Iterate through each integer input
    for i in range(n):
        wk = 0

        # Read an integer value from the user
        wk = int(input("Enter an integer: "))

        # Check if the current integer is a multiple of 4
        if wk % 4 == 0:
            cnt4 += 1
        # Check if the current integer is a multiple of 2
        elif wk % 2 == 0:
            cnt2 += 1

    # Check the condition to determine the output
    if cnt4 + cnt2 / 2 >= n / 2:
        print("Yes")
    else:
        print("No")

# Main function ends here
main()

