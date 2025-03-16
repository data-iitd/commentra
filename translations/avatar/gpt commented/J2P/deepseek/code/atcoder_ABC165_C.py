def main():
    # Read the values of n, m, and q from input
    n, m, q = map(int, input().split())
    
    # Initialize arrays based on the number of queries (q)
    a = [0] * q
    b = [0] * q
    c = [0] * q
    d = [0] * q
    
    # Read the query parameters into the arrays
    for i in range(q):
        a[i], b[i], c[i], d[i] = map(int, input().split())
        a[i] -= 1  # Store a[i] (0-indexed)
        b[i] -= 1  # Store b[i] (0-indexed)
    
    # Initialize answer to a very low value
    ans = -100
    
    # Start the depth-first search (DFS) to find the maximum score
    def dfs(list_):
        nonlocal ans
        # Check if the current list has reached the required size (n)
        if len(list_) == n:
            score = 0
            # Calculate the score based on the queries
            for i in range(q):
                # If the condition is met, add the corresponding value to the score
                if list_[b[i]] - list_[a[i]] == c[i]:
                    score += d[i]
            # Update the maximum score if the current score is higher
            ans = max(ans, score)
            return
        
        # If the list is not empty, continue adding numbers from the last added number to m
        if list_:
            last_num = list_[-1]
            for num in range(last_num, m + 1):
                list_.append(num)  # Add the current number to the list
                dfs(list_)         # Recur with the updated list
                list_.pop()        # Backtrack by removing the last number
        else:
            # If the list is empty, start adding numbers from 1 to m
            for num in range(1, m + 1):
                list_.append(num)  # Add the current number to the list
                dfs(list_)         # Recur with the updated list
                list_.pop()        # Backtrack by removing the last number
    
    dfs([])
    
    # Output the maximum score found
    print(ans)

if __name__ == "__main__":
    main()
