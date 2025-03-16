def nPr(n, r):
    # Initialize result to 1
    res = 1
    # Iterate from 0 to r and multiply result with (n-i)
    for i in range(r):
        res *= (n - i)
        # Multiply result with factorial of (n-i)
        # to get the value of nPr(n, r)
        # print(f"Calculating nPr({n}, {r}) = {res}")
    # Return the result
    return res

def nCr(n, r):
    # Initialize result to 1
    res = 1.0
    # Iterate from 0 to r and multiply result with (n-i) and divide by (i+1)
    for i in range(r):
        res *= (n - i)
        res /= (i + 1)
        # Multiply result with factorial of (n-i) and divide by (i+1)
        # to get the value of nCr(n, r)
        # print(f"Calculating nCr({n}, {r}) = {res}")
    # Convert the double result to long long and return it
    return int(res)

# Main function
if __name__ == "__main__":
    # Read input values of n and p from the user
    n, p = map(int, input().split())
    # Initialize b and c to count the number of even and odd elements in the array a
    a = list(map(int, input().split()))
    b = 0  # Count of even numbers
    c = 0  # Count of odd numbers

    for num in a:
        if num % 2 == 0:
            b += 1
        else:
            c += 1
        # Read an element from the array a and check if it is even or odd
        # Increment the corresponding counter (b for even and c for odd)

    # Calculate the sum of 2^b and c
    bsum = 1 << b  # This is equivalent to 2 ** b

    # Calculate the sum of nCr(c, i) for i from 0 to c
    csum = 0
    if p == 0:
        for i in range(c + 1):
            if i % 2 == 0:
                csum += nCr(c, i)
            # If i is even, add nCr(c, i) to csum
    else:
        for i in range(c + 1):
            if i % 2 == 1:
                csum += nCr(c, i)
            # If i is odd, add nCr(c, i) to csum

    # Multiply bsum and csum and store the result in ans
    ans = bsum * csum
    # Multiply bsum and csum to get the final answer

    # Print the final answer
    print(ans)

# <END-OF-CODE>
