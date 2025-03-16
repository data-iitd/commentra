import sys

def main():
    # Read the number of rows (n), columns (m), and the minimum required value (x)
    n, m, x = map(int, sys.stdin.readline().split())

    # Initialize a 2D array to store the input values
    a = [[0] * (m + 1) for _ in range(n)]

    # Read the values into the 2D array
    for i in range(n):
        a[i] = list(map(int, sys.stdin.readline().split()))

    # Iterate through all possible combinations of rows using bit manipulation
    for i in range(2 ** n):
        # Create an array to track which rows are included in the current combination
        status = [0] * n

        # Determine which rows are included in the current combination
        for j in range(n):
            if (1 & i >> j) == 1:
                status[j] = 1

        # Initialize an array to store the sum of the selected rows
        res = [0] * (m + 1)

        # Calculate the sum of the selected rows
        for j in range(n):
            if status[j] == 1:
                for k in range(m + 1):
                    res[k] += a[j][k]

        # Check if the current combination meets the minimum requirement for each column
        flag = True
        for j in range(1, m + 1):
            if res[j] < x:
                flag = False
                break

        # If the combination is valid, update the minimum value found
        if flag:
            min = min(min, res[0])

    # Output the result: -1 if no valid combination was found, otherwise the minimum value
    if min == float('inf'):
        print(-1)
    else:
        print(min)

if __name__ == '__main__':
    main()

