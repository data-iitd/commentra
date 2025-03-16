# Declare a variable to hold the input number
n = int(input())

# Initialize a flag to indicate if a solution is found
flg = False

# Check if the input number is less than 4
if n < 4:
    # If n is less than 4, output "No" since it's not possible to form n with 4s and 7s
    print("No")
else:
    # Iterate through possible counts of 4s (i)
    for i in range(0, n // 4 + 1):
        # Iterate through possible counts of 7s (j)
        for j in range(0, n // 7 + 1):
            # Check if the current combination of 4s and 7s equals n
            if i * 4 + j * 7 == n:
                # If a valid combination is found, set the flag to true
                flg = True
                break # Exit the inner loop
        # If a valid combination has been found, exit the outer loop
        if flg:
            break

# Check if a valid combination was found
if flg:
    # Output "Yes" if a combination of 4s and 7s can form n
    print("Yes")
else:
    # Output "No" if no combination can form n
    print("No")

