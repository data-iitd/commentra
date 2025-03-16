N = int(input())  # Read the number of elements N from user input
A = list(map(int, input().split()))  # Read a list A of N integers from user input
B = [0] * N  # Initialize an empty list B of size N

for i in range(N - 1, -1, -1):  # Iterate through the list B in reverse order, starting from the last index (N-1) and going backwards to the first index (-1)
    tmp_sum = 0  # Initialize a variable tmp_sum to 0
    for j in range((i + 1) * 2 - 1, N, i + 1):  # Iterate through the indices j of the list B, starting from j = (i + 1) * 2 - 1 and going up by steps of i + 1 until we reach the end of the list B
        tmp_sum += B[j]  # Add the value of B[j] to tmp_sum
        tmp_sum %= 2  # Take the modulo 2 of tmp_sum
    B[i] = tmp_sum ^ A[i]  # Assign the XOR of the current element A[i] and the final value of tmp_sum to the current index i of list B

print(sum(B))  # Print the sum of all the elements in list B
print(*[i + 1 for i, b in enumerate(B) if b == 1])  # Print the indices of all the elements in list B that have the value 1