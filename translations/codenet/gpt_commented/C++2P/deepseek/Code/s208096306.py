def gcd(a, b):
    # Ensure 'a' is the larger number for the algorithm
    if a < b:
        a, b = b, a
    # Apply the Euclidean algorithm to find the GCD
    while (r := a % b) > 0:
        a = b
        b = r
    return b

# Main function to compute the GCD of 'n' integers
def main():
    n = int(input())  # Read the number of integers
    ans = int(input())  # Read the first integer and initialize 'ans' with it

    # Loop through the remaining integers to compute the GCD
    for _ in range(1, n):
        a = int(input())  # Read the current integer
        ans = gcd(ans, a)  # Update 'ans' with the GCD of 'ans' and 'a'

    # Output the final GCD result
    print(ans)

# Call the main function
main()

