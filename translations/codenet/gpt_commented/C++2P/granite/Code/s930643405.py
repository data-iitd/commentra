
# Read the initial number 'n' and the count of forbidden digits 'k'
n, k = map(int, input().split())

# Array to track forbidden digits
d = [0] * 10 # Initialize all digits as not forbidden

# Read the forbidden digits and mark them in the array
for _ in range(k):
    a = int(input()) # Input each forbidden digit
    d[a] = 1 # Mark the digit as forbidden

# Infinite loop to find the next valid number
while True:
    x = n # Start checking from the current number 'n'
    hantei = True # Reset the validity flag for the new number

    # Check each digit of the number 'x'
    while x > 0:
        # If the current digit is forbidden
        if d[x % 10] == 1:
            hantei = False # Mark the number as invalid
            break # Exit the digit checking loop
        x //= 10 # Remove the last digit

    # If the number is valid (no forbidden digits found)
    if hantei:
        print(n) # Output the valid number
        break # Exit the infinite loop
    n += 1 # Increment the number and check the next one

