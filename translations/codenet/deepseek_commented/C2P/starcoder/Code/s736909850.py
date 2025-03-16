# Step 1: Include the standard input/output library to use printf and scanf functions.
import sys

# Step 2: Define the main function which is the entry point of the program.
def main():
   sheep = 0  # Step 3: Declare two integer variables, sheep and wolf, to store the number of sheep and wolves.
   wolf = 0

   sheep, wolf = map(int, sys.stdin.readline().split())  # Step 4: Use the scanf function to read the number of sheep and wolves from the user.

   if(wolf>=sheep):  # Step 5: Check if the number of wolves is greater than or equal to the number of sheep.
      print("unsafe")  # Step 6: If the condition is true, print "unsafe".
   else:
      print("safe")  # Step 7: Otherwise, print "safe".

# Step 8: Return 0 to indicate successful execution of the program.
if __name__ == "__main__":
   main()

