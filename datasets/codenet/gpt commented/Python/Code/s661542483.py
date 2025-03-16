# Read an integer input from the user, representing the height
H = int(input())

# Initialize a counter variable to keep track of some value (not used in this code)
count = 0

# Define a recursive function 'dfs' that calculates a value based on the height 'h'
def dfs(h):
    # Base case: if the height is 1, return 1
    if h == 1:
        return 1

    # Recursive case: calculate the value for the current height
    # by dividing the height by 2, multiplying the result by 2, and adding 1
    return dfs(h // 2) * 2 + 1

# Call the 'dfs' function with the initial height 'H' and print the result
print(dfs(H))
