
n, k = map(int, input().split())  # Read the number of elements and the size of the subarray from the user and store them in the variables n and k
l = list(map(int, input().split()))  # Read the elements of the vector l from the user and store them in a list
l.sort(reverse=True)  # Sort the list l in descending order
ans = sum(l[:k])  # Calculate the sum of the first k elements in the list l and store it in the variable ans
print(ans)  # Output the value of the variable ans to the console

