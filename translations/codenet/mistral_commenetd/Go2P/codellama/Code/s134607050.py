
# Function to search the range of 'R' and 'L' in the given text
# S....M....E
# R...RL...LR
def searchRange(text, start, limit):
    middle = -1 # Initialize middle to -1

    for i in range(start, limit):
        if text[i] != 'R': # Check if current character is not 'R'
            middle = i # If not, then set middle to current index
            break # and break the loop

    end = limit # Initialize end to limit

    for i in range(middle, limit):
        if text[i] != 'L': # Check if current character is not 'L'
            end = i # If not, then set end to current index
            break # and break the loop

    return start, middle, end # Return start, middle and end indices

# Function to print the answer
def answer():
    text = input() # Read text from standard input
    limit = len(text) # Get length of text

    start = 0 # Initialize start index to 0
    middle = 0 # Initialize middle index to 0
    end = 0 # Initialize end index to 0
    firstPrinted = False # Initialize firstPrinted to false

    while end < limit: # Loop until end is less than limit
        start, middle, end = searchRange(text, start, limit) # Call searchRange function to find the range of 'R' and 'L'

        len1 = middle - start # Calculate length of first substring
        len2 = end - middle # Calculate length of second substring

        # Print the first substring
        for i in range(start, middle-1):
            if firstPrinted: # Check if firstPrinted is true
                print(" ", end="") # Print a space if true
            print("0", end="") # Print '0' for each character in the first substring
            firstPrinted = True # Set firstPrinted to true

        # Print the count of 'R' and 'L' in the first and second substrings
        if firstPrinted: # Check if firstPrinted is true
            print(" ", end="") # Print a space if true
        print(f"{len1//2+len2//2} {len1//2+(len2+1)//2}", end="") # Print the count of 'R' and 'L' in the first and second substrings
        firstPrinted = True # Set firstPrinted to true

        # Print the second substring
        for i in range(middle + 1, end):
            if firstPrinted: # Check if firstPrinted is true
                print(" ", end="") # Print a space if true
            print("0", end="") # Print '0' for each character in the second substring
            firstPrinted = True # Set firstPrinted to true
        start = end # Set start to end
        firstPrinted = True # Set firstPrinted to true
    print() # Print newline at the end

# Main function to call answer function
def main():
    answer() # Call answer function



