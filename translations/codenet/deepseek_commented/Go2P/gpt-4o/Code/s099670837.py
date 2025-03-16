n, ans = 0, 0  # Declare variables n and ans to store the size of the array and the result respectively.

array_size = 101  # Define a constant array_size to set the size of the 2D array.

a = [[0] * array_size for _ in range(array_size)]  # Declare a 2D array a with dimensions [array_size][array_size].

# find_ans is a recursive function that explores all possible paths from the top-left to the bottom-right corner of the array.
def find_ans(i, j, sum):
    global ans  # Use the global variable ans
    if i == 1 and j == n - 1 and sum + a[i][j] > ans:  # Check if the current position is the bottom-right corner
        ans = sum + a[i][j]  # Update ans if the condition is met.
        return  # Return to stop further recursion.
    if i == 0:  # If the current row is the first row, move to the next row.
        find_ans(i + 1, j, sum + a[i][j])  # Recursively call find_ans with the next row.
    if j + 1 < n:  # If the current column is within bounds, move to the next column.
        find_ans(i, j + 1, sum + a[i][j])  # Recursively call find_ans with the next column.

# main function to execute the program.
if __name__ == "__main__":
    n = int(input())  # Read the value of n from the input.
    for i in range(2):  # Loop through the first two rows of the array.
        row = list(map(int, input().split()))  # Read the values into the array a from the input.
        for j in range(n):
            a[i][j] = row[j]  # Assign the input values to the array a.
    find_ans(0, 0, 0)  # Call the find_ans function with initial parameters (0, 0, 0).
    print(ans)  # Print the final value of ans.

# <END-OF-CODE>
