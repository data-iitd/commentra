# Define the main function
def main():
    # Declare variables
    n = int(input())  # Read the input number
    flg = False  # Initialize a boolean variable (flag) to False

    # Check if n is less than 4
    if n < 4:
        print("No")  # Print "No" and exit the function
        return

    # Check if n can be represented as a sum of two integers, each a multiple of 4 and 7
    for i in range(n // 4 + 1):  # Outer loop: i from 0 to n/4
        for j in range(n // 7 + 1):  # Inner loop: j from 0 to n/7
            if (i * 4 + j * 7) == n:  # Check if the sum of i*4 and j*7 equals n
                flg = True  # Set the flag to True if found
                break  # Exit the inner loop
        if flg:  # Exit the outer loop if flag is True
            break

    # Print the result
    if flg:
        print("Yes")  # Print "Yes" if n can be represented as a sum of two integers, each a multiple of 4 and 7
    else:
        print("No")  # Print "No" otherwise

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
