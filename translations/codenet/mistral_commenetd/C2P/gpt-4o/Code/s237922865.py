# Main function starts here
def main():
    # Read an integer value from the user
    n = int(input("Enter the number of integers: "))

    cnt4 = 0  # Initialize counter for 4's multiples
    cnt2 = 0  # Initialize counter for 2's multiples

    # Iterate through each integer input
    for i in range(n):
        # Read an integer value from the user
        wk = int(input("Enter an integer: "))

        # Check if the current integer is a multiple of 4
        if wk % 4 == 0:
            cnt4 += 1  # Increment the counter for 4's multiples
        # Check if the current integer is a multiple of 2
        elif wk % 2 == 0:
            cnt2 += 1  # Increment the counter for 2's multiples

    # Check the condition to determine the output
    if cnt4 + cnt2 // 2 >= n // 2:
        print("Yes")  # Output "Yes" if the condition is true
    else:
        print("No")  # Output "No" if the condition is false

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
