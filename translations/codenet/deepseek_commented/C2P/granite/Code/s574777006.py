
n = int(input())  # Read the number of elements
x = list(map(int, input().split()))  # Read the elements of array x
q = int(input())  # Read the number of queries
y = list(map(int, input().split()))  # Read the elements of array y

sum = 0
for i in range(q):  # For each query
    for j in range(n):  # Check each element in array x
        if y[i] == x[j]:  # If the query matches an element in x
            sum += 1  # Increment the sum
            break  # Break out of the inner loop

print(sum)  # Print the sum of matches

