#include <stdio.h>

# The main function is the entry point of the program
def main():

  S = int(input()) # Read an integer value from the standard input using scanf function

  if S < 60:
    print("0:0:%d" % S)
  elif S < 3600:
    print("0:%d:%d" % (S/60, S%60))
  else:
    print("%d:%d:%d" % (S/3600, (S%3600)/60, (S%60)%60))

# Call the main function
if __name__ == "__main__":
  main()

