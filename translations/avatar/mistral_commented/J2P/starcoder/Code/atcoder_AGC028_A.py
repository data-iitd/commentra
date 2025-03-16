#######
# Import necessary libraries
#######
import math
import sys

# Initialize a Scanner object for reading input
scanner = sys.stdin

# Main method to start the program
def main():
  # Read input values for n and m
  n = int(scanner.readline())
  m = int(scanner.readline())

  # Calculate the greatest common divisor (GCD) of n and m
  gcd = math.gcd(n, m)

  # Read input strings s and t
  s = scanner.readline()
  t = scanner.readline()

  # Perform the required calculation and print the result
  result = next((k for k in range(gcd) if s[k * n // gcd]!= t[k * m // gcd]), -1)
  if result == -1:
    result = n * m // gcd
  print(result)

# Start the program
if __name__ == "__main__":
  main()

