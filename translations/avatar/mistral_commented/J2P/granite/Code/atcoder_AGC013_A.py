

N = int(input()) # Reading the number of elements in the array from the standard input
A = [int(input()) for _ in range(N)] # Reading the elements of the array from the standard input

count = 0 # Initializing the count variable to zero

for i in range(N - 1): # Iterating through the array to find the number of increasing and decreasing sequences
    if i == N - 1:
        count += 1 # If we have reached the last index, increment the count
    elif A[i] == A[i + 1]:
        pass # If the current and next elements are equal, do nothing
    elif A[i] < A[i + 1]:
        while A[i] <= A[i + 1]: # Finding the length of the increasing sequence
            i += 1
            if i == N - 1:
                break # If we have reached the last index, break the loop
        count += 1 # Increment the count after finding the length of the increasing sequence
    else:
        while A[i] >= A[i + 1]: # Finding the length of the decreasing sequence
            i += 1
            if i == N - 1:
                break # If we have reached the last index, break the loop
        count += 1 # Increment the count after finding the length of the decreasing sequence

print(count) # Printing the final count

