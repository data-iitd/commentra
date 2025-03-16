
# The main function is the entry point of the program
def main():

  S = int(input()) # Read an integer value from the standard input using input function and convert it to an integer

  # Check if the value of S is less than 60
  if S < 60:
    # If the condition is true, print the time in the format "0:0:S"
    print("0:0:%d" % S)
  # Else if the value of S is less than 3600 (1 hour)
  elif S < 3600:
    # Calculate the number of hours by dividing the value of S by 60
    # Print the time in the format "0:M:S"
    print("0:%d:%d" % (S//60, S%60))
  # Else if the value of S is greater than or equal to 3600
  else:
    # Calculate the number of hours by dividing the value of S by 3600
    # Calculate the number of minutes by finding the remainder of S when divided by 60
    # Calculate the number of seconds by finding the remainder of the remainder when divided by 60
    # Print the time in the format "H:M:S"
    print("%d:%d:%d" % (S//3600, (S%3600)//60, (S%60)%60))

# Call the main function to execute the program
main()

