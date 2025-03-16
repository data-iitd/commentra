# Include the standard input-output library
import sys

# Define the main function, which returns an integer
def main():
  # Declare an integer variable S
  S = int(input())

  # Check if S is less than 60
  if S < 60:
    # Print "0:0:S" if S is less than 60
    print("0:0:{}".format(S))

  # Check if S is less than 3600
  elif S < 3600:
    # Print "0:S/60:S%60" if S is less than 3600
    print("0:{}:{}".format(S // 60, S % 60))

  # If S is not less than 3600
  else:
    # Print "S/3600:S%3600/60:S%60" if S is not less than 3600
    print("{}:{}:{}".format(S // 3600, S % 3600 // 60, S % 60 % 60))

  # Return 0 to indicate successful execution
  return 0

# Execute the main function
if __name__ == "__main__":
  sys.exit(main())

