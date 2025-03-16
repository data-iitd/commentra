# Importing the regular expression module for splitting the input string
import re

# Taking the number of sentences n as input
n = int(input())

# Initializing the answer counter ans and the sum of lengths of sentences sumL
ans, sumL = 1, 0

# Loop to split the input string into sentences based on punctuation marks
for s in re.split("[.?!]", input()):
    # Stripping leading and trailing whitespaces from the sentence s
    s = s.strip()
    # Adding a dot at the end of the sentence if it doesn't already have one
    s += '.'

    # Calculating the length L of the sentence s
    L = len(s)

    # Checking if the length of the sentence is greater than the number of sentences n
    if L > n:
        # Printing an error message and exiting the program if the condition is true
        print("Impossible")
        exit()

    # Checking if the sum of lengths of all previous sentences and the current sentence is greater than n
    if sumL + L + (sumL > 0):
        # Incrementing the answer counter ans if the condition is true
        ans += 1
        # Updating the sum of lengths sumL with the length of the current sentence
        sumL = L
    else:
        # Updating the sum of lengths sumL with the length of the current sentence and the previous sentence's length if any
        sumL = sumL + L + (sumL > 0)

# Printing the final answer
print(ans)
