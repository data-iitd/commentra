import sys

# Declare arrays to hold input values and variables for dimensions and result
a = None
b = None
c = None
d = None
n = 0
m = 0
q = 0
ans = -100 # Initialize answer to a very low value

def dfs(list):
    # Check if the current list has reached the required size (n)
    if len(list) == n:
        score = 0 # Initialize score for the current configuration
        
        # Calculate the score based on the queries
        for i in range(q):
            # If the condition is met, add the corresponding value to the score
            score += (list[b[i]] - list[a[i]] == c[i]) * d[i]
        
        # Update the maximum score if the current score is higher
        global ans
        ans = max(ans, score)
        return
    
    # If the list is not empty, continue adding numbers from the last added number to m
    if len(list) > 0:
        for num in range(list[-1], m + 1):
            list.append(num) # Add the current number to the list
            dfs(list)     # Recur with the updated list
            list.pop() # Backtrack by removing the last number
    else:
        # If the list is empty, start adding numbers from 1 to m
        for num in range(1, m + 1):
            list.append(num) # Add the current number to the list
            dfs(list)     # Recur with the updated list
            list.pop() # Backtrack by removing the last number

def main():
    # Create a Scanner object for input
    sc = sys.stdin
    
    # Read the values of n, m, and q from input
    global n, m, q
    n, m, q = map(int, sc.readline().split())
    
    # Initialize arrays based on the number of queries (q)
    global a, b, c, d
    a = [0] * q
    b = [0] * q
    c = [0] * q
    d = [0] * q
    
    # Read the query parameters into the arrays
    for i in range(q):
        a[i], b[i], c[i], d[i] = map(int, sc.readline().split()) - 1 # Store a[i] (0-indexed) and b[i] (0-indexed)
    
    # Start the depth-first search (DFS) to find the maximum score
    dfs([])
    
    # Output the maximum score found
    print(ans)

if __name__ == "__main__":
    main()

# 