
import re

# Take the maximum sentence length as input
n = int(input())

# Initialize variables to keep track of the number of sentences and their cumulative length
ans, sumL = 1, 0

# Take a string input and split it into sentences using the regular expression [.?!]
for s in re.split("[.?!]", input()):
    # Strip leading and trailing whitespace and add a period to the end of the sentence
    s = s.strip() + '.'
    # Calculate the length of the sentence
    L = len(s)
    
    # Check if the sentence length is greater than 1
    if L > 1:
        # Check if the sentence length is greater than the maximum allowed length
        if L > n:
            # If the sentence is too long, print "Impossible" and exit
            print("Impossible")
            exit()
        
        # Check if adding the current sentence would exceed the maximum allowed length
        if sumL + L + (sumL > 0) > n:
            # If adding the sentence would exceed the maximum length, increment the sentence count
            ans += 1
            # Reset the cumulative length to the length of the current sentence
            sumL = L
        else:
            # Otherwise, add the length of the current sentence to the cumulative length
            sumL = sumL + L + (sumL > 0)

# Print the total number of sentences
print(ans)

