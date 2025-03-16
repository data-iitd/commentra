
# Define a function to calculate the difference in minutes between two time values
def time_diff(h1, m1, h2, m2):
    # Calculate the difference in minutes between h2:m2 and h1:m1
    ans = (h2 * 60 + m2) - (h1 * 60 + m1)
    return ans

# Read input values for h1, m1, h2, m2, and k from the standard input
h1, m1, h2, m2, k = map(int, input().split())

# Print the result of subtracting k from the calculated difference
print(time_diff(h1, m1, h2, m2) - k)

