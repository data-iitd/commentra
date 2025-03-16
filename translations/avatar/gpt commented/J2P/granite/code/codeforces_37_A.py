
import sys

# Read the number of integers to be processed
n = int(input())

# Initialize a dictionary to store the frequency of each integer
freq = {}

# Loop through the input integers and populate the frequency dictionary
for _ in range(n):
    val = int(input())
    # Update the count of the integer in the dictionary
    freq[val] = freq.get(val, 0) + 1

# Initialize a variable to track the maximum frequency found
max_freq = float('-inf')

# Iterate through the entries in the frequency dictionary to find the maximum frequency
for key, value in freq.items():
    # Update max_freq if the current frequency is greater than the current max
    max_freq = max(max_freq, value)

# Print the maximum frequency and the number of unique integers
print(str(max_freq) +'' + str(len(freq)))

