
n = int(input())  # Take an integer input `n` which represents the number of elements to be inputted.
res = []  # Initialize an empty list `res` to store the inputs.
for i in range(n):  # Loop `n` times to take `n` inputs.
    a = input()  # Take an input `a` in each iteration.
    res.append(a)  # Append the input `a` to the list `res`.
print(len(set(res)))  # Print the length of the set of `res`, which gives the number of unique elements.

