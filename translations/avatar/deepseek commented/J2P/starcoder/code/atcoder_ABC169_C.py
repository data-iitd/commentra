
import java.util.ArrayList; // Importing ArrayList class from java.util package
import java.util.LinkedList; // Importing LinkedList class from java.util package
import java.util.Scanner; // Importing Scanner class from java.util package

def main():
    sc = Scanner(System.in); # Creating a Scanner object to read input from the standard input stream
    a = sc.nextLong(); # Reading a long integer 'a' from the input
    b = sc.next(); # Reading a string 'b' from the input
    
    bChar = b.toCharArray(); # Converting the string 'b' to a character array
    length = len(bChar); # Getting the length of the character array
    bStr = ""; # Initializing an empty string to store the filtered characters of 'b'
    
    # Looping through the character array 'bChar' to build the string 'bStr' without periods
    for i in range(length):
        if bChar[i]!= '.':
            bStr += bChar[i]; # Appending non-period characters to 'bStr'
    
    bInt = int(bStr); # Parsing 'bStr' as an integer
    result = (a * bInt) / 100; # Calculating the result of (a * bInt) / 100
    print(result); # Printing the result to the standard output

if __name__ == "__main__":
    main()

