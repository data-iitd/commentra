
N = int(input())  # Read the number of elements in the list A
A = [int(x) for x in input().split()]  # Read the list of integers and store them in A

# Initialize ans to the absolute value of the last element in A
ans = abs(A[-1])

# Modify the list A by adding two zeros at the beginning and end
A = [0] + A + [0]

# Initialize the list diff with zeros, having the same length as A
diff = [0 for x in range(N)]

# Loop through the elements of A from 1 to N+1 (inclusive)
for i in range(1, N+1):
    # Calculate the difference between the current element and the previous element,
    # and the difference between the current element and the next element.
    # Subtract the difference between the previous and next elements from the sum of these two differences.
    dif = abs(A[i] - A[i-1]) + abs(A[i] - A[i+1]) - abs(A[i-1] - A[i+1])
    
    # Update ans by adding the absolute difference between the current element and the previous element
    ans += abs(A[i] - A[i-1])
    
    # Store the difference between the current element and the previous element in the list diff
    diff[i-1] = dif

# Loop through the list diff and print the value of ans minus the current element in diff
for i in range(N):
    print(ans - diff[i])

