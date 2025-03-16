def main():
    # Read values of n, m, and q
    n, m, q = map(int, input().split())
    
    # Initialize arrays to store the conditions
    a = [0] * q
    b = [0] * q
    c = [0] * q
    d = [0] * q
    
    # Read the conditions into the arrays
    for i in range(q):
        a[i], b[i], c[i], d[i] = map(int, input().split())
        a[i] -= 1  # Adjusting for 0-based index
        b[i] -= 1  # Adjusting for 0-based index
    
    # Start the DFS with an empty list
    dfs([], n, m)
    
    # Print the maximum score found
    print(ans)

# Depth-First Search (DFS) function to generate combinations
def dfs(list, n, m):
    global ans
    # If the list size equals n, calculate the score and update ans
    if len(list) == n:
        score = 0
        for i in range(q):
            if list[b[i]] - list[a[i]] == c[i]:
                score += d[i]
        ans = max(ans, score)
        return
    
    # If the list is not empty, continue adding numbers from the last number in the list
    if list:
        for num in range(list[-1], m + 1):
            list.append(num)
            dfs(list, n, m)
            list.pop()
    else:
        # If the list is empty, start with numbers from 1 to m
        for num in range(1, m + 1):
            list.append(num)
            dfs(list, n, m)
            list.pop()

# Call the main function
main()
