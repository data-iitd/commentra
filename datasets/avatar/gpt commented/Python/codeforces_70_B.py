import re  # Import the regular expression module

# Read an integer input which represents the maximum allowed length for sentences
n = int(input())

# Initialize the answer counter and the sum of lengths of sentences
ans, sumL = 1, 0

# Split the input text into sentences based on punctuation marks (., ?, !)
for s in re.split("[.?!]", input()):
    s = s.strip() + '.'  # Strip whitespace and add a period to the end of the sentence
    L = len(s)  # Calculate the length of the current sentence

    # Check if the length of the sentence is greater than 1 (to avoid empty sentences)
    if L > 1:
        # If the length of the sentence exceeds the maximum allowed length, print "Impossible" and exit
        if L > n:
            print("Impossible")
            exit()

        # Check if adding the current sentence length to the sum exceeds the maximum allowed length
        if sumL + L + (sumL > 0) > n:
            ans += 1  # Increment the answer counter for a new line
            sumL = L  # Reset the sum of lengths to the current sentence length
        else:
            # Update the sum of lengths by adding the current sentence length
            sumL = sumL + L + (sumL > 0)  # Add 1 if there was a previous sentence (to account for space)

# Print the total number of lines needed
print(ans)
