# Declare three integer variables: A, B, and flag
def main():
    A, B = map(int, input().split())
    flag = 0

    # Iterate from 1 to 3 using a for loop
    for i in range(1, 4):
        # Check if the product of A, B, and the loop counter i is odd
        if (A * B * i) % 2 == 1:
            # Set the flag variable to 1 if the condition is true
            flag = 1
            # Break out of the loop if the condition is true
            break

    # Check the value of the flag variable
    if flag:
        # Print "Yes" to the standard output if the flag variable is 1
        print("Yes")
    else:
        # Print "No" to the standard output if the flag variable is 0
        print("No")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
