
#include<stdio.h>  # Step 1: Include the standard input/output library to use printf and scanf functions.

def main():  # Step 2: Define the main function which is the entry point of the program.
   sheep = int(input())  # Step 3: Declare two integer variables, sheep and wolf, to store the number of sheep and wolves.
   wolf = int(input())

   if(wolf>=sheep):  # Step 4: Use the scanf function to read the number of sheep and wolves from the user.
      print("unsafe")  # Step 5: Check if the number of wolves is greater than or equal to the number of sheep.
   else:
      print("safe")  # Step 6: If the condition is true, print "unsafe".
   return 0  # Step 7: Otherwise, print "safe".

main()  # Step 8: Return 0 to indicate successful execution of the program.

