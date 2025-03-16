
import sys  # Import the standard input-output library

def main():  # Define the main function, which does not return anything
  S = int(input())  # Read an integer input from the user and store it in S

  # Check if S is less than 60
  if S < 60:
    print("0:0:%d" % S)  # Print "0:0:S" if S is less than 60

  # Check if S is less than 3600
  elif S < 3600:
    print("0:%d:%d" % (S // 60, S % 60))  # Print "0:S/60:S%60" if S is less than 3600

  # If S is not less than 3600
  else:
    print("%d:%d:%d" % (S // 3600, (S % 3600) // 60, (S % 60) % 60))  # Print "S/3600:S%3600/60:S%60" if S is not less than 3600

if __name__ == "__main__":  # Call the main function if the script is executed directly
  main()

