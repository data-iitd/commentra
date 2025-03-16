
# Declare global variables for the size of the array and the answer
n = 0
ans = 0

# Initialize a 2D array to store the input values
a = [[0 for _ in range(101)] for _ in range(2)]

# Recursive function to find the maximum sum path
def find_ans(i, j, sum):
    # Check if the current position is the bottom-right corner and if the current sum is greater than the recorded answer
    global ans
    if i == 1 and j == n-1 and sum+a[i][j] > ans:
        # Update the answer with the new maximum sum
        ans = sum + a[i][j]
        return
    # If we are at the first row, move down to the next row
    if i == 0:
        find_ans(i+1, j, sum+a[i][j])
    # If we can move right within the bounds of the array, do so
    if j+1 < n:
        find_ans(i, j+1, sum+a[i][j])

# Read the size of the array from standard input
n = int(input())

# Loop to read the values into the 2D array
for i in range(2):
    for j in range(n):
        a[i][j] = int(input())
# Start the recursive function to find the maximum sum path from the top-left corner
find_ans(0, 0, 0)
# Print the final answer
print(ans)

