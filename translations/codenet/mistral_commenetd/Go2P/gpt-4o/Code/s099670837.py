# Variables declaration
n = 0
ans = 0
array_size = 101

# 2D array declaration and initialization
a = [[0] * array_size for _ in range(array_size)]

# Recursive function to find the maximum sum of a sub-matrix
def find_ans(i, j, sum):
    global ans
    # Base case: if we have reached the last cell and the sum is greater than the current answer, update the answer
    if i == 1 and j == n - 1:
        ans = sum + a[i][j]
        return
    # Base case: if we have reached the first row, recursively call the function for the next cell and add the current cell value to the sum
    if i == 0:
        find_ans(i + 1, j, sum + a[i][j])
        return
    # Recursively call the function for the next cell and add the current cell value to the sum
    if j + 1 < n:
        find_ans(i, j + 1, sum + a[i][j])
        return

# Main function
if __name__ == "__main__":
    # Read the number of rows and columns from the standard input
    n = int(input())

    # Read the elements of the matrix from the standard input
    for i in range(2):
        row = list(map(int, input().split()))
        for j in range(n):
            a[i][j] = row[j]

    # Call the recursive function to find the maximum sum of a sub-matrix
    find_ans(0, 0, 0)

    # Print the maximum sum of a sub-matrix
    print(ans)

# <END-OF-CODE>
