# We include the standard input/output library
import sys

# The main function is the entry point of the program
def main():
  n = int(sys.stdin.readline()) # We read the first number 'n' from the standard input
  c = 0 # We initialize the variable 'c' to zero
  m = 100000000 # We initialize'm' to a very large negative number
  M =-100000000 # We initialize 'M' to a very large positive number

  for i in range(1,n+1): # We start a for loop that iterates 'n' times
    a = int(sys.stdin.readline()) # We read the current number 'a' from the standard input

    # If the current number 'a' is greater than the current maximum number 'M', we update 'M' with 'a'
    if(a>M):
      M = a

    # If the current number 'a' is smaller than the current minimum number'm', we update'm' with 'a'
    if(a < m):
      m = a

    # We add the current number 'a' to the variable 'c'
    c = c+a

  # We print the minimum number'm', the maximum number 'M', and the sum 'c' to the standard output
  print(m,M,c)

# The main function is the entry point of the program
if __name__ == "__main__":
  main()

