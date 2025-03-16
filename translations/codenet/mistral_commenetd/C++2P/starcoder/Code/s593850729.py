# Start of the main function
def main():
  # Declare variables A, B, C, and X to store user input
  A = int(input())
  B = int(input())
  C = int(input())
  X = int(input())

  # Initialize counter variable cnt to 0
  cnt = 0

  # Start of the outermost for loop, iterating from 0 to A
  for a in range(A+1):
    # Start of the inner for loop, iterating from 0 to B
    for b in range(B+1):
      # Start of the innermost for loop, iterating from 0 to C
      for c in range(C+1):
        # Calculate the total value based on the current values of a, b, and c
        total = 500*a + 100*b + 50*c
        # If the total value equals X, increment the counter variable cnt
        if total == X:
          cnt += 1

  # Output the final value of the counter variable cnt to the console
  print(cnt)

# Start of the program execution
if __name__ == '__main__':
  main()

