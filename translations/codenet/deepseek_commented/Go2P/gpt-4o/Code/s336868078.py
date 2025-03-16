def solve(a, b, c):
    # Check if c is equal to the sum of a and b
    if c == a + b:
        temp_ = b + c
    elif c - 1 > a + b:  # Check if c-1 is greater than the sum of a and b
        temp = (c - 1) - (a + b)
        temp_ = b + c - temp  # Calculate temp_ based on the difference
    else:  # If neither condition is met
        temp_ = b + c
    return temp_

# Main function reads three integers from standard input, calls the solve function with these integers, and prints the result.
if __name__ == "__main__":
    a, b, c = map(int, input().split())
    ans = solve(a, b, c)
    print(ans)

# <END-OF-CODE>
