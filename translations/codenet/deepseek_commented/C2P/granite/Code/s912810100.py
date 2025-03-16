
# Step 1: Import the sys module to access system functions.
import sys

# Step 2: Define a function named main() to encapsulate the program logic.
def main():
  # Step 3: Prompt the user to enter two integer values and read them from the standard input.
  a = int(input("Enter the first integer: "))
  b = int(input("Enter the second integer: "))

  # Step 4: Calculate the product of a and b, and store the result in variable x.
  x = a*b

  # Step 5: Calculate the perimeter of a rectangle with sides a and b, and store the result in variable y.
  y = (a+b)*2

  # Step 6: Display the values of x and y.
  print(f"The product of {a} and {b} is {x}.")
  print(f"The perimeter of a rectangle with sides {a} and {b} is {y}.")

# Step 7: Call the main() function to execute the program logic.
if __name__ == "__main__":
  main()

# Step 8: Return 0 to indicate that the program has executed successfully.
sys.exit(0)

