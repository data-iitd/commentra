
# Importing the Scanner class for user input
import java.util.Scanner;

# Method to generate a character array from the concatenation of numbers 1 to 1000
def generateString():
    sb = StringBuilder(); # Creating a StringBuilder to efficiently build the string
    
    # Looping through numbers 1 to 1000 and appending them to the StringBuilder
    for i in range(1, 1001):
        sb.append(i); # Appending the current number to the StringBuilder
    
    # Converting the built string to a character array and returning it
    return sb.toString().toCharArray();

if __name__ == '__main__':
    sc = Scanner(System.in); # Creating a Scanner object to read input from the user
    
    # Reading an integer input from the user
    n = sc.nextInt();
    
    # Printing the character at the (n-1)th index of the generated character array
    print(generateString()[n - 1]);
    
    sc.close(); # Closing the Scanner to prevent resource leaks

