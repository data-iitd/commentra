def main():
    # Step 1: Read the number of elements N from the standard input
    N = int(input())
    
    # Step 2: Read N integers from the standard input and add them to the list L
    L = list(map(int, input().split()))
    
    # Step 3: Sort the list L in ascending order
    L.sort()
    
    # Step 4: Initialize a counter to zero
    count = 0
    
    # Step 5: Use two nested loops to iterate through the list L, selecting pairs of elements (a, b) where a < b
    for i in range(N):
        for j in range(i + 1, N):
            a = L[i]
            b = L[j]
            
            # Step 6: For each pair (a, b), call the find method to determine the number of elements in the list L
            # that are greater than a + b and are located after the index j+1
            res = find(L, j + 1, a + b)
            
            # Step 7: Add the result of the find method to the counter count
            count += res
    
    # Step 8: After all pairs have been processed, print the value of count
    print(count)

# Step 9: The find method uses a binary search algorithm to efficiently find the number of elements in the list L
# that are greater than a + b and are located after the index from
def find(li, from_index, target):
    low = from_index
    upp = len(li) - 1
    mid = (upp - low + 1) // 2 + (low + upp) // 2
    
    if upp - low < 0:
        return 0
    elif li[from_index] >= target:
        return 0
    elif li[upp] < target:
        return upp - low + 1
    
    while upp - low > 1:
        if li[mid] >= target:
            upp = mid
        else:
            low = mid
        mid = (upp - low + 1) // 2 + (low + upp) // 2
    
    return low - from_index + 1

# Call the main function
main()
