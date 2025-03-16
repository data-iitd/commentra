N = int(input())  # Step 1: Read the number of elements N
H = list(map(int, list(input().split())))  # Step 1: Read the list of heights H

count_best, count_tmp = 0, 0  # Step 2: Initialize counters

for i in range(N-1):  # Step 3: Iterate through the list
    if H[i] >= H[i+1]:  # Step 4: Compare each element with the next one
        count_tmp += 1  # Increment the current sequence counter
    else:
        if count_tmp > count_best:  # Step 5: Compare and update best sequence length
            count_best = count_tmp
        count_tmp = 0  # Reset the current sequence counter

if count_tmp > count_best:  # Step 6: Check the last sequence
    count_best = count_tmp

print(count_best)  # Step 7: Print the result
