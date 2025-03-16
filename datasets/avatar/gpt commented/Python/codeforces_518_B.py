# Read two strings from input
s, t = input(), input()

# Initialize dictionaries to store frequency counts of characters in both strings
freqs = dict()
freqt = dict()

# Initialize counters for matching characters
yay, whoops = 0, 0

# Count the frequency of each character in the first string 's'
for letra in s:
    if letra in freqs:
        freqs[letra] += 1  # Increment count if character already exists
    else:
        freqs[letra] = 1    # Initialize count if character is new

# Count the frequency of each character in the second string 't'
for letra in t:
    if letra in freqt:
        freqt[letra] += 1  # Increment count if character already exists
    else:
        freqt[letra] = 1    # Initialize count if character is new

# Compare character frequencies from both strings to count exact matches
for letra in freqs.keys():
    while (freqs[letra] > 0 and letra in freqt and freqt[letra] > 0):
        yay += 1  # Increment the count of exact matches
        freqs[letra] -= 1  # Decrease the count in the first string
        freqt[letra] -= 1  # Decrease the count in the second string

# Compare remaining characters for case-insensitive matches
for letra in freqs.keys():
    while (freqs[letra] > 0):
        # Check for a lowercase letter in 's' and its uppercase counterpart in 't'
        if letra.islower() and letra.upper() in freqt.keys() and freqt[letra.upper()] > 0:
            whoops += 1  # Increment the count of case-insensitive matches
            freqs[letra] -= 1  # Decrease the count in the first string
            freqt[letra.upper()] -= 1  # Decrease the count in the second string
        # Check for an uppercase letter in 's' and its lowercase counterpart in 't'
        elif letra.isupper() and letra.lower() in freqt.keys() and freqt[letra.lower()] > 0:
            whoops += 1  # Increment the count of case-insensitive matches
            freqs[letra] -= 1  # Decrease the count in the first string
            freqt[letra.lower()] -= 1  # Decrease the count in the second string
        else:
            break  # Exit the loop if no more matches can be found

# Print the results: number of exact matches and case-insensitive matches
print(yay, whoops)
