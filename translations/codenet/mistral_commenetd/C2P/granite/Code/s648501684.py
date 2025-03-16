

n, k, q = map(int, input().split()) # Read the input values n, k, and q from the user using the map function and split the input string by spaces

arr = [0] * (n + 1) # Initialize the array arr with zeros using list comprehension

for _ in range(q): # Read q query values from the user and increment the corresponding index in the array arr
    temp = int(input())
    arr[temp] += 1

for i in range(1, n + 1): # Check each index i in the array arr and print "Yes" if the count is greater than q-k, otherwise print "No"
    if arr[i] > (q - k):
        print("Yes")
    else:
        print("No")

