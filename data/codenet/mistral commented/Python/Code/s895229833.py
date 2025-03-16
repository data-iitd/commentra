# Input the number of elements in the list H and the elements themselves
N = int(input())
H = list(map(int, list(input().split())))

# Initialize two variables, count_best and count_tmp, to 0
count_best, count_tmp = 0, 0

# Iterate through the list H from the first index to the second last index
for i in range(N-1):
    # Check if the current height is greater than or equal to the next height
    if H[i] >= H[i+1]:
        # If yes, increment the count_tmp variable
        count_tmp += 1
    else:
        # If no, check if the current count_tmp is greater than the current best count
        if count_tmp > count_best:
            # If yes, update the count_best variable with the current count_tmp
            count_best = count_tmp
        # Reset the count_tmp variable to 0
        count_tmp = 0

# Check if the last count_tmp is greater than the current best count and update it if true
if count_tmp > count_best:
    count_best = count_tmp

# Print the value of the count_best variable
print(count_best)