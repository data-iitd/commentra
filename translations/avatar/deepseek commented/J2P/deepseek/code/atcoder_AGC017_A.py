import math

# Function to calculate combination (n choose m) using math.comb for large numbers
def C(n, m):
    res = 1
    # Calculate product from m-n+1 to m
    for i in range(m - n + 1, m + 1):
        res *= i
    # Divide by product from 1 to n
    for i in range(1, n + 1):
        res //= i
    return res

# Main function
def main():
    # Read number of items (n) and the value of p
    n, p = map(int, input().split())

    # Count even and odd numbers in the input
    k0 = 0  # Count of even numbers
    k1 = 0  # Count of odd numbers
    numbers = list(map(int, input().split()))
    for x in numbers:
        if x % 2 == 1:
            k1 += 1
        else:
            k0 += 1

    # Initialize result for number of ways to arrange items
    ans = 1

    # Calculate number of ways based on the value of p
    for i in range(k0):
        ans *= 2  # Multiply by 2 for each even number

    if p == 0:
        add = 0
        # Sum combinations of odd numbers, taking 0, 2, 4, ... odd numbers
        for i in range(0, k1 + 1, 2):
            add += C(i, k1)
        ans *= add  # Multiply result by the sum
        print(ans)  # Print final result
    else:
        add = 0
        # Sum combinations of odd numbers, taking 1, 3, 5, ... odd numbers
        for i in range(1, k1 + 1, 2):
            add += C(i, k1)
        ans *= add  # Multiply result by the sum
        print(ans)  # Print final result

# Call the main function
main()
