
# Start of the main function
def main():
  B = input() # Read a character from the standard input stream and store it in variable B

  # Logic block to determine the output character based on the input character
  if(B == 'A'): # If the input character is 'A'
    OUT = 'T' # Set the output character to 'T'
  elif(B == 'T'): # If the input character is 'T'
    OUT = 'A' # Set the output character to 'A'
  elif(B == 'C'): # If the input character is 'C'
    OUT = 'G' # Set the output character to 'G'
  else: # If the input character is neither 'A', 'T', nor 'C'
    OUT = B # Set the output character to the input character itself

  print(OUT) # Output the result character to the standard output stream

# End of the main function

# Start of the program
if __name__ == "__main__":
  main() # Call the main function

# End of the program
