
# Initialize variables
n = int(input()) # Read the number of integers from the standard input
as = [0] * n # Create an array of size n to store the input integers
ps = {} # Create a dictionary to store the prime factors and their powers

# Read the input integers and calculate their prime factors
for i in range(n):
    as[i] = int(input()) # Read an integer from the standard input

    ns = primeFactorize(as[i]) # Calculate the prime factors and their powers of the current integer
    for k, v in ns.items(): # Iterate through the dictionary to update the powers of the prime factors
        ps[k] = max(ps.get(k, 0), v) # Update the power of the current prime factor if it's greater

# Calculate the answer
x = 1 # Initialize a variable to store the product of prime factors
for k, v in ps.items(): # Iterate through the dictionary to calculate the product of prime factors
    for i in range(v): # Calculate the power of the prime factor
        x = mul(x, k) # Multiply the current product with the prime factor

ans = 0 # Initialize a variable to store the answer
for i in range(n): # Iterate through the array to calculate the answer
    ans = add(ans, div(x, as[i])) # Calculate the difference between the current product and the current integer, and add it to the answer

print(ans) # Print the answer

# END-OF-CODE