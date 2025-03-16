
# Include standard input/output library
# Include string manipulation library

# Start of the main function
def main():
  n = int(input()) # Read an integer 'n' from the standard input

  while n > 0: # Start of the while loop that processes each string
    s = input() # Read a string of maximum length 1000 from the standard input into the character array's'

    while "Hoshino" in s: # Start of the inner while loop that replaces the substring "Hoshino" with "aana"
      s = s.replace("Hoshino","aana")

    print(s) # Print the modified string to the standard output

    n = n - 1 # Decrement the value of 'n' by 1

# End of the main function

# 