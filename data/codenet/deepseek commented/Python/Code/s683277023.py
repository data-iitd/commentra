
n,k = map(int,input().split())  # Read two integers n and k from input
li = list(map(int,input().split()))  # Read a list of integers and store it in li
li.sort()  # Sort the list li in ascending order
tmp = li[:k]  # Create a temporary list tmp containing the first k elements of the sorted list li
print(sum(tmp))  # Print the sum of the elements in the temporary list tmp

