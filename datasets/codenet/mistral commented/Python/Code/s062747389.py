
# Define two variables `a` and `b` and assign them the values obtained by splitting the user input using the `split()` method and converting the resulting list to integers using the `map()` function
a, b = map(int, input().split())

# Check if both variables have the same value using the `if` statement
if a == b:
    # If they are equal, we print the sum of the two variables using the `print()` function and the `if` statement condition
    print(a + b)
else:
    # If they are not equal, we print the maximum value between the two variables multiplied by 2 and subtracted by 1 using the `print()` function and the `else` statement
    print(max(a, b) * 2 - 1)