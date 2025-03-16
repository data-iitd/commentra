
soz = input()  # Take a string input from the user
a = [0] * (len(soz) + 1)  # Initialize a list 'a' with zeros, with a length of len(soz) + 1

# Iterate over the string from index 1 to len(soz) - 1
for i in range(1, len(soz)):
    a[i] = a[i - 1]  # Set 'a[i]' to the value of 'a[i - 1]'
    if soz[i - 1] == soz[i]:  # If the characters at positions 'i - 1' and 'i' are the same
        a[i] += 1  # Increment 'a[i]' by 1

n = int(input())  # Take an integer input from the user
arr = []  # Initialize an empty list 'arr'

# Iterate 'n' times
for i in range(n):
    m, l = input().split()  # Take two inputs 'm' and 'l'
    arr.append(a[int(l) - 1] - a[int(m) - 1])  # Append the difference 'a[int(l) - 1] - a[int(m) - 1]' to 'arr'

# Print each element in 'arr'
for i in arr:
    print(i)

