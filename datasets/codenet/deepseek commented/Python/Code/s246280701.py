
n = int(input())  # Read the number of elements in the list
x = list(map(int, input().split()))  # Read the list of integers
ans = 10**10  # Initialize the answer variable to a very large number

# Iterate over a range of 101 values (from 0 to 100)
for i in range(101):
    # Calculate the squared differences between i and each element in x
    tmp = [abs(i - x[j])**2 for j in range(n)]
    # Sum these squared differences and check if it's less than the current ans
    if sum(tmp) < ans:
        ans = sum(tmp)  # Update ans with the new sum if it's smaller

print(ans)  # Print the smallest sum found


