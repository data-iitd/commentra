def max(a, b):
    return a if a > b else b

while True:
    n, k = map(int, input().split())  # Read the number of elements 'n' and the size of the sequence 'k'
    if n == 0 and k == 0:
        break  # If both 'n' and 'k' are zero, break the loop

    data = [0] * 111112  # Initialize an array 'data' of size 111112 for storing the frequency of each number
    seq = [0] * 222222  # Initialize an array 'seq' of size 222222 for storing the sequence numbers

    for _ in range(k):  # Loop through each number in the sequence
        t = int(input())  # Read a number 't' from the standard input
        data[t] += 1  # Increment the frequency of the number 't' in the 'data' array

    p = 0  # Initialize a pointer 'p' to the first element of the 'seq' array
    for i in range(1, n + 1):  # Loop through each number from 1 to 'n'
        if data[i]:  # If the frequency of the number 'i' is not zero
            seq[p] += 1  # Increment the corresponding element in the 'seq' array
        else:  # If the frequency of the number 'i' is zero
            p += 2  # Move the pointer 'p' to the next even index

    p += 1  # Increment the pointer 'p' to the next index
    ret = 0  # Initialize 'ret' as the result

    if data[0]:  # If the frequency of the number 0 is not zero
        for i in range(p):  # Calculate the maximum sum of consecutive sequences in the 'seq' array
            ret = max(ret, seq[i] + seq[i + 2] + 1)  # Update the maximum sum if necessary
    else:  # If the frequency of the number 0 is zero
        for i in range(p):  # Calculate the maximum sum of sequences in the 'seq' array
            ret = max(ret, seq[i])  # Update the maximum sum if necessary

    print(ret)  # Print the maximum sum of sequences to the standard output

# <END-OF-CODE>
