
n = int(input()) # Reading the number of elements in the array
array = [int(input()) for _ in range(n)] # Reading the array elements from the user input

odd = 0
even = 0
odd_ind = 0
even_ind = 0

# Counting the number of odd and even numbers and recording their indices
for i in range(n):
    if array[i] % 2 == 0:
        even += 1
        even_ind = i + 1
    else:
        odd += 1
        odd_ind = i + 1

# Comparing the counts of odd and even numbers and printing the index of the majority
if odd > even:
    print(even_ind)
else:
    print(odd_ind)

