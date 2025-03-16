# Declare a variable to hold the input number
n = int(input())

# Initialize a variable to store the result
ans = 0

# Loop through possible divisors from 1 to the square root of n
for i in range(1, int(n**0.5) + 1):
    # Check if i is a divisor of n and if the corresponding divisor (n/i) satisfies the condition
    if n % i == 0 and n % (n // i - 1) == i:
        # If the condition is met, add (n/i - 1) to the answer
        ans += n // i - 1

# Print the final result
print(ans)

# <END-OF-CODE>
