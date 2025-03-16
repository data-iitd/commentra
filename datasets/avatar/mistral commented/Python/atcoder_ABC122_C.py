# Importing itertools module for using accumulate function
from itertools import accumulate

# Taking input for number of strings 'n' and number of problems 'q'
n, q = map(int, input().split())

# Taking input for the string 's'
s = input()

# List comprehension to create a list 'problems' of lists containing start and end indices of each problem
problems = [list(map(int, input().split())) for _ in range(q)]

# Function definition for counting the number of 'AC' substrings in the given string 's'
# The function takes two arguments: 'total' which is the current sum of 'AC' substrings and 'i' which is the index of the current character
def count(total, i):
    # Return the sum of 'total' and 1 if the substring from index 'i-1' to 'i+1' is 'AC'
    return total + 1 if s[i-1:i+1] == 'AC' else total

# Using accumulate function to calculate the cumulative sum of 'AC' substrings in the string 's'
cumsum = list(accumulate([0] + list(range(1, n)), count))

# Iterating through each problem in the list 'problems' and printing the difference between the cumulative sum at the end and start of the problem
for l, r in problems:
    # Print the difference between the cumulative sum at the end and start of the problem
    print(cumsum[r-1] - cumsum[l-1])
