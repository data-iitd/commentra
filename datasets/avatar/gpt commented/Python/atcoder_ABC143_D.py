from bisect import bisect_right, bisect_left

# Read input values: first value is n, followed by n integers
n, *l = map(int, open(0).read().split())

# Sort the list of integers
l.sort()

# Initialize the answer variable to count valid triplets
ans = 0

# Iterate through each pair of elements in the sorted list
for i in range(n):
    for j in range(i + 1, n):
        a = l[i]  # First element of the pair
        b = l[j]  # Second element of the pair
        
        # Find the index where a + b would fit in the sorted list
        right = bisect_left(l, a + b)
        
        # Find the index where max(a - b, b - a) would fit in the sorted list
        left = bisect_right(l, max(a - b, b - a))
        
        # Calculate the number of valid third elements that can form a triplet
        tmp = max(0, right - left)
        
        # Adjust the count if the indices i or j are within the range of valid third elements
        if left <= i < right:
            tmp -= 1  # Exclude the first element if it's counted
        if left <= j < right:
            tmp -= 1  # Exclude the second element if it's counted
        
        # Add the number of valid triplets formed with the current pair (i, j)
        ans += tmp

# Since each triplet is counted three times, divide the final answer by 3
print(ans // 3)
