def check(x, y):
    # Check if y is even
    if y % 2 == 0:
        # Calculate t as half of y minus x
        t = (y // 2) - x
        # Check if t is non-negative and x minus t is also non-negative
        if t >= 0 and (x - t) >= 0:
            return "Yes"
    # If the conditions are not met, return "No"
    return "No"

if __name__ == "__main__":
    # Read two integers x and y from the standard input
    x, y = map(int, input().split())
    
    # Call the check function with x and y, and print the result
    print(check(x, y))

# <END-OF-CODE>
