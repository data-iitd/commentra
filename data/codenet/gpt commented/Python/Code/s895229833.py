# Read the number of elements
N = int(input())

# Read the heights into a list from user input
H = list(map(int, list(input().split())))

# Initialize counters for the longest non-increasing sequence
count_best, count_tmp = 0, 0

# Iterate through the list of heights
for i in range(N-1):
    # Check if the current height is greater than or equal to the next height
    if H[i] >= H[i+1]:
        # Increment the temporary count for the current non-increasing sequence
        count_tmp += 1
    else:
        # If the current sequence ends, check if it's the longest found so far
        if count_tmp > count_best:
            count_best = count_tmp
        
        # Reset the temporary count for the next sequence
        count_tmp = 0

# After the loop, check again in case the longest sequence ends at the last element
if count_tmp > count_best:
    count_best = count_tmp

# Output the length of the longest non-increasing sequence
print(count_best)
