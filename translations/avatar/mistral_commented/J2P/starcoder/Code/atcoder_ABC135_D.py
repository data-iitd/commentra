
import java.io.PrintWriter; // Import the PrintWriter class for writing output to a file or stream
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner; // Import the Scanner class for reading input from the user

class Main:

 # Main method to start the program
 def main(self):
 self.run() # Call the run method of the Main class to start the execution

 # Final constant for the modulus value
 MOD = 1000000007

 # Method to run the program
 def run(self):
 sc = Scanner(System.in) # Create a new Scanner object to read input from the user
 cs = sc.next().toCharArray() # Read the input string and convert it to a character array
 dp = [[0 for i in range(13)] for j in range(len(cs))] # Create a 2D array dp of size cs.length x 13 to store the intermediate results
 base = 1 # Initialize the base variable to 1

 # Iterate through each character in the character array cs
 for i in range(len(cs)):
 if cs[len(cs) - 1 - i] == '?': # If the current character is a '?'
 for pre in range(13): # Iterate through all possible values of pre (from 0 to 12)
 for next in range(10): # Iterate through all possible values of next (from 0 to 9)
 dp[i][(base * next + pre) % 13] += # Add the contribution of the current character to the dp array
 (i > 0? dp[i - 1][pre] : # If i is not the first character, add the contribution of the previous character
 (pre == 0? 1 : 0)) # If pre is 0, add a constant value of 1
 dp[i][(base * next + pre) % 13] %= MOD # Perform modulo operation to keep the result within the range of MOD
 else: # If the current character is not a '?'
 next = cs[len(cs) - 1 - i] - '0' # Convert the digit character to an integer and subtract '0' to get the actual value
 for pre in range(13): # Iterate through all possible values of pre (from 0 to 12)
 dp[i][(base * next + pre) % 13] += # Add the contribution of the current character to the dp array
 (i > 0? dp[i - 1][pre] : # If i is not the first character, add the contribution of the previous character
 (pre == 0? 1 : 0)) # If pre is 0, add a constant value of 1
 dp[i][(base * next + pre) % 13] %= MOD # Perform modulo operation to keep the result within the range of MOD
 base = base * 10 % 13 # Multiply the base by 10 and take the result modulo 13 to update the base for the next character

 # Print the final result
 print(dp[len(dp) - 1][5])

# Method to print an object or an array in a readable format
def tr(self, *objects):
 print(objects)

if __name__ == '__main__':
 Main().main() # Call the main method of the Main class

