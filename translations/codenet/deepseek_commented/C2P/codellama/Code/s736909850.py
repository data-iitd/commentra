#include<stdio.h>  # Step 1: Include the standard input/output library to use printf and scanf functions.

def main():  # Step 2: Define the main function which is the entry point of the program.
   sheep = 0  # Step 3: Declare two integer variables, sheep and wolf, to store the number of sheep and wolves.
   wolf = 0

   scanf("%d %d",&sheep,&wolf)  # Step 4: Use the scanf function to read the number of sheep and wolves from the user.

   if(wolf>=sheep):  # Step 5: Check if the number of wolves is greater than or equal to the number of sheep.
      printf("unsafe\n")  # Step 6: If the condition is true, print "unsafe".
   else:
      printf("safe\n")  # Step 7: Otherwise, print "safe".

   return 0  # Step 8: Return 0 to indicate successful execution of the program.

