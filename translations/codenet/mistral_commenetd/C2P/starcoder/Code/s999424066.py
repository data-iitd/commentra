# Include the standard input/output library
import sys

# Start of the main function
def main():
  # Declare variables a, b, c, x, and y as integers
  a = int(sys.stdin.readline())
  b = int(sys.stdin.readline())
  c = int(sys.stdin.readline())
  x = int(sys.stdin.readline())
  y = int(sys.stdin.readline())

  # Multiply the value of variable c by 2
  c *= 2

  # Check if the sum of variables a and b is less than or equal to the value of variable c
  if a+b <= c:
    # If the condition is true, print the result of multiplying variables a and x, and variables b and y, and then print a newline character
    print(a*x+b*y)

  # If the condition in the if statement is false, execute the code in the else block
  else:
    # Check if the value of variable x is less than or equal to the value of variable y
    if x <= y:
      # Check if the value of variable b is less than or equal to the value of variable c
      if b <= c:
        # If both conditions in the nested if statement are true, print the result of multiplying variable c by x, and then subtract the value of x from y and multiply the result by b, and finally print a newline character
        print(c*x+(y-x)*b)

      # If the first condition in the nested if statement is false, execute the code in this else block
      else:
        # Print the result of multiplying variable c by the value of variable y, and then print a newline character
        print(c*y)

    # If the condition in the outer if statement is false and the condition in the if statement that checks if x is less than or equal to y is also false, execute the code in this else block
    else:
      # Check if the value of variable a is less than or equal to the value of variable c
      if a <= c:
        # If the condition is true, print the result of multiplying variable c by the value of y, subtract the value of y from x, and then multiply the result by a, and finally print a newline character
        print(c*y+(x-y)*a)

      # If the condition in the if statement that checks if a is less than or equal to c is false, execute the code in this else block
      else:
        # Print the result of multiplying variable c by the value of variable x, and then print a newline character
        print(c*x)

# Call the main function
if __name__ == "__main__":
  main()

# 