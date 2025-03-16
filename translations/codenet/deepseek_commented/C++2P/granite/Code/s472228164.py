
def check(x, y):
    # Check if y is even
    if y % 2 == 0:
        # Calculate t as half of y minus x
        t = int(0.5*y) - x
        # Check if t is non-negative and x minus t is also non-negative
        if t >= 0 and (x-t) >= 0:
            return "Yes"
    # If the conditions are not met, return "No"
    return "No"

x = int(input())
y = int(input())

# Call the check function with x and y, and print the result
print(check(x, y))
