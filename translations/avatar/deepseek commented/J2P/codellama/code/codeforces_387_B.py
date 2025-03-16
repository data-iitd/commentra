import array // Import array for dynamic array

def main():
    n, m = map(int, input().split()) // Read the number of elements n and m
    req = array.array("i", []) // Initialize array req
    pre = array.array("i", []) // Initialize array pre
    
    # Read elements into req
    for i in range(n):
        req.append(int(input()))
    
    # Read elements into pre
    for i in range(m):
        pre.append(int(input()))
    
    i = n - 1 // Initialize indices i and j
    j = m - 1
    ans = 0 // Initialize ans to store the result
    
    # Implement the logic to find the number of elements in req that are greater than the corresponding elements in pre
    while i >= 0 and j >= 0:
        if req[i] > pre[j]: // If the element in req is greater than the element in pre
            ans += 1 // Increment ans
        else:
            j -= 1 // Decrement j to check the next element in pre
        i -= 1 // Decrement i in each iteration
    
    # Print the result which is the sum of ans and the remaining elements in req
    print(ans + i + 1)


