def main():
    # Read the number of rows and columns from the input
    n = int(input())  # Number of rows
    m = int(input())  # Number of columns

    # Read the 2D array 'a' from the input
    a = [[0] * (m + 1) for _ in range(n)]
    for i in range(n):
        a[i] = list(map(int, input().split()))  # Read an element of the array 'a'

    # Initialize variables for binary search tree traversal
    min_val = float('inf')
    x = int(input())  # Value to search for

    # Perform binary tree traversal
    for i in range(2 ** n):
        status = [0] * n  # Initialize status array for current binary tree node

        # Set the status of each node based on the current binary tree node
        for j in range(n):
            if (i >> j) & 1:  # If the current binary tree node has a '1' at the j-th position
                status[j] = 1  # Set the status of the j-th node to '1'

        # Initialize result array for the current binary tree node
        res = [0] * (m + 1)

        # Calculate the sum of elements in the current row for each column
        for j in range(n):
            if status[j] == 1:  # If the j-th node is included in the current binary tree
                for k in range(m + 1):
                    res[k] += a[j][k]  # Add the element in the current column to the sum

        # Check if the sum of elements in the current row for each column is greater than or equal to 'x'
        flag = True
        for j in range(1, m + 1):
            if res[j] < x:  # If the sum of elements in the current column is less than 'x'
                flag = False  # Set the flag to 'false' and break the loop
                break

        # If the sum of elements in all columns for the current binary tree node is greater than or equal to 'x', update the minimum value
        if flag:
            min_val = min(min_val, res[0])  # Update the minimum value with the sum of elements in the first column

    # Print the minimum value if it exists, otherwise print '-1'
    if min_val == float('inf'):
        print(-1)
    else:
        print(min_val)


main()
