# Read two integers n and k from input
n, k = map(int, input().split())

# Read the string s from input
s = input()

# Initialize a list to count occurrences of each letter (A-Z)
count = [0] * 26

# Count the occurrences of each character in the string
for c in s:
    count[ord(c) - ord("A")] += 1

# Sort the count list in descending order to prioritize higher counts
count.sort(reverse=True)

# Initialize the result variable to accumulate the final score
res = 0

# Iterate through the sorted count list
for i in range(26):
    # If the current count is greater than or equal to k
    if count[i] >= k:
        # Add k squared to the result and print it
        res += k * k
        print(res)
        exit()  # Exit the program since we have found the result

    # Decrease k by the current count
    k -= count[i]
    
    # Add the square of the current count to the result
    res += count[i] ** 2

# Print the final result after processing all counts
print(res)
