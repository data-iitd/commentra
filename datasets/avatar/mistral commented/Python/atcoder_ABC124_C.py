# Import the collections module and specifically the Counter class
import collections

# Initialize an empty list 's' by taking input from the user
s = list(input())

# Create two dictionaries 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the list 's' respectively
even = collections.Counter(s[:len(s)//2])
odd = collections.Counter(s[len(s)//2:])

# Print the minimum difference between the length of the list 's' and the sum of the frequencies of '0' and '1' in either half of the list
print(min(len(s) - (even["0"] + odd["1"]), len(s) - (even["1"] + odd["0"])))
