
# Read the upper limit 'n' from user input
n = int(input())

# Loop through numbers from 1 to n
for i in range(1, n+1):
    x = i
    s = str(x) # Convert 'x' to string for digit analysis

    # Check if 'x' is divisible by 3 or ends with the digit 3
    if x % 3 == 0 or x % 10 == 3:
        print(i, end=" ") # Print the number if condition is met
        continue # Skip to the next iteration
    else:
        # Get the number of digits in 'x'
        k = len(s)
        # Loop through each digit of 'x' from the most significant to the least
        while k > 0:
            k = k - 1 # Decrease the digit index
            j = 10 ** k # Calculate the place value for the current digit
            # Check if the current digit is 3
            if (x // j) % 10 == 3:
                print(i, end=" ") # Print the number if it contains the digit 3
                break # Exit the loop as we found a 3

print() # Print a newline after all numbers are processed

