import sys

def main():
    # Read the number of rows (n), columns (m), and the minimum required value (x)
    n, m, x = map(int, input().split())
    
    # Initialize a 2D list to store the input values
    a = [list(map(int, input().split())) for _ in range(n)]
    
    # Initialize the minimum value to a very large number
    min_value = float('inf')
    
    # Iterate through all possible combinations of rows using bit manipulation
    for i in range(1 << n):
        # Create a list to track which rows are included in the current combination
        status = [0] * n
        
        # Determine which rows are included in the current combination
        for j in range(n):
            if (i >> j) & 1:
                status[j] = 1
        
        # Initialize a list to store the sum of the selected rows
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
            min_value = min(min_value, res[0])
    
    # Output the result: -1 if no valid combination was found, otherwise the minimum value
    if min_value == float('inf'):
        print(-1)
    else:
        print(min_value)

if __name__ == "__main__":
    main()
