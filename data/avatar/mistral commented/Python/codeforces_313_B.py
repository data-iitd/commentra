# Take input string 'soz' from the user
soz = input()

# Initialize an array 'a' of size 'len(soz)+1' with zeros
a = [0] * (len(soz) + 1)

# Iterate through the string 'soz' starting from index 1
for i in range(1, len(soz)):
    # Assign the value of the previous index to the current index
    a[i] = a[i - 1]
    
    # If the current character is same as the previous character, increment the count
    if soz[i - 1] == soz[i]:
        a[i] += 1

# Take the number of test cases 'n' as input
n = int(input())

# Initialize an empty list 'arr' to store the differences
arr = []

# Iterate through the test cases
for i in range(n):
    # Take two integers 'm' and 'l' as input, separated by a space
    m, l = input().split()
    
    # Calculate the difference between the count at index 'l' and index 'm'
    arr.append(a[int(l) - 1] - a[int(m) - 1])

# Iterate through the list 'arr' and print each difference
for i in arr:
    print(i)
