# Declare global variables for the size of the array and the answer
n = 0
ans = 0

# Define a constant for the size of the array
arraySize = 101

# Initialize a 2D array to store the input values
a = [[0] * arraySize for _ in range(arraySize)]

# Recursive function to find the maximum sum path
def findAns(i, j, sum):
    global ans
    # Check if the current position is the bottom-right corner and if the current sum is greater than the recorded answer
    if i == 1 and j == n - 1 and sum + a[i][j] > ans:
        # Update the answer with the new maximum sum
        ans = sum + a[i][j]
        return
    # If we are at the first row, move down to the next row
    if i == 0:
        findAns(i + 1, j, sum + a[i][j])
    # If we can move right within the bounds of the array, do so
    if j + 1 < n:
        findAns(i, j + 1, sum + a[i][j])

def main():
    global n
    # Read the size of the array from standard input
    n = int(input())
    
    # Loop to read the values into the 2D array
    for i in range(2):
        values = list(map(int, input().split()))
        for j in range(n):
            a[i][j] = values[j]
    
    # Start the recursive function to find the maximum sum path from the top-left corner
    findAns(0, 0, 0)
    # Print the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
