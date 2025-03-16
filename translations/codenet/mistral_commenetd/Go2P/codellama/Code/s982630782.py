
# Initialize an empty dictionary to store the frequency of each number
m = {}

# Read the number of test cases N
N = int(input())
# Read the N integers and store their frequencies in the dictionary
for i in range(N):
    num = int(input())
    m[num] = m.get(num, 0) + 1

# Read the number of queries M
M = int(input())
# For each query, read the number B and the index C, and update the frequency of the number at index C in the dictionary
for i in range(M):
    B, C = map(int, input().split())
    m[C] = m.get(C, 0) + B

# Create a list of integers from the dictionary keys
ints = list(m.keys())

# Sort the list in descending order
ints.sort(reverse=True)

# Initialize variables for calculating the sum
rest = N
sum = 0
# Iterate through the sorted list of integers
for i in ints:
    num = m[i]
    # If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
    if num >= rest:
        sum += rest * i
        break
    # Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
    sum += num * i
    rest -= num

# Print the result
print(sum)

